#include <stdio.h>
#include <highgui/highgui.hpp>
#include <core/core.hpp>
#include <imgproc/imgproc.hpp>
#include <vector>

int vib_upper = 255;
int vib_lower = 50;//50 71%
int hue_upper = 130;//120;
int hue_lower = 90;//109;
int sat_upper = 255;
int sat_lower = 10;

//Seems to have little effect on test data 0 = 0.61 precison, 55 = 0.68, 250 = 0.61 
int spiralThresh = 250;//250 71%

int main(int argc, char** argv) {
	char* imageName = argv[1];

	cv::Mat image, imageHSV;
	image = cv::imread( imageName, CV_LOAD_IMAGE_COLOR );
	cvtColor(image, imageHSV, CV_BGR2HSV);

	std::vector<cv::Mat> v_channel;
	split(imageHSV, v_channel);

	int pix = 0;

	for (int i = 0; i<imageHSV.rows; i++) {
		for (int j = 0; j<imageHSV.cols; j++) {
			int hue = (int) v_channel[0].at<uchar>(i, j);
			int sat = (int) v_channel[1].at<uchar>(i, j);
			int vib = (int) v_channel[2].at<uchar>(i, j);

			if ( 
				hue > hue_lower && hue < hue_upper && 
				sat > sat_lower && sat < sat_upper && 
				vib > vib_lower && vib < vib_upper
				) 
			{
				pix++;
			}
		}
	}
	if (pix > spiralThresh) {
		printf("spiral\n");
	} else {
		printf("ellipse\n");
	}
}

#include <stdio.h>
#include <highgui/highgui.hpp>
#include <core/core.hpp>
#include <imgproc/imgproc.hpp>
#include <vector>

int main(int argc, char** argv) {
	char* imageName = argv[1];

	cv::Mat image, imageHSV;
	image = cv::imread( imageName, CV_LOAD_IMAGE_COLOR );
	cvtColor(image, imageHSV, CV_BGR2HSV);

	std::vector<cv::Mat> v_channel;
	split(imageHSV, v_channel);

	int bluePix = 0;

	for (int i = 0; i<imageHSV.rows; i++) {
		for (int j = 0; j<imageHSV.cols; j++) {
			int hue = (int) v_channel[0].at<uchar>(i, j);
			if (hue > 219/2 && hue < 240/2) bluePix++;
		}
	}
	if (bluePix > 1900) {
		printf("spiral\n");
	} else {
		printf("ellipse\n");
	}
}

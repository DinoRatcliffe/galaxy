#include "GalaxyCategoriser.h"
#include <vector>
#include <imgproc/imgproc.hpp>

GalaxyCategoriser::GalaxyCategoriser() {
	vib_upper	= 255;
	vib_lower	= 50;
	sat_upper	= 255;
	sat_lower	= 10;
	hue_upper	= 130;
	hue_lower	= 90;

	thresh		= 250;
}

GalaxyCategoriser::GalaxyType GalaxyCategoriser::categoriseGalaxy(cv::Mat image) {
	cv::Mat imageHsv;
	cvtColor(image, imageHsv, CV_BGR2HSV);
	
	int pixels = countPixels(imageHsv);
	return pixels > thresh ? SPIRAL : ELLIPSE;
}

int GalaxyCategoriser::countPixels(cv::Mat image) {
	std::vector<cv::Mat> hsvChannels;
	split(image, hsvChannels);

	int numPix = 0;
	for (int i = 0; i < image.rows; i++) {
		for (int j = 0; j < image.cols; j++) {
			int hue = (int) hsvChannels[0].at<uchar>(i, j);
			int sat = (int) hsvChannels[1].at<uchar>(i, j);
			int vib = (int) hsvChannels[2].at<uchar>(i, j);

			if (	hue > hue_lower && hue < hue_upper &&
				sat > sat_lower && sat < sat_upper &&
				vib > vib_lower && vib < vib_upper
			) {
				numPix++;
			}
		}	
	}	

	return numPix;
}

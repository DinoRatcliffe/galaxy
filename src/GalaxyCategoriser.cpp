#include "GalaxyCategoriser.h"
#include <vector>
#include <imgproc/imgproc.hpp>

GalaxyCategoriser::GalaxyCategoriser() {
	//initialise defaults
	vib_upper	= 255;
	vib_lower	= 50;
	sat_upper	= 255;
	sat_lower	= 10;
	hue_upper	= 130;
	hue_lower	= 90;

	thresh		= 750;
}

GalaxyCategoriser::GalaxyType GalaxyCategoriser::categoriseGalaxy(cv::Mat image) {
	//convert image
	cv::Mat imageHsv;
	cvtColor(image, imageHsv, CV_BGR2HSV);
	
	//blur image
	cv::Mat bluredImage;
	cv::Size ksize;
	ksize.width = 5;
	ksize.height = 5;
	blur(imageHsv, bluredImage, ksize);

	//count blue pixels
	int pixels = countPixels(bluredImage);
	return pixels > thresh ? SPIRAL : ELLIPSE;
}

int GalaxyCategoriser::countPixels(cv::Mat image) {
	//split channels
	std::vector<cv::Mat> hsvChannels;
	split(image, hsvChannels);

	//count pixels
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

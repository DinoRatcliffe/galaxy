#include <stdio.h>
#include <core/core.hpp>
#include <highgui/highgui.hpp>
#include "GalaxyCategoriser.h"

int main(int argc, char** argv) {
	char* imageName = argv[1];

	cv::Mat image, imageHSV;
	image = cv::imread( imageName, CV_LOAD_IMAGE_COLOR );

	GalaxyCategoriser cat;
	if (cat.categoriseGalaxy(image) == GalaxyCategoriser::SPIRAL) {
		printf("spiral\n");
	} else {
		printf("ellipse\n");
	}
}

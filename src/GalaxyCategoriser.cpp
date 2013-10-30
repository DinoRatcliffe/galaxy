#include "GalaxyCategoriser.h"

GalaxyCategoriser::GalaxyCategoriser() {

}

GalaxyCategoriser::GalaxyType GalaxyCategoriser::categoriseGalaxy(cv::Mat image) {
	return SPIRAL;
}

int GalaxyCategoriser::countPixels(cv::Mat image) {
	return -1;
}

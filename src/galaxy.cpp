/////////////////////////////////////////////////////////////////////
/// \brief 	Output predicted type of galaxy (spiral or ellipse)
/// 
/// \details 	This program takes the path to an image file as an
///		argument. It then determines the type of galaxy in
///		the file using a GalaxyCatagoriser Object. It then
///		prints the type to stdout.
///
///		| Type    | Output   |
///		| :-----: | :------- |
///		| Spiral  | spiral   |
///		| Ellipse | ellipse  |
///
/// \warning	This program does not determine if the image 
///		contains a galaxy so it will always output spiral
///		or ellipse
///
/// \author Dino Ratcliffe
/// \date 2013
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <core/core.hpp>
#include <highgui/highgui.hpp>
#include "GalaxyCategoriser.h"

////////////////////////////////////////////////////////////////////
// Main
////////////////////////////////////////////////////////////////////
int main(int argc, char** argv) {

	//grab image
	char* imageName = argv[1];
	cv::Mat image, imageHSV;
	image = cv::imread( imageName, CV_LOAD_IMAGE_COLOR );

	//get and print type
	GalaxyCategoriser cat;
	if (cat.categoriseGalaxy(image) == GalaxyCategoriser::SPIRAL) {
		printf("spiral\n");
	} else {
		printf("ellipse\n");
	}
}

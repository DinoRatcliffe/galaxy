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
/// \author 1101399
/// \date 2013
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <core/core.hpp>
#include <highgui/highgui.hpp>
#include "GalaxyCategoriser.h"
#include <unistd.h>

////////////////////////////////////////////////////////////////////
// Option handling
////////////////////////////////////////////////////////////////////
void printUsage(char* program) {
	printf("usage: %s [ -h ] image\n", program);

}

int handleOptions(int argc, char** argv) {
	bool needUsage = false;
	//handle flags
	int c;
	while ((c = getopt(argc, argv, "h")) != -1){
		switch (c) {
			case 'h':
				needUsage = true;
			       	break;	
			case '?':
				 if (isprint (optopt)) fprintf (stderr, "Unknown option `-%c'.\n", optopt);
				 else fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
				 needUsage = true;
				 break;
		}
	}
	
	//make sure there is a non flag argument
	if ((argc - optind) == 0) {
	       	printf("Requires image argument\n");
		needUsage = true;
	}

	if (needUsage) {
		printUsage(argv[0]);
		exit(EXIT_FAILURE);
	}

	return optind;
}

////////////////////////////////////////////////////////////////////
// Main
////////////////////////////////////////////////////////////////////
int main(int argc, char** argv) {

	int index = handleOptions(argc, argv);	

	//grab image
	char* imageName = argv[index];
	cv::Mat image, imageHSV;
	image = cv::imread( imageName, CV_LOAD_IMAGE_COLOR );

	if (! image.data) { 
		printf("Error - Cannot open image \"%s\"\n", argv[index]);
		exit(EXIT_FAILURE);
	}
	
	//get and print type
	GalaxyCategoriser cat;
	if (cat.categoriseGalaxy(image) == GalaxyCategoriser::SPIRAL) {
		printf("spiral\n");
	} else {
		printf("ellipse\n");
	}
}

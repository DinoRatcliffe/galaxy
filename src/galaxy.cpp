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
//
//	TESTS
//	>>> galaxy -h
//	usage: galaxy [ -h ] image
//
//	>>> galaxy
//	Requires Image argument
//	usage: galaxy [ -h ] image
//
//	>>> galaxy -help
//	usage: galaxy [ -h ] image
//
//	>>> galaxy -p
//	galaxy: invalid option -- 'p'
//	usage: galaxy [ -h ] image
//
//	>>> galaxy --help
//	galaxy: invalid option -- '-'
//	usage: galaxy [ -h ] image
//
//	>>> galaxy A_NON_IMAGE_FILE
//	Error - Cannot open image "A_NON_IMAGE_FILE"
//
//	THIS TEST REQUIRES LEGITEMATE IMAGE FILES AS FOUND IN test
//	>>> galaxy gz-0668.jpg
//	spiral
//
//	>>> galaxy gz-0001.jpg
//	ellipse
//
//	>>> galaxy -h gz-0668.jpg
//	usage: galaxy [ -h ] image
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

void exitWithUsage(char* program) {
	printUsage(program);
	exit(EXIT_FAILURE);
}

int handleOptions(int argc, char** argv) {
	bool needUsage = false;
	//handle flags
	int c;
	while ((c = getopt(argc, argv, "h")) != -1){
		switch (c) {
			case 'h':
				exitWithUsage(argv[0]);
			       	break;
			case '?':
				exitWithUsage(argv[0]);
				break;	
		}
	}
	
	//make sure there is a non flag argument
	if ((argc - optind) == 0) {
		printf("Requires Image argument\n");
		exitWithUsage(argv[0]);
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

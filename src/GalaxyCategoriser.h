#ifndef _GALAXYCATEGORISER_H_
#define _GALAXYCATEGORISER_H_

#include <core/core.hpp>

class GalaxyCategoriser {
	public:
		enum GalaxyType { SPIRAL, ELLIPSE };		

		GalaxyCategoriser();
		GalaxyType categoriseGalaxy(cv::Mat image);
	private:
		int vib_upper;
		int vib_lower;
		int hue_upper;
		int hue_lower;
		int sat_upper;
		int sat_lower;

		int thresh;

		int countPixels(cv::Mat image);
};
#endif

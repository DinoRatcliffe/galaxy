///////////////////////////////////////////////////////////////
/// \file
/// \brief	A class used to determine what type of galaxy
///		is in an image.
/// 
/// \details	By passing your image to the categoriseGalaxy
///		and comparing the result with the galaxy types
///		defined in this class.
///
/// \author Dino Ratlcliffe
/// \date 2013
///////////////////////////////////////////////////////////////
#ifndef _GALAXYCATEGORISER_H_
#define _GALAXYCATEGORISER_H_

///////////////////////////////////////////////////////////////
// Includes
///////////////////////////////////////////////////////////////
#include <core/core.hpp>

///////////////////////////////////////////////////////////////
// Class
///////////////////////////////////////////////////////////////
class GalaxyCategoriser {
	public:
		enum GalaxyType { SPIRAL, ELLIPSE }; /// the types of galaxies this class detects		

		GalaxyCategoriser();

		////////////////////////////////////////////////////////////
		/// This function takes a cv Mat image and then catagorises
		/// the image as one of the GalaxyType enums.
		///
		/// It catagorises the image by first converting it to the
		/// hsv coloUr space and then blurring the image to remove
		/// some of the noise. Then it counts the blue pixels as
		/// set by the parameters in this class. If the pixel count
		/// is higer than a defined threshold it will return the type
		/// spiral.
		///
		/// \param image a cv Mat image
		/// \returns
		////////////////////////////////////////////////////////////
		GalaxyType categoriseGalaxy(cv::Mat image);
	private:
		int vib_upper; /// upper limit to match vibrance of pixel
		int vib_lower; /// lower limit to match vibrance of pixel
		int hue_upper; /// upper limit to match the hue of the pixel
		int hue_lower; /// lower limit to match the hue of the pixel
		int sat_upper; /// upper limit to match the saturation of the pixel
		int sat_lower; /// lower limit to match the saturation of the pixel

		int thresh; /// the threshold that the pixel number should go over 
			    /// to catagorise it as a spiral galaxy

		///////////////////////////////////////////////////////////
		/// This function takes an image and then counts the 
		/// number of pixels that fit into the range set by the 
		/// various parameters in this class  
		///
		/// \param 	image 	a cv Mat image
		/// \returns 	int 	a count of the number of pixels 
		///			within parameters
		///////////////////////////////////////////////////////////
		int countPixels(cv::Mat image);
};
#endif

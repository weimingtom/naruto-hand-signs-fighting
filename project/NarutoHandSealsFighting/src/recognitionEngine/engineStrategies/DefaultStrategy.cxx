/*
 ******************************************************
 * NAME:
 * DefaultStrategy.cxx
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Dec 7, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#include "DefaultStrategy.h"

DefaultStrategy::DefaultStrategy() {
	// TODO Auto-generated constructor stub

}

DefaultStrategy::~DefaultStrategy() {
	// TODO Auto-generated destructor stub
}

void DefaultStrategy::initModules(){
	//equalization
	addModule(new HistogramEM()); //<- remember to uncomment

	//Sobel
	//	recognitionEngine->addModule(new SobelEM(7, 2, 2));
	addModule(new SobelEM(CV_SCHARR, 1, 0)); //<-
	//	addModule(new SobelEM(CV_SCHARR, 0, 1));

	//Canny
	//	addModule(new CannyEM(5, 200, 40));

	//blurring
	addModule(new BlurEM(CV_GAUSSIAN,3,3)); //<-(?)

	//Laplacian
	addModule(new LaplacianEM(7)); //<-

	//contours extraction
	//addModule(new ContoursFinderEM(120));
}

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

DefaultStrategy::DefaultStrategy(ModulesPool* p) : AbstractStrategy(p) {
	// TODO Auto-generated constructor stub

}

DefaultStrategy::~DefaultStrategy() {
	// TODO Auto-generated destructor stub
}

void DefaultStrategy::initModules(){
	//equalization
	pool->addModule(new HistogramEM()); //<- remember to uncomment

	//Sobel
	//	pool->addModule(new SobelEM(7, 2, 2));
	pool->addModule(new SobelEM(CV_SCHARR, 1, 0)); //<-
	//	pool->addModule(new SobelEM(CV_SCHARR, 0, 1));

	//Canny
	//	pool->addModule(new CannyEM(5, 200, 40));

	//blurring
	pool->addModule(new BlurEM(CV_GAUSSIAN,3,3)); //<-(?)

	//Laplacian
	pool->addModule(new LaplacianEM(7)); //<-

	//contours extraction
	//addModule(new ContoursFinderEM(120));
}

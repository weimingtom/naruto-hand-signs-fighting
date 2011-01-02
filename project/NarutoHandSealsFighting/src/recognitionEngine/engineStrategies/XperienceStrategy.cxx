/*
 ******************************************************
 * NAME:
 * XperienceStrategy.cxx
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Jan 2, 2011
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#include "XperienceStrategy.h"
#include "../../acquisitionSection/Camera.h"

XperienceStrategy::XperienceStrategy(ModulesPool* p) : AbstractStrategy(p) {
	strategyName = "Xperience Strategy";
}

XperienceStrategy::~XperienceStrategy() {
	// TODO Auto-generated destructor stub
}

void XperienceStrategy::initModules(){
	IplImage *img;
	int meanImage;
	for(int i=0; i<10; i++)
		cam->capturing();

	img=cam->getFrame();

	meanImage = cvMean(img);

//	rePool->addModule(new ContoursFinderEM(meanImage));
	rePool->addModule(new BlurEM(CV_GAUSSIAN,3,3));
	rePool->addModule(new LaplacianEM(7));
	rePool->addModule(new ClosureEM(15));
}

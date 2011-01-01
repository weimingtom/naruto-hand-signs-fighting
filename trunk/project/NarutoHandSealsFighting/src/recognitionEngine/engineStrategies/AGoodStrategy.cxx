/*
 ******************************************************
 * NAME:
 * AGoodStrategy.cxx
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Jan 1, 2011
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#include "AGoodStrategy.h"
#include "../../acquisitionSection/Camera.h"
#include "../../DebugPrint.h"

AGoodStrategy::AGoodStrategy(ModulesPool* p) : AbstractStrategy(p) {
	strategyName = "AGoodStrategy";
	range = DEFAULT_RANGE;
}

AGoodStrategy::~AGoodStrategy() {
	// TODO Auto-generated destructor stub
}

void AGoodStrategy::initModules(){
	IplImage *img;
	for(int i=0; i<10; i++)
		cam->capturing();

	img=cam->getFrame();
//	const char *n = "AGoodStrategyTest";
//	cvNamedWindow(n, CV_WINDOW_AUTOSIZE);
//	cvShowImage(n, img);
//	cvWaitKey(0);
//	cvDestroyWindow(n);

	meanImage = cvMean(img);
//	debugPrint("Mean: %d \n", meanImage);

	rePool->addModule(new SobelEM(CV_SCHARR, 1, 0));
	rePool->addModule(new BlurEM(CV_GAUSSIAN,3,3));
	rePool->addModule(new LaplacianEM(7));
	rePool->addModule(new CannyEM(7, meanImage-range/2, meanImage+range/2));
	rePool->addModule(new ContoursFinderEM(meanImage));

	rePool->addModule(new ClosureEM(15));

}

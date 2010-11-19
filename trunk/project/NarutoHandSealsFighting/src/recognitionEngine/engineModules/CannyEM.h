/*
 ******************************************************
 * NAME:
 * CannyEM.h
 ******************************************************
 * DESCRIPTION:
 * Canny algorithm is useful for edge extraction in the image processing.
 * This class simply call use the cvCanny function in order to
 * execute it.
 *
 ******************************************************
 *	Created on: Nov 15, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#ifndef CANNYEM_H_
#define CANNYEM_H_

#include <opencv/cv.h>
#include <opencv/cxcore.h>
#include <opencv/highgui.h>
#include "EngineModule.h"

#define DEFAULT_CANNY_TH1 150
#define DEFAULT_CANNY_TH2 100
#define DEFAULT_CANNY_KERNEL 3

class CannyEM : public EngineModule{
	int kernelSize;
	double lowThresh, highThresh;
	void fixName();
public:
	CannyEM(){
		fixName();
		kernelSize = DEFAULT_CANNY_KERNEL;
		lowThresh = DEFAULT_CANNY_TH1;
		highThresh = DEFAULT_CANNY_TH2;
	}

	CannyEM(int kernelSize, double highThreshold, double lowThreshold);

	int compute( const IplImage* src, IplImage* dst);
};

#endif /* CANNYEM_H_ */

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

class CannyEM : public EngineModule{
public:
	CannyEM(){
		moduleName = "cannyModule";
	}

	int compute( const IplImage* src, IplImage* dst);
};

extern EngineModule *canny;

#endif /* CANNYEM_H_ */

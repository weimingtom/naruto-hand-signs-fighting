/*
 * CannyEM.h
 *
 *  Created on: Nov 15, 2010
 *      Author: michele
 */

#ifndef CANNYEM_H_
#define CANNYEM_H_

#include <opencv/cv.h>
#include <opencv/cxcore.h>
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

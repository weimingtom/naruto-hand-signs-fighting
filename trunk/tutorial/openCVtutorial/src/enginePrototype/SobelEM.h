/*
 * SobelEM.h
 *
 *  Created on: Nov 13, 2010
 *      Author: michele
 */

#ifndef SOBELEM_H_
#define SOBELEM_H_

#include "EngineModule.h"

class SobelEM : public EngineModule{
public:
	SobelEM(){
		moduleName = "sobelModule";
	}
	int compute( const IplImage* src, IplImage* dst);
};

extern EngineModule *sobel;

#endif /* SOBELEM_H_ */

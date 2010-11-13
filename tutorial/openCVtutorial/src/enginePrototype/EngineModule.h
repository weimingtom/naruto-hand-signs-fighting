/*
 * EngineModule.h
 *
 *  Created on: Nov 13, 2010
 *      Author: michele
 */

#ifndef ENGINEMODULE_H_
#define ENGINEMODULE_H_

#include <opencv/cv.h>
static long int globalID;

class EngineModule{
	long int moduleID;

public:
	EngineModule(){
		moduleID = globalID++;
	}

	long int getModuleID(){
		return moduleID;
	}

	virtual int compute( const IplImage* src, IplImage* dst) = 0;
};


#endif /* ENGINEMODULE_H_ */

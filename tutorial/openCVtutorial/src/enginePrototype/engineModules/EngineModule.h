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
protected:
	long int moduleID;
	const char* moduleName;

public:
	EngineModule(){
		moduleID = globalID++;
	}

	long int getModuleID(){
		return moduleID;
	}

	const char* getModuleName(){
		return moduleName;
	}

	virtual int compute( const IplImage* src, IplImage* dst) = 0;
};


#endif /* ENGINEMODULE_H_ */

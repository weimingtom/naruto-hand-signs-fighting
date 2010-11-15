/*
 ******************************************************
 * NAME:
 * EngineModule.h
 ******************************************************
 * DESCRIPTION:
 * Recall that the Recognition Engine is made by different module which
 * are called Engine Module, each developing a different feature to
 * the image process phase.
 * This class is a pure virtual one which can be used in order to build
 * these module and put them in the Recognition Engine.
 *
 * Pattern Applied: Strategy
 * Any Engine Module needs to provide an implementation for the
 * strategy class member:
 *       int compute( const IplImage* src, IplImage* dst);
 * The implementation corresponds to the specific feature provided by the
 * class performing a part in the overall algorithm.
 *
 ******************************************************
 *	Created on: Nov 13, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
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

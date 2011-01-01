/*
 ******************************************************
 * NAME:
 * AbstractProcessingFunction.h
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Dec 27, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#ifndef ABSTRACTPROCESSINGFUNCTION_H_
#define ABSTRACTPROCESSINGFUNCTION_H_

#include <vector>
#include <opencv/cv.h>
#include "../engineModules/EngineModule.h"

using namespace std;

class AbstractProcessingFunction {
protected:
	const char* processingFunctionName;
public:
	virtual int processFunction(std::vector<EngineModule*> *modArray,
			const IplImage* src, IplImage* res) = 0;
    const char *getProcessingFunctionName() const
    {
        return processingFunctionName;
    }

};

#endif /* ABSTRACTPROCESSINGFUNCTION_H_ */

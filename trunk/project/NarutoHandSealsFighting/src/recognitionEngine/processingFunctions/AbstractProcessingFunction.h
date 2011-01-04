/*
 ******************************************************
 * NAME:
 * AbstractProcessingFunction.h
 ******************************************************
 * DESCRIPTION:
 * A processing function defines in what way the modules
 * are combined in order to produce a good result
 * (eg if the output of
 * a module have to interact with the next one).
 *
 * All classes that are supposed to be a
 * ProcessingFunction need to implement the function:
 *
 * int processFunction(std::vector<EngineModule*> *modArray,
			const IplImage* src, IplImage* res)
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

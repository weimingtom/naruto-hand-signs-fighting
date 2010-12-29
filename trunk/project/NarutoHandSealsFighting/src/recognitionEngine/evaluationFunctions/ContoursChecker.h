/*
 ******************************************************
 * NAME:
 * ContoursChecker.h
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

#ifndef CONTOURSCHECKER_H_
#define CONTOURSCHECKER_H_

#include "EvaluatorFunctionTemplate.h"
#include "../engineModules/ContoursFinderEM.h"

class ContoursChecker: public EvaluatorFunctionTemplate {
protected:
	ContoursFinderEM *contourTemplate;
	ContoursFinderEM *contourImage;
public:
	ContoursChecker();
	virtual ~ContoursChecker();

	int evaluate(IplImage* img, Move* currMove, int sealIndex);
};

#endif /* CONTOURSCHECKER_H_ */

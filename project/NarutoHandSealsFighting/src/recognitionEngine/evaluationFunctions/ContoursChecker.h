/*
 ******************************************************
 * NAME:
 * ContoursChecker.h
 ******************************************************
 * DESCRIPTION:
 * It extracts the contour of the input image and the
 * template image by using cvFindContours.
 * Then it applies a match with the function:
 * cvMatchShapes
 * with the CV_CONTOURS_MATCH_I3 algorithm.
 *
 * You can visualize the result by setting the
 * SHOW_WINDOWS define in the file
 * ContoursChecker.cxx
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

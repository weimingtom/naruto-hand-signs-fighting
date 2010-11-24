/*
 ******************************************************
 * NAME:
 * evaluatorFunctionTemplate.h
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Nov 23, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#ifndef EVALUATORFUNCTIONTEMPLATE_H_
#define EVALUATORFUNCTIONTEMPLATE_H_

#include <opencv/cv.h>
#include "../../gameLogic/Move.h"

class EvaluatorFunctionTemplate{
protected:
	const char* evaluatorName;
public:
	virtual int evaluate(IplImage* img, Move* currMove, int sealIndex) = 0;

    const char *getEvaluatorName() const
    {
        return evaluatorName;
    }

};


#endif /* EVALUATORFUNCTIONTEMPLATE_H_ */

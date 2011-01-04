/*
 ******************************************************
 * NAME:
 * MulEvaluator.h
 ******************************************************
 * DESCRIPTION:
 * It uses the template image as a mask by multiplying
 * each pixel of the input image by the template.
 * Only the very identical pixel (set to 1) are
 * kept by this comparison.
 *
 ******************************************************
 *	Created on: Nov 23, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#ifndef MULEVALUATOR_H_
#define MULEVALUATOR_H_

#include "EvaluatorFunctionTemplate.h"

class MulEvaluator : public EvaluatorFunctionTemplate{
	void displayResult(IplImage* input, IplImage* templateImg, IplImage* result, int delay);
public:
	MulEvaluator(){
		evaluatorName = "MulEvaluator";
	};

	int evaluate(IplImage* img, Move* currMove, int sealIndex);

};

extern EvaluatorFunctionTemplate* mulEvaluator;

#endif /* MULEVALUATOR_H_ */

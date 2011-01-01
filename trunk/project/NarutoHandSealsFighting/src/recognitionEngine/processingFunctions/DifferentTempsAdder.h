/*
 ******************************************************
 * NAME:
 * DifferentTempsAdder.h
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

#ifndef DIFFERENTTEMPSADDER_H_
#define DIFFERENTTEMPSADDER_H_

#include "AbstractProcessingFunction.h"

class DifferentTempsAdder: public AbstractProcessingFunction {
public:
	DifferentTempsAdder();
	virtual ~DifferentTempsAdder();

	int processFunction(std::vector<EngineModule*> *modArray, const IplImage* src, IplImage* res);
};

#endif /* DIFFERENTTEMPSADDER_H_ */

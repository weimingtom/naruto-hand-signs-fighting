/*
 ******************************************************
 * NAME:
 * ChainAdder.h
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

#ifndef CHAINADDER_H_
#define CHAINADDER_H_

#include "AbstractProcessingFunction.h"

class ChainAdder: public AbstractProcessingFunction {
public:
	ChainAdder();
	virtual ~ChainAdder();

	int processFunction(std::vector<EngineModule*> modArray, const IplImage* src, IplImage* res);
};

#endif /* CHAINADDER_H_ */

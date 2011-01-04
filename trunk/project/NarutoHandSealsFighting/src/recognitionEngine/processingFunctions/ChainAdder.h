/*
 ******************************************************
 * NAME:
 * ChainAdder.h
 ******************************************************
 * DESCRIPTION:
 * It structures the modules as a chain.
 * The pixels resulting from the process will be
 * added to the incoming image, and then this is
 * the output for the next module.
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

	int processFunction(std::vector<EngineModule*> *modArray, const IplImage* src, IplImage* res);
};

#endif /* CHAINADDER_H_ */

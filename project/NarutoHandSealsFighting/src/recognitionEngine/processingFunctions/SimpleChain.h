/*
 ******************************************************
 * NAME:
 * SimpleChain.h
 ******************************************************
 * DESCRIPTION:
 * It structures the modules as a chain.
 * Then the output of a module will become the input
 * of the next one.
 *
 ******************************************************
 *	Created on: Dec 30, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#ifndef SIMPLECHAIN_H_
#define SIMPLECHAIN_H_

#include "AbstractProcessingFunction.h"

class SimpleChain: public AbstractProcessingFunction {
public:
	SimpleChain();
	virtual ~SimpleChain();

	int processFunction(std::vector<EngineModule*> *modArray,
				const IplImage* src, IplImage* res);
};

#endif /* SIMPLECHAIN_H_ */

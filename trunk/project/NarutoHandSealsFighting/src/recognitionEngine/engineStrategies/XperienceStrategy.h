/*
 ******************************************************
 * NAME:
 * XperienceStrategy.h
 ******************************************************
 * DESCRIPTION:
 * Engine Strategy
 * It adds the following modules:
 * 1. Blurr with pars CV_GAUSSIAN,3,3
 * 2. Laplacian with kernel size 7x7
 * 3. Closure iterated for 15 iterations
 *
 ******************************************************
 *	Created on: Jan 2, 2011
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#ifndef XPERIENCESTRATEGY_H_
#define XPERIENCESTRATEGY_H_

#include "AbstractStrategy.h"

class XperienceStrategy: public AbstractStrategy {
public:
	XperienceStrategy(ModulesPool* p);
	virtual ~XperienceStrategy();
	void initModules();
};

#endif /* XPERIENCESTRATEGY_H_ */

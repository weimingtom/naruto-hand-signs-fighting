/*
 ******************************************************
 * NAME:
 * AGoodStrategy.h
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Jan 1, 2011
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#ifndef AGOODSTRATEGY_H_
#define AGOODSTRATEGY_H_

#include "AbstractStrategy.h"

#define DEFAULT_RANGE 20;

class AGoodStrategy: public AbstractStrategy {
	int meanImage;
	double range;

public:
	AGoodStrategy(ModulesPool* p);
	virtual ~AGoodStrategy();

	void initModules();
};

#endif /* AGOODSTRATEGY_H_ */

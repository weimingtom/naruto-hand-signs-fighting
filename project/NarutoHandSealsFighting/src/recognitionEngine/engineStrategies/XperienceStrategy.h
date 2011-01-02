/*
 ******************************************************
 * NAME:
 * XperienceStrategy.h
 ******************************************************
 * DESCRIPTION:
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

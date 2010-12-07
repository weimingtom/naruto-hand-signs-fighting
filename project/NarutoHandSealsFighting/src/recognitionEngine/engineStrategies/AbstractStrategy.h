/*
 ******************************************************
 * NAME:
 * AbstractStrategy.h
 ******************************************************
 * DESCRIPTION:
 *
 * A strategy in the Recognition Engine defines the order and
 * what modules load into it. This abstract class is will
 * left to its descendants the task to implement the method
 * that adds the desired modules.
 *
 * In building new strategies keep in mind that the order is
 * very relevant. Each modules will be applied to the input
 * image following the order chose during the initialization.
 *
 ******************************************************
 *	Created on: Dec 7, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#ifndef ABSTRACTSTRATEGY_H_
#define ABSTRACTSTRATEGY_H_

#include "../ModulesPool.h"
#include "../engineModules/All.h"

class AbstractStrategy : public ModulesPool {

public:
	AbstractStrategy();
	virtual ~AbstractStrategy();

	virtual void initModules() = 0;
};

#endif /* ABSTRACTSTRATEGY_H_ */

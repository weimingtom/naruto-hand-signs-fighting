/*
 ******************************************************
 * NAME:
 * MovesFactory.h
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Nov 20, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#ifndef MOVESFACTORY_H_
#define MOVESFACTORY_H_

#include "MovesFactoryAbstract.h"
#include "MovesSettings.h"
#include "Move.h"

class MovesFactory : public MovesFactoryAbstract {
public:
	void buildMovesSet(MovesSet* mSet);
};

extern MovesFactoryAbstract *movesFactory;

#endif /* MOVESFACTORY_H_ */

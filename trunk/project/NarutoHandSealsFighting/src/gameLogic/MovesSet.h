/*
 ******************************************************
 * NAME:
 * MovesSet.h
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

#ifndef MOVESSET_H_
#define MOVESSET_H_

#include <set>
#include "Move.h"

using namespace std;

class MovesSet{
	set<Move*> movesSet;

public:
	MovesSet(){};

	int addMove(Move* m);

    set<Move*> getMoveSet() const
    {
        return movesSet;
    }

};


#endif /* MOVESSET_H_ */

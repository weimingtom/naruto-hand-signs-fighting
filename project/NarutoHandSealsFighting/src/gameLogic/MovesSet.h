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

//#include <set> // <- it will not works properly....
#include <map>
#include <string>
#include "Move.h"

using namespace std;

class MovesSet{
	map<string,Move*> movesSet;

public:
	MovesSet(){};

	int addMove(Move* m);
	Move* getMove(const char* moveName);

    map<string,Move*> getMoveSet() const
    {
        return movesSet;
    }

};


#endif /* MOVESSET_H_ */

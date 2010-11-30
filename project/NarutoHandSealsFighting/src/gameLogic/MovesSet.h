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
	~MovesSet();

	int addMove(Move* m);
	Move* getMove(const char* moveName);
	Move* getMove(string s);

    map<string,Move*> getMoveSet() const
    {
        return movesSet;
    }

};

extern MovesSet* movesSetGlobal;


#endif /* MOVESSET_H_ */

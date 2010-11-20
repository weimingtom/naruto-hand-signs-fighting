/*
 ******************************************************
 * NAME:
 * Move.h
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

#ifndef MOVE_H_
#define MOVE_H_

#include <string>
#include "HandSeal.h"


using namespace std;

/*
 * Type of JUSTU such as:
 *  - genjustu: illusion technique
 *  - taijustu: body technique
 *  - ninjustu: general technique (doesn't fall in other two categories)
 *  - kekkei genkai: bloodline limit
 *  - fuingjustu: sealing jutsu
 */
struct MoveType{
	string japName;
	string engName;
};

enum MoveElements{
		FIRE, WATER, ICE, GROUND, LIGHTNING, WIND, UNBREAKABLESEAL
	};

enum DifficultyRank{
	A, B, C, D, E, F, SECRET, FORBIDDEN
};

class Move{
	vector<HandSeal*> moveSeals;

	string moveName;
	MoveType type;
	MoveElements element;
	DifficultyRank rank;

public:

	Move(const char* name);
	Move(const char* name, MoveType t, MoveElements ele, DifficultyRank diff);

	void setMoveName(const char* s){
		moveName = string(s);
	}

    MoveElements getElement() const
    {
        return element;
    }

    string getMoveName() const
    {
        return moveName;
    }

    vector<HandSeal*> getMoveSeals() const
    {
        return moveSeals;
    }

    MoveType getType() const
    {
        return type;
    }

    void setMoveSeals(vector<HandSeal*> moveSeals)
    {
        this->moveSeals = moveSeals;
    }

};

#endif /* MOVE_H_ */

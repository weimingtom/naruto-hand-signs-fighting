/*
 * Move.cxx
 *
 *  Created on: Nov 19, 2010
 *      Author: michele
 */

#include "Move.h"


Move::Move(const char* name, MoveType t, MoveElements ele, DifficultyRank diff){
	moveName = name;
	type =t;
	element = ele;
	rank = diff;
}

Move::Move(const char* n){
	moveName = n;
}

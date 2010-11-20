/*
 * MovesFactory.cxx
 *
 *  Created on: Nov 19, 2010
 *      Author: michele
 */

#include "MovesFactory.h"

MovesFactoryAbstract *movesFactory = new MovesFactory();

void MovesFactory::buildMovesSet(MovesSet* mSet){
	Move *mTemp;
	MoveStruct *mStr;
	MoveType t;
	for(int i = 0; i<MOVES_NUMBER; i++){
		mStr = &moves[i];
		t.japName = string( jutsuTypes[mStr->jutsuType][JUTSU_TYPES_JAPNAME]);
		t.engName = string( jutsuTypes[mStr->jutsuType][JUTSU_TYPES_ENGNAME]);
		mTemp = new Move(mStr->name, t, mStr->element, mStr->difficulty);
		mSet->addMove(mTemp);
	}

}

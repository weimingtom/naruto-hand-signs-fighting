/*
 ******************************************************
 * NAME:
 * MovesSettings.h
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

#ifndef MOVESSETTINGS_H_
#define MOVESSETTINGS_H_

#include "Move.h"
#include "SealsMap.h"

#define JUTSU_TYPES_JAPNAME 0
#define JUTSU_TYPES_ENGNAME 1
#define MOVES_NUMBER 2

struct MoveStruct{
	const char* name;
	int jutsuType;
	MoveElements element;
	DifficultyRank difficulty;
};

extern const char* jutsuTypes[][2];
//extern const int MOVES_NUMBER;
extern MoveStruct moves[MOVES_NUMBER];
extern const char* movesSeals[][MOVES_NUMBER];


#endif /* MOVESSETTINGS_H_ */

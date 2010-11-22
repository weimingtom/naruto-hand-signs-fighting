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

#define STOPPING_STRING "stop"
#define FILE_MOVES_SEALS "MovesSeals.txt"
#define JUTSU_TYPES_JAPNAME 0
#define JUTSU_TYPES_ENGNAME 1

struct MoveStruct{
	const char* name;
	int jutsuType;
	MoveElements element;
	DifficultyRank difficulty;
};

struct moveSealsStruct{
	const char* s[];
};

extern const char* jutsuTypes[][2];

#define MOVES_NUMBER 2
extern MoveStruct moves[MOVES_NUMBER];

#endif /* MOVESSETTINGS_H_ */

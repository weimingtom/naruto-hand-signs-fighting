/*
 ******************************************************
 * NAME:
 * MovesSettings.cxx
 ******************************************************
 * DESCRIPTION:
 * Implementation of MovesSettings.h
 ******************************************************
 *	Created on: Nov 20, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#include "MovesSettings.h"

using namespace std;

const char* jutsuTypes[][2] = {
		"Genjutsu", "Illusionary", //0
		"Taijutsu", "Body", //1
		"Ninjutsu", "Chakra", //2
		"Kekkei Genkai", "Bloodline Limit", //3
		"Fuingjutsu", "Sealing Jutsu" //4
};

MoveStruct moves[MOVES_NUMBER] = {
		"LighningBlade", 2, LIGHTNING, B,
		"DemonicSoulSeal", 4, UNBREAKABLESEAL, S
};

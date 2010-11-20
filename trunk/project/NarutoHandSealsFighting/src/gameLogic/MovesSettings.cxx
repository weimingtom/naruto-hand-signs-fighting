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

//const int MOVES_NUMBER = 2;

const char* jutsuTypes[][2] = {
		"Genjutsu", "Illusionary", //0
		"Taijutsu", "Body", //1
		"Ninjutsu", "Chakra", //2
		"Kekkei Genkai", "Bloodline Limit", //3
		"Fuingjutsu", "Sealing Jutsu" //4
};

//const char* demonicSoulSeal_Seals[] = {
//		"serpent", "boar", "ram", "hare", "dog", "rat", "bird", "horse", "serpent"
//};

//const char* LightningBlade_Seals[] = {"cow", "hare", "monkey"};

const char* movesSeals[][MOVES_NUMBER] = {
		"cow", "hare", "monkey", "0", //LighningBlade
		"serpent", "boar", "ram", "hare", "dog", "rat", "bird", "horse", "serpent", "0" //DemonicSoulSeal

};

MoveStruct moves[MOVES_NUMBER] = {
		"LighningBlade", 4, LIGHTNING, B,
		"DemonicSoulSeal", 4, UNBREAKABLESEAL, SECRET
};

/*
 ******************************************************
 * NAME:
 * gameStackTest.cxx
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Nov 25, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */
#include <iostream>
#include <stdio.h>
#include "GameMachine.h"
#include "FactoryGameMachine.h"
#include "../DebugPrint.h"

int main(int argc, char* argv[]){
	cout<<"**********\n";
	cout<<"GAME STACK TEST \n";
	cout<<"**********\n";
	GameMachine *gm = GameMachine().getGameMachineInstance();
	debugPrint("Initializing the GameMachine ... ");

	factoryGameMachine->initGameMachine(gm);

	debugPrint("done\n");

	debugPrint("Starting the machine: ");
	gm->startGameMachine();
	debugPrint("done\n");
	gm->mainLoop();

	return 0;
}

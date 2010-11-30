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
#include "../gui/MenuWindow.h"

#include "../gameLogic/GameLogic.h"

#include "../DebugPrint.h"

int main(int argc, char* argv[]){
	AbstractFactory* mainMenu;

	//Game Logic initialization
	SealsMap smap;
	MovesSet *myMoveSet = movesSetGlobal;
	sealsFactory->buildSealsMap(&smap);
	movesFactory->buildMovesSet(myMoveSet, &smap);

	cout<<"**********\n";
	cout<<"GAME STACK TEST \n";
	cout<<"**********\n";
	try{
		GameMachine *gm = GameMachine().getGameMachineInstance();
		debugPrint("Initializing the GameMachine ... ");
		factoryGameMachine->initGameMachine(gm);
		debugPrint("done\n");

		debugPrint("Starting the machine: ");
		gm->startGameMachine();
		debugPrint("done\n");
		gm->mainLoop();
	}catch(gcn::Exception e){
		cout<<e.getMessage().c_str()<<"\n";
	}catch(std::exception e){
		cout<<e.what()<<"\n";
	}

	return 0;
}

/*
 ******************************************************
 * NAME:
 * FactoryGameMachine.cxx
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


#include "FactoryGameMachine.h"
#include "../DebugPrint.h"

FactoryGameMachine* factoryGameMachine = new FactoryGameMachine();

void FactoryGameMachine::initGameMachine(GameMachine* gameMachine){
	/*
	 * !!! REMEMBER !!!
	 * The order is relevant!!
	 * The gameMachine is a stack, with policy LIFO (Last In First Out).
	 * Your last inserted element will be the one (first) displayed.
	 */
//	debugPrint("create a MainMenu\n");
//	MainMenu* m = new MainMenu();
//	debugPrint("set the MainMenuController\n");
//	m->setMainMenuCtrl(mainMenuController);
//	debugPrint("inserting the MainMenu... ");
//	gameMachine->pushInGameStack(m);
//	debugPrint("done");

//	gameMachine->pushInGameStack(new OptionsMenu(new OptionsMenuController(gameMachine)));
//	gameMachine->pushInGameStack(new MovesList(new MovesListController(gameMachine)));

	gameMachine->pushInGameStack(new MainMenu(new MainMenuController(gameMachine)));
}

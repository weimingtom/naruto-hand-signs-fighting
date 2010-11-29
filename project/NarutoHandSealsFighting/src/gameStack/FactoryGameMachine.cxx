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
	 */
//	debugPrint("create a MainMenu\n");
//	MainMenu* m = new MainMenu();
//	debugPrint("set the MainMenuController\n");
//	m->setMainMenuCtrl(mainMenuController);
//	debugPrint("inserting the MainMenu... ");
//	gameMachine->pushInGameStack(m);
//	debugPrint("done");
	gameMachine->pushInGameStack(new MainMenu(new MainMenuController(gameMachine)));
	gameMachine->pushInGameStack(new OptionsMenu(new OptionsMenuController(gameMachine)));
	gameMachine->pushInGameStack(new MovesList(new MovesListController(gameMachine)));
}

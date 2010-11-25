/*
 ******************************************************
 * NAME:
 * FactoryGameMachine.h
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

#ifndef FACTORYGAMEMACHINE_H_
#define FACTORYGAMEMACHINE_H_

//Target of the factory: our GameMachine
#include "GameMachine.h"

//Elements that need to be inserted into the GameMachine
/////////////////////////////
#include "menu/MainMenu.h"
/////////////////////////////

//Controller of the elements just inserted
/////////////////////////////
#include "controller/MainMenuController.h"
/////////////////////////////

using namespace std;

class FactoryGameMachine{
public:
	void initGameMachine(GameMachine* gm);
};

extern FactoryGameMachine* factoryGameMachine;

#endif /* FACTORYGAMEMACHINE_H_ */

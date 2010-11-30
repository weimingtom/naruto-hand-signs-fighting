/*
 ******************************************************
 * NAME:
 * GameMachine.cxx
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

#include "GameMachine.h"

//Initialization of the gameMachine pointer
GameMachine* GameMachine::gameMachine = NULL;

int GameMachine::mainLoop(){
	while(running){
		gameStack.top()->loopFunction();
	}
}

int GameMachine::startGameMachine(){
	running = true;
	return 0;
}

int GameMachine::stopGameMachine(){
	running = false;
	return 0;
}

void GameMachine::pushInGameStack(GameElement* e){
	gameStack.push(e);
}

GameElement* GameMachine::popFromGameStack(){
	gameStack.pop();
	if(gameStack.empty())
		return NULL;
	return gameStack.top();
}

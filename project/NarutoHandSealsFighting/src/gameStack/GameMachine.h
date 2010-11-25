/*
 ******************************************************
 * NAME:
 * GameMachine.h
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

#ifndef GAMEMACHINE_H_
#define GAMEMACHINE_H_

#include <stack>
#include "GameElement.h"

using namespace std;

class GameMachine{

	//PATTERN: Singletone
	static GameMachine* gameMachine;

	//The gameStack contains all the elements of the game
	stack<GameElement*> gameStack;

	bool running;

public:

	static GameMachine* getGameMachineInstance(){
		if(gameMachine == NULL){
			gameMachine = new GameMachine();
		}
		return gameMachine;
	}

	/*
	 * Starts the main-loop-function launching the top
	 * element loopFunction in the gameStack
	 */
	int mainLoop();

	int startGameMachine();
	int stopGameMachine();

	/*
	 * Push the GameElement pointed by e in the
	 * top of the gameStack
	 */
	void pushInGameStack(GameElement* e);

	/*
	 * Remove the current top element from the
	 * gameStack and return a pointer to the new
	 * one actually in top
	 */
	GameElement* popFromGameStack();

};

#endif /* GAMEMACHINE_H_ */

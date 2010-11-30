/*
 ******************************************************
 * NAME:
 * MovesListController.cxx
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Nov 29, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#include "MovesListController.h"

MovesListController* movesListController_Kagi = new MovesListController(
		GameMachine::getGameMachineInstance());

MovesListController::~MovesListController() {
	// TODO Auto-generated destructor stub
}

void MovesListController::dispatchEvent(SDL_Event* e){
	Move* m;
	if (e->type == SDL_KEYDOWN)
	{
		GeneralKeyboardController::dispatchEvent(e);
		switch(e->key.keysym.sym){

			case SDLK_ASTERISK:
				m = movesSetGlobal->getMove(targetMove);
				gameMachine->pushInGameStack(new TrainingSection(m, movesListController_Kagi));
				break;

			default:
				cout<<"not recognized key pressed: \n";
		}
	}
}

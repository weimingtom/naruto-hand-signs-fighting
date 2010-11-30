/*
 ******************************************************
 * NAME:
 * GeneralKeyboadController.cxx
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Nov 30, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#include "GeneralKeyboardController.h"

GeneralKeyboardController::GeneralKeyboardController(GameMachine* gm):AbstractController(gm){

}

GeneralKeyboardController::~GeneralKeyboardController() {
	// TODO Auto-generated destructor stub
}

void GeneralKeyboardController::dispatchEvent(SDL_Event *e){
	switch(e->key.keysym.sym){
		case SDLK_ESCAPE:
			gameMachine->stopGameMachine();
			break;

		case SDLK_b:
			if(gameMachine->popFromGameStack() == NULL)
				gameMachine->stopGameMachine();
			break;

	}
}

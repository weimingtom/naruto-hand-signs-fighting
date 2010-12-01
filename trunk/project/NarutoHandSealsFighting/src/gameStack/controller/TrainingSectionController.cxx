/*
 ******************************************************
 * NAME:
 * TrainingSectionController.cxx
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

#include "TrainingSectionController.h"

using namespace std;

TrainingSectionController::TrainingSectionController(GameMachine* gm) :
	AbstractController(gm){

}

TrainingSectionController::~TrainingSectionController() {
	// TODO Auto-generated destructor stub
}

void TrainingSectionController::dispatchEvent(SDL_Event* e){
//	debugPrint("received event of type %d \n", e->type);
	switch(e->type){
		case SDL_KEYDOWN:
			dispatchKeyboardEvent(e);
			break;

		case SDL_QUIT:
			gameMachine->stopGameMachine();
			break;

		default:
			break;
	}
}

void TrainingSectionController::dispatchKeyboardEvent(SDL_Event* e){
	switch(e->key.keysym.sym){
		case SDLK_ESCAPE:
			break;

		case SDLK_SPACE:
			//shotPhoto();
			break;

		case SDLK_b:
			gameMachine->popFromGameStack();
			trainingWindow->restoreOldSizeWindow();
			break;

		default:
			break;
	}
}

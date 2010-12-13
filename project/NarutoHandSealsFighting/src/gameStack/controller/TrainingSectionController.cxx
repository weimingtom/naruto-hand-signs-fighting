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
#include "../../DebugPrint.h"

using namespace std;

TrainingSectionController::TrainingSectionController(GameMachine* gm) :
	AbstractController(gm){
	director = NULL;
	trainingWindow = NULL;
}

TrainingSectionController::~TrainingSectionController() {
	debugPrint("TrainingSectionController destructor\n");
	if(director != NULL)
		delete director;
	if(trainingWindow != NULL)
		delete trainingWindow;
}

void TrainingSectionController::dispatchEvent(SDL_Event* e){
//	debugPrint("received event of type %d \n", e->type);
	switch(e->type){
		case SDL_KEYDOWN:
			dispatchKeyboardEvent(e);
			break;

		case SDL_KEYUP:
			//nothing
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

		case SDLK_s:
			director->handleShot(10, trainingWindow->getCurrentSealIndex());
			break;

		case SDLK_ASTERISK:
			director->elapsedTimer();
			break;

		case SDLK_b:
			gameMachine->popFromGameStack();
			trainingWindow->restoreOldSizeWindow();
			break;

		default:
			break;
	}
}

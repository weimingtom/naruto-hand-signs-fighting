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
	debugPrint("received event of type %d \n", e->type);
}

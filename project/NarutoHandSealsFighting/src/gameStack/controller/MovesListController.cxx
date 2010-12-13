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

#include "../../DebugPrint.h"
#include "MovesListController.h"

//MovesListController* movesListController_Kagi = new MovesListController(
//		GameMachine::getGameMachineInstance());
MovesListController* movesListController_Kagi ;

MovesListController::~MovesListController() {
	// TODO Auto-generated destructor stub
}

void MovesListController::dispatchEvent(SDL_Event* e){
	Move* m;
	if (e->type == SDL_KEYDOWN)
	{
		GeneralKeyboardController::dispatchEvent(e);
		switch(e->key.keysym.sym){

			case SDLK_s:
//				debugPrint("SDL asterisk\n targetMove: %s \n", targetMove.c_str());
				if(strcmp(targetMove.c_str(), "") != 0){
					m = movesSetGlobal->getMove(targetMove);
					gameMachine->pushInGameStack(
							new TrainingSection(m, new TrainingSectionController(gameMachine)));
				}else{
					cout<<"ERROR: MovesListController: targetMove still not initialized\n";
				}
				break;

			default:
//				cout<<"not recognized key pressed: \n";
				break;
		}
	}
}

/*
 ******************************************************
 * NAME:
 * MainMenuController.cxx
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

#include <iostream>
#include "MainMenuController.h"
#include "../controller/MovesListController.h"
#include "../controller/OptionsMenuController.h"
#include "../menu/OptionsMenu.h"
#include "../menu/MovesList.h"
#include "../../gameLogic/MovesSet.h"

using namespace std;

void MainMenuController::dispatchEvent(SDL_Event* event){
	if (event->type == SDL_KEYDOWN)
	{
		GeneralKeyboardController::dispatchEvent(event);
		switch(event->key.keysym.sym){
			case SDLK_q:
				gameMachine->stopGameMachine();
				break;

			case SDLK_i:
				break;

			case SDLK_t:
				movesListController_Kagi = new MovesListController(gameMachine);
				gameMachine->pushInGameStack(
						new MovesList(movesListController_Kagi, movesSetGlobal));
				break;

			case SDLK_p:
				cout<<"NOT Supported feature in this release\n";
				break;

			case SDLK_o:
				gameMachine->pushInGameStack(new OptionsMenu(new OptionsMenuController(gameMachine)));
				break;

			default:
//				cout<<"not recognized key pressed: "<< SDL_GetKeyName(event->key.keysym.sym) <<"\n";
				break;
		}
	}
}

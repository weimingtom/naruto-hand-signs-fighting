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

using namespace std;

//AbstractController* mainMenuController = new MainMenuController();

void MainMenuController::dispatchEvent(SDL_Event* event){
	if (event->type == SDL_KEYDOWN)
	{
		switch(event->key.keysym.sym){
			case SDLK_ESCAPE: case SDLK_q:
				gameMachine->stopGameMachine();
				break;

			case SDLK_i:
				cout<<"pressed i\n";
				break;

			case SDLK_t:
				cout<<"pressed t\n";
				gameMachine->pushInGameStack(new MovesList(new MovesListController(gameMachine)));
				break;

			case SDLK_o:
				cout<<"pressed o\n";
				gameMachine->pushInGameStack(new OptionsMenu(new OptionsMenuController(gameMachine)));
				break;

			case SDLK_b:
				if(gameMachine->popFromGameStack() == NULL)
					gameMachine->stopGameMachine();
				break;

			default:
				cout<<"not recognized key pressed: "<< event->key.keysym.sym <<"\n";
		}
	}
}

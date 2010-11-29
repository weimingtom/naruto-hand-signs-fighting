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
				break;

			case SDLK_t:
				break;

			case SDLK_o:
				break;

			default:
				cout<<"not recognized key pressed: "<< event->key.keysym.sym <<"\n";
		}
	}
}

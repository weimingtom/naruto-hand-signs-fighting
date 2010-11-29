/*
 ******************************************************
 * NAME:
 * OptionsMenuController.cxx
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
#include "OptionsMenuController.h"

void OptionsMenuController::dispatchEvent(SDL_Event* event){
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

			case SDLK_b:
				if(gameMachine->popFromGameStack() == NULL)
					gameMachine->stopGameMachine();
				break;

			default:
				cout<<"not recognized key pressed: "<< event->key.keysym.sym <<"\n";
		}
	}
}

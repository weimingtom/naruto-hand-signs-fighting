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

MovesListController::~MovesListController() {
	// TODO Auto-generated destructor stub
}

void MovesListController::dispatchEvent(SDL_Event* e){
	if (e->type == SDL_KEYDOWN)
	{
		GeneralKeyboardController::dispatchEvent(e);
		switch(e->key.keysym.sym){

			default:
				//cout<<"not recognized key pressed: "<< SDL_GetKeyName(event->key.keysym.sym) <<"\n";
				break;
		}
	}
}

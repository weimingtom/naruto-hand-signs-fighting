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
		GeneralKeyboardController::dispatchEvent(event);
		switch(event->key.keysym.sym){


			default:
//				cout<<"not recognized key pressed: "<< event->key.keysym.sym <<"\n";
				break;
		}
	}
}

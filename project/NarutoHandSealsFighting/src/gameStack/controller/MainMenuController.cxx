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

#include "MainMenuController.h"

//AbstractController* mainMenuController = new MainMenuController();

void MainMenuController::dispatchEvent(SDL_Event* event){
	if (event->type == SDL_KEYDOWN)
	{
		if (event->key.keysym.sym == SDLK_ESCAPE)
		{
			gameMachine->stopGameMachine();
		}
		if (event->key.keysym.sym == SDLK_f)
		{
			if (event->key.keysym.mod & KMOD_CTRL)
			{
				// Works with X11 only
//				SDL_WM_ToggleFullScreen(menu->getScreen());
			}
		}
	}
}

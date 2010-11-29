/*
 ******************************************************
 * NAME:
 * MainMenuController.h
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

#ifndef MAINMENUCONTROLLER_H_
#define MAINMENUCONTROLLER_H_

#include "AbstractController.h"

class MainMenuController : public AbstractController{

public:
	MainMenuController(GameMachine* gm):AbstractController(gm){};
	void dispatchEvent(SDL_Event* e);
};

#endif /* MAINMENUCONTROLLER_H_ */

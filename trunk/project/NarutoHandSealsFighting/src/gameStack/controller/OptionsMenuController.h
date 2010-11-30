/*
 ******************************************************
 * NAME:
 * OptionsMenuController.h
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

#ifndef OPTIONSMENUCONTROLLER_H_
#define OPTIONSMENUCONTROLLER_H_

#include "GeneralKeyboardController.h"

class OptionsMenuController : public GeneralKeyboardController{
public:
	OptionsMenuController(GameMachine* gm):GeneralKeyboardController(gm){};
	void dispatchEvent(SDL_Event* e);
};


#endif /* OPTIONSMENUCONTROLLER_H_ */

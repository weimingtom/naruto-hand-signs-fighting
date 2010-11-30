/*
 ******************************************************
 * NAME:
 * GeneralKeyboadController.h
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Nov 30, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#ifndef GENERALKEYBOADCONTROLLER_H_
#define GENERALKEYBOADCONTROLLER_H_

#include "AbstractController.h"

class GeneralKeyboardController: public AbstractController {
public:
	GeneralKeyboardController(GameMachine* gm);
	virtual ~GeneralKeyboardController();
	void dispatchEvent(SDL_Event* e);
};

#endif /* GENERALKEYBOADCONTROLLER_H_ */

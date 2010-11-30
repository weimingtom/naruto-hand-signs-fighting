/*
 ******************************************************
 * NAME:
 * MovesListController.h
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

#ifndef MOVESLISTCONTROLLER_H_
#define MOVESLISTCONTROLLER_H_

#include "GeneralKeyboardController.h"

class MovesListController: public GeneralKeyboardController {
public:
	MovesListController(GameMachine* gm) : GeneralKeyboardController(gm){};
	virtual ~MovesListController();
	void dispatchEvent(SDL_Event* e);
};

#endif /* MOVESLISTCONTROLLER_H_ */

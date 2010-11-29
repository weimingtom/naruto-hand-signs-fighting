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

#include "AbstractController.h"
#include "../GameMachine.h"

class MovesListController: public AbstractController {
public:
	MovesListController(GameMachine* gm) : AbstractController(gm){};
	virtual ~MovesListController();
	void dispatchEvent(SDL_Event* e);
};

#endif /* MOVESLISTCONTROLLER_H_ */

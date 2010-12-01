/*
 ******************************************************
 * NAME:
 * TrainingSectionController.h
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

#ifndef TRAININGSECTIONCONTROLLER_H_
#define TRAININGSECTIONCONTROLLER_H_

#include "AbstractController.h"

class TrainingSectionController: public AbstractController {
	void dispatchKeyboardEvent(SDL_Event* e);
public:
	TrainingSectionController(GameMachine* gm);
	virtual ~TrainingSectionController();

	void dispatchEvent(SDL_Event* e);
};

#endif /* TRAININGSECTIONCONTROLLER_H_ */

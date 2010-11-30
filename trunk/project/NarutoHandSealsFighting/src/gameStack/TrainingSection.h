/*
 ******************************************************
 * NAME:
 * TrainingSection.h
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

#ifndef TRAININGSECTION_H_
#define TRAININGSECTION_H_

#include "GameElement.h"
#include "controller/AbstractController.h"
#include "../gameLogic/Move.h"
#include "../gui/AbstractFactory.h"
#include "../gui/TrainingWindow.h"

class TrainingSection: public GameElement {
	AbstractController* trainingSectionController;
	Move* move;
	AbstractFactory* graphicWindow;
public:
	TrainingSection(Move* m, AbstractController* ctrl);
	virtual ~TrainingSection();
	void loopFunction();
};

#endif /* TRAININGSECTION_H_ */

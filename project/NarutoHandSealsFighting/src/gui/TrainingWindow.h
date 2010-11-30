/*
 ******************************************************
 * NAME:
 * TrainingWindow.h
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Nov 28, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#ifndef TRAININGWINDOW_H_
#define TRAININGWINDOW_H_

#include "MenuWindow.h"
#include "../gameLogic/MovesSet.h"

using namespace std;

class TrainingWindow: public MenuWindow {
	Move* move;
public:
	TrainingWindow(string targetMove);
	~TrainingWindow();
};

#endif /* TRAININGWINDOW_H_ */

/*
 ******************************************************
 * NAME:
 * TrainingWindow.cxx
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

#include "TrainingWindow.h"

TrainingWindow::TrainingWindow(string targetMove) : MenuWindow() {
	title = "TRAINING SECTION";
	move = movesSetGlobal->getMove(targetMove);
}

TrainingWindow::~TrainingWindow() {
	// TODO Auto-generated destructor stub
}

void buildWindow(){

}

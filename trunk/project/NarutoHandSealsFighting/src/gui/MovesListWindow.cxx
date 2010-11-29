/*
 ******************************************************
 * NAME:
 * MovesListWindow.cxx
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

#include "MovesListWindow.h"

MovesListWindow::MovesListWindow() : MenuWindow() {
	title = "MOVES LIST WINDOW";
}

MovesListWindow::~MovesListWindow() {
	// TODO Auto-generated destructor stub
}

void MovesListWindow::buildWindow(){
	buildTitle();
}

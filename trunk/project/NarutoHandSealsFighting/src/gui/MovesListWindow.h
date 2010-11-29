/*
 ******************************************************
 * NAME:
 * MovesListWindow.h
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

#ifndef MOVESLISTWINDOW_H_
#define MOVESLISTWINDOW_H_

#include "MenuWindow.h"

class MovesListWindow: public MenuWindow {
public:
	MovesListWindow();
	virtual ~MovesListWindow();
	void buildWindow();
};

#endif /* MOVESLISTWINDOW_H_ */

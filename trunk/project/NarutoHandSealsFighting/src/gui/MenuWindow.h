/*
 ******************************************************
 * NAME:
 * MenuWindow.h
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

#ifndef MENUWINDOW_H_
#define MENUWINDOW_H_

#include "AbstractFactory.h"

#define MENU_ELEMENT 5

class MenuWindow: public AbstractFactory {
public:
	MenuWindow();
	virtual ~MenuWindow();
	void buildWindow();
};

#endif /* MENUWINDOW_H_ */

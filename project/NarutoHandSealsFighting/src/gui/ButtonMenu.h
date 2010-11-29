/*
 ******************************************************
 * NAME:
 * ButtonMenu.h
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

#ifndef BUTTONMENU_H_
#define BUTTONMENU_H_

#include "AbstractGUIObject.h"

class ButtonMenu: public AbstractGUIObject {
	gcn::Button* button;

public:
	ButtonMenu(const char*, int xPos, int yPos );
	~ButtonMenu();
};


#endif /* BUTTONMENU_H_ */

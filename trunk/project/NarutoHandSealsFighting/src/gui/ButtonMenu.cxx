/*
 ******************************************************
 * NAME:
 * ButtonMenu.cxx
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

#include "ButtonMenu.h"

ButtonMenu::ButtonMenu(const char* name, int xPos, int yPos) : AbstractGUIObject(xPos, yPos) {
	button = new gcn::Button("Button");
}

ButtonMenu::~ButtonMenu() {
	// TODO Auto-generated destructor stub
}

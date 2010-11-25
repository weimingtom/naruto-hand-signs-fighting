/*
 ******************************************************
 * NAME:
 * MainMenu.h
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Nov 25, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#ifndef MAINMENU_H_
#define MAINMENU_H_

#include "MenuElement.h"

class MainMenu : public MenuElement{

public:
	MainMenu(AbstractController* ctrlI):MenuElement(ctrlI){};

	void displayMenuElement();

};

#endif /* MAINMENU_H_ */

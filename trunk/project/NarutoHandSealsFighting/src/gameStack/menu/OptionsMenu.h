/*
 ******************************************************
 * NAME:
 * OptionsMenu.h
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

#ifndef OPTIONSMENU_H_
#define OPTIONSMENU_H_

#include "MenuElement.h"
#include "../controller/AbstractController.h"
#include "../../gui/OptionsWindow.h"

class OptionsMenu : public MenuElement{

public:
	OptionsMenu(AbstractController* ctrlI) : MenuElement(ctrlI){
		elementGraphic = new OptionsWindow();
		elementGraphic->buildWindow();
	};
	void displayMenuElement();

};


#endif /* OPTIONSMENU_H_ */

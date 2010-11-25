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

class OptionsMenu : public MenuElement{

public:
	OptionsMenu(AbstractController* ctrlI):MenuElement(ctrlI){};
	void displayMenuElement();

};


#endif /* OPTIONSMENU_H_ */

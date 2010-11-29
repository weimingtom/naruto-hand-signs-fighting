/*
 ******************************************************
 * NAME:
 * MenuElement.cxx
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

#include "MenuElement.h"

void MenuElement::loopFunction(){
	SDL_Event event;
	if(SDL_PollEvent(&event)){
		controllerElement->dispatchEvent(&event);
		elementGraphic->getInput()->pushInput(event);
	}
	displayMenuElement();
}
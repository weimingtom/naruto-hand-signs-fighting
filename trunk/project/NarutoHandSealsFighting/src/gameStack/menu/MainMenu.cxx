/*
 ******************************************************
 * NAME:
 * MainMenu.cxx
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

#include "MainMenu.h"
#include <iostream>


//void MainMenu::loopFunction(){
//	SDL_Event event;
//	displayMenuElement();
//	if(SDL_PollEvent(&event))
//		mainMenuCtrl->dispatchEvent(&event);
//}

void MainMenu::displayMenuElement(){
//	cout<<"MainMenu::displayMainMenu\n";
	elementGraphic->display();
}

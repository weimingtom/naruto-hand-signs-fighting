/*
 ******************************************************
 * NAME:
 * MenuWindow.cxx
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

#include "../guichan-0.8.2/include/guichan.hpp"
#include "../guichan-0.8.2/include/guichan/sdl.hpp"
#include "../guichan-0.8.2/include/guichan/graphics.hpp"
#include "MenuWindow.h"
#include "myButtonListener.h"
#include "ButtonMenu.h"

#define MENU_ELEMENT 4

int buttonWidth = 150;
int buttonHeight = 30;
int distBetweenButtons = 30;
int titleHeight = 80;

const char* menuChar[MENU_ELEMENT] ={
		"Play",
		"Training Section",
		"Instructions",
		"Options"
};

const char* menuEventID[MENU_ELEMENT] = {
		"play",
		"training",
		"instructions",
		"options"
};

MenuWindow::MenuWindow() {
	// TODO Auto-generated constructor stub

}

MenuWindow::~MenuWindow() {
	// TODO Auto-generated destructor stub
}

void MenuWindow::buildWindow(){
	//Buildind menu
	gcn::Button* b;
	gcn::ActionListener* act = new MyButtonListener();
	gcn::Label *label = new gcn::Label("MAIN MENU");
	int xPos = screenWidth/2 - buttonWidth/2, yPos;

	label->setPosition(0,0);
	label->setDimension( gcn::Rectangle(0,0, screenWidth, titleHeight));
	label->setAlignment(gcn::Graphics::CENTER);

	yPos = label->getHeight() + 20;

	panel->add(label);
	for(int i=0; i < MENU_ELEMENT; i++){
		b = new gcn::Button(menuChar[i]);
		b->setDimension(gcn::Rectangle(0,0,buttonWidth, buttonHeight));
		b->setPosition(xPos, yPos);
		b->setActionEventId(menuEventID[i]);
		b->addActionListener(act);
		panel->add(b);

		yPos+= b->getHeight() + distBetweenButtons;
	}

}

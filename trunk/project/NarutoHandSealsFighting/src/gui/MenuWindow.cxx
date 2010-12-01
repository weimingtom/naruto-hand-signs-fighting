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

#include "guichan-0.8.2/include/guichan/graphics.hpp"
#include "MenuWindow.h"
#include "myButtonListener.h"
#include "EventToKeyPressConverter.h"


const char* menuChar[MENU_ELEMENT] ={
		"[P]lay",
		"[T]raining Section",
		"[I]nstructions",
		"[O]ptions",
		"[Q]uit"
};

const char* menuEventID[MENU_ELEMENT] = {
		"play",
		"training",
		"instructions",
		"options",
		"quit"
};

MenuWindow::MenuWindow() {
	title = "MAIN MENU";

	buttonWidth = 250;
	buttonHeight = 30;
	distBetweenButtons = 30;
	titleHeight = 80;
}

MenuWindow::~MenuWindow() {
	delete titleLabel;
	delete backButton;
}

void MenuWindow::buildTitle(){
	titleLabel = new gcn::Label(title);
	titleLabel->setPosition(0,0);
	titleLabel->setDimension( gcn::Rectangle(0,0, screenWidth, titleHeight));
	titleLabel->setAlignment(gcn::Graphics::CENTER);
	panel->add(titleLabel);
}

void MenuWindow::buildBackButton(){
	int backButtonWidth = buttonWidth/2, backButonHeight = buttonHeight/2;
	backButton = new gcn::Button("[B]ack");
	backButton->setDimension(gcn::Rectangle(0,0,backButtonWidth, backButonHeight));
	backButton->setPosition(screenWidth-backButtonWidth - 2, screenHeight - backButonHeight - 2 );
	backButton->setActionEventId("back");
	backButtonListener = new EventToKeyPressConverter();
	backButton->addActionListener(backButtonListener);
	panel->add(backButton);
}

void MenuWindow::buildWindow(){
	//Buildind menu
	gcn::Button* b;
	int xPos = screenWidth/2 - buttonWidth/2, yPos;
	gcn::ActionListener* act = new EventToKeyPressConverter();
	buildTitle();

	yPos = titleLabel->getHeight() + 20;

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

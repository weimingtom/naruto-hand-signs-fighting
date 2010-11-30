/*
 ******************************************************
 * NAME:
 * MovesListWindow.cxx
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Nov 29, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#include "MovesListWindow.h"
#include "../gameLogic/MovesFactory.h"

MovesListWindow::MovesListWindow(MovesSet* ms) : MenuWindow() {
	title = "MOVES LIST WINDOW";
	movesList = new MovesListModel(ms);
	buildTitle();
	buildBackButton();
	listBoxWidth = screenWidth - backButton->getWidth() - 20;
	listBoxHeight = screenHeight - titleLabel->getHeight() - 20;
}

MovesListWindow::~MovesListWindow() {
	delete listBox;
}

void MovesListWindow::buildWindow(){
//	buildTitle();
//	buildBackButton();

	listBox = new gcn::ListBox(movesList);
	listBox->setFrameSize(5);
	listBox->setSize(listBoxWidth, listBoxHeight);
	listBox->setPosition( 10 ,titleLabel->getHeight() + 10);
	listBox->adjustSize();
	panel->add(listBox);
}

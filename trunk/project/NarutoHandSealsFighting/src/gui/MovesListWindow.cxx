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
#include "MovesListListener.h"

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
	delete tryMove;
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


	tryMove = new gcn::Button("Start");
	int startWidth = backButton->getWidth();
	int startHeight = buttonHeight;
	tryMove->setSize(startWidth, startHeight);
	tryMove->setPosition(backButton->getX(), titleLabel->getY() + 30);
	tryMove->setActionEventId(TRAINING_EVENT_ID);
	tryMove->addActionListener(new MovesListListener(listBox));
	panel->add(tryMove);
}

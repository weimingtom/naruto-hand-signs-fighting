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
#include "MovesListBoxListener.h"

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
	delete listBoxScrollArea;
}

void MovesListWindow::buildWindow(){
//	buildTitle();
//	buildBackButton();

	listBox = new gcn::ListBox(movesList);
	listBox->setSize(listBoxWidth, listBoxHeight);
	listBox->adjustSize();
	//you know.. such as in music when you have to play different instruments...
	listBox->addFocusListener(new MovesListBoxListener());
	listBox->addSelectionListener(new MovesListBoxListener() );
	listBox->addActionListener(new MovesListBoxListener());
	listBoxScrollArea = new gcn::ScrollArea(listBox);
	listBoxScrollArea->setFrameSize(5);
	listBoxScrollArea->setSize(listBoxWidth, listBoxHeight);
	listBoxScrollArea->setPosition( 10 ,titleLabel->getHeight() + 10);
//	listBoxScrollArea->setFocusable(true);
	panel->add(listBoxScrollArea);


	tryMove = new gcn::Button("[S]tart");
	int startWidth = backButton->getWidth();
	int startHeight = buttonHeight;
	tryMove->setSize(startWidth, startHeight);
	tryMove->setPosition(backButton->getX(), titleLabel->getY() + 30);
	tryMove->setActionEventId(TRAINING_EVENT_ID);
	tryMove->addActionListener(new MovesListListener(listBox));
	panel->add(tryMove);
}

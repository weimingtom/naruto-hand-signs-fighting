/*
 ******************************************************
 * NAME:
 * TrainingWindow.cxx
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

#include <iostream>
#include <string>
#include <stdlib.h>
#include "TrainingWindow.h"
#include "../DebugPrint.h"

using namespace std;

TrainingWindow::TrainingWindow(string targetMove) : MenuWindow() {
	title = "TRAINING SECTION";
	move = movesSetGlobal->getMove(targetMove);
	oldScreenWidth = screenWidth;
	oldScreenHeight = screenHeight;
	screenWidth = TRAINING_WINDOW_WIDTH;
	screenHeight = TRAINING_WINDOW_HEIGHT;
	screen = SDL_SetVideoMode(screenWidth, screenHeight, 32, SDL_HWSURFACE);
	panel->setDimension(gcn::Rectangle(0,0, screenWidth, screenHeight));
	currentSealIndex = 0;
}

TrainingWindow::~TrainingWindow() {
	restoreOldSizeWindow();
	delete labelName;
	delete labelElement;
	delete labelRank;
	delete labelType;
	delete bigImageIcon;
	delete bigImageLabel;
	delete secondsLabel;
	delete shotButton;
	delete bottomRow;
	delete cameraWindow;
	for(int i=0; i< icoVector.size(); i++)
		delete icoVector.at(i);
	icoVector.clear();
}

void TrainingWindow::restoreOldSizeWindow(){
	screen = SDL_SetVideoMode(oldScreenWidth, oldScreenHeight, 32, SDL_HWSURFACE);
	panel->setDimension(gcn::Rectangle(0,0, oldScreenWidth, oldScreenHeight));
}

void TrainingWindow::buildWindow(){
	gcn::Image *image;
	int numberOfSeals = move->getMoveSeals().size();
	int distanceMoveDescription = 20;
	int x=10, y=0;
	string path = move->getMoveSeals().at(currentSealIndex)->getThumbnailImagePath();
	string type;
	buildBackButton();
	buildTitle();

	//Move Name:
	labelName = new gcn::Label("NAME: ");
//	y = titleLabel->getY() + titleLabel->getHeight() + 10;
	y = 10;
	labelName->setPosition(x, y);
	panel->add(labelName);
	moveName = new gcn::Label(move->getMoveName().c_str());
	moveName->setPosition(x + labelName->getWidth(), y);
	panel->add(moveName);


	//Move Element:
	labelElement = new gcn::Label("ELEMENT: ");
	y = labelName->getY() + distanceMoveDescription;
	labelElement->setPosition(x, y);
	panel->add(labelElement);
	moveElement = new gcn::Label(move->getElementStr().c_str());
	moveElement->setPosition(x+labelElement->getWidth(), y);
	panel->add(moveElement);

	//Move Rank:
	labelRank = new gcn::Label("RANK: ");
	y = labelElement->getY() + distanceMoveDescription;
	labelRank->setPosition(x, y);
	panel->add(labelRank);
	moveRank = new gcn::Label(move->getRankStr().c_str());
	moveRank->setPosition(x+labelRank->getWidth(), y);
	panel->add(moveRank);

	//Move type
	labelType = new gcn::Label("TYPE: ");
	y = labelRank->getY() + distanceMoveDescription;
	labelType->setPosition(x, y);
	panel->add(labelType);
	type = move->getType().japName + " - " +  move->getType().engName ;
	moveType = new gcn::Label(type.c_str());
	moveType->setPosition(x+labelType->getWidth(), y);
	panel->add(moveType);

	//Current Seal
	cout<<path<<"\n";
	image = gcn::Image::load(path);
	bigImageIcon = new gcn::Icon(image);
	bigImageIcon->setPosition(10,labelType->getY() + 60);
	panel->add(bigImageIcon);
	bigImageLabel = new gcn::Label("CURRENT SEAL");
	bigImageLabel->setPosition(bigImageIcon->getX() + (bigImageIcon->getWidth()/2) -
			(bigImageLabel->getWidth()/2),
			bigImageIcon->getY() - 20);
	panel->add(bigImageLabel);



	//Small Seals Thumbnails:
	gcn::Icon* ico;
	bottomRow = new gcn::Window("SEALS:");
	bottomRow->setPosition(10,screenHeight - 400);
	int bottomRowScrollWidth = screenWidth - 20;
	int bottomRowScrollHeight = 170;
	int brWidth = 0;
	//here the position is relative into the window
	x = 0;
	y = 0;
	//@BUG we mill the last ico image.... why??
	for(int i=0; i<move->getMoveSeals().size(); i++){
		debugPrint("reaching the image: %s\n",
				move->getMoveSeals().at(i)->getThumbnailImagePath().c_str());
		image = gcn::Image::load(move->getMoveSeals().at(i)->getThumbnailImagePath().c_str());
//		debugPrint("creating the ico\n");
		ico = new gcn::Icon(image);
		ico->setSize(130, 130);
		ico->setPosition(x,y);
		x += ico->getWidth() + 10;
		brWidth += ico->getWidth();
		icoVector.push_back(ico);
		debugPrint("adding to bottom row\n");
		bottomRow->add(ico);
	}
	if(brWidth < bottomRowScrollWidth)
		brWidth = bottomRowScrollWidth;
	bottomRow->setSize(brWidth + ico->getWidth(), 200);
	bottomRowScroll = new gcn::ScrollArea(bottomRow);
	bottomRowScroll->setHorizontalScrollPolicy( gcn::ScrollArea::SHOW_ALWAYS);
	bottomRowScroll->setVerticalScrollPolicy(gcn::ScrollArea::SHOW_NEVER);
	bottomRowScroll->setSize(bottomRowScrollWidth, bottomRowScrollHeight);
	bottomRowScroll->setPosition(10, screenHeight - bottomRowScroll->getHeight() - 10);
	panel->add(bottomRowScroll);

	//we position the back button away
	shotButton = new gcn::Button("SHOT!");
	shotButton->setPosition(bigImageIcon->getX(),
			bigImageIcon->getY() + bigImageIcon->getHeight() + 25);
	shotButton->setSize(bigImageIcon->getWidth(), buttonHeight + 20);
	shotButton->setFrameSize(3);
	panel->add(shotButton);

	backButton->setPosition(bigImageIcon->getX(),
			shotButton->getY() + shotButton->getHeight() + 15);

	//Camera Window:
	cameraWindow = new gcn::Window("Camera");
	cameraWindowWidth = screenWidth - (bigImageIcon->getWidth() + 40);
	cameraWindowHeight = screenHeight - (titleLabel->getHeight() + bottomRowScroll->getHeight() + 40);
	cameraWindowX = bigImageIcon->getX() + bigImageIcon->getWidth() + 20 ;
	cameraWindowY = titleLabel->getY() + titleLabel->getHeight() ;
	cameraWindow->setSize(cameraWindowWidth, cameraWindowHeight);
	cameraWindow->setPosition(cameraWindowX, cameraWindowY);
	cameraWindow->setMovable(false);
	panel->add(cameraWindow);

	//Seconds Label:
	secondsLabel = new gcn::Label("Seconds");
	secondsLabel->setPosition(cameraWindow->getX() + cameraWindow->getWidth()/2,
			cameraWindow->getY() + cameraWindow->getHeight() + 5);
	panel->add(secondsLabel);



//	delete image;
}

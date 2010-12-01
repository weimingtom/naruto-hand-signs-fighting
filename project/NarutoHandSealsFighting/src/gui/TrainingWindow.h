/*
 ******************************************************
 * NAME:
 * TrainingWindow.h
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

#ifndef TRAININGWINDOW_H_
#define TRAININGWINDOW_H_

#include <SDL/SDL.h>
#include <vector>
#include "MenuWindow.h"
#include "../gameLogic/MovesSet.h"

#define TRAINING_WINDOW_WIDTH 800
#define TRAINING_WINDOW_HEIGHT 600

using namespace std;

class TrainingWindow: public MenuWindow {
	Move* move;
	int	oldScreenWidth;
	int oldScreenHeight;

	////Move description///
	///////////////////////
	gcn::Label* moveName;
	gcn::Label* moveElement;
	gcn::Label* moveRank;
	gcn::Label* moveType;

	gcn::Label* labelName;
	gcn::Label* labelElement;
	gcn::Label* labelRank;
	gcn::Label* labelType;

	///// Thumbnails //////
	///////////////////////
	//Current Seal:
	gcn::Icon* bigImageIcon;
	std::vector<gcn::Icon*> icoVector;
	gcn::Label* bigImageLabel;

	//Small Thumbnails
	gcn::Label* secondsLabel;
	gcn::Window* bottomRow;
	gcn::ScrollArea* bottomRowScroll;

	gcn::Button* shotButton;

	//Camera input
	int cameraWindowWidth;
	int cameraWindowHeight;
	int cameraWindowX;
	int cameraWindowY;
	gcn::Window *cameraWindow;

	int currentSealIndex;

	void restoreOldSizeWindow();

public:
	TrainingWindow(string targetMove);
	~TrainingWindow();
	void buildWindow();

	void incrementCurrentSealIndex(){
		currentSealIndex++;
	}

	int getCurrentSealIndex() const
    {
        return currentSealIndex;
    }

    void setCurrentSealIndex(int currentSealIndex)
    {
        this->currentSealIndex = currentSealIndex;
    }

};

#endif /* TRAININGWINDOW_H_ */

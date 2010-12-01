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
#include "EventToKeyPressConverter.h"
#include "../acquisitionSection/Camera.h"

#define TRAINING_WINDOW_WIDTH 800
#define TRAINING_WINDOW_HEIGHT 600

using namespace std;

class TrainingWindow: public MenuWindow {
	Move* move;
	int	oldScreenWidth;
	int oldScreenHeight;
    gcn::Label *moveName;
    gcn::Label *moveElement;
    gcn::Label *moveRank;
    gcn::Label *moveType;
    gcn::Label *labelName;
    gcn::Label *labelElement;
    gcn::Label *labelRank;
    gcn::Label *labelType;
    gcn::Icon *bigImageIcon;
    std::vector<gcn::Icon*> icoVector;
    gcn::Label *bigImageLabel;
    gcn::Label *secondsLabel;
    gcn::Window *bottomRow;
    gcn::ScrollArea *bottomRowScroll;
    gcn::Button *shotButton;
    int cameraWindowWidth;
    int cameraWindowHeight;
    int cameraWindowX;
    int cameraWindowY;
    gcn::Window *cameraWindow;
    int currentSealIndex;
    Camera *cam;
public:
    TrainingWindow(string targetMove);
    ~TrainingWindow();
    void buildWindow();
    void restoreOldSizeWindow();
    gcn::Window *getCameraWindow() const
    {
        return cameraWindow;
    }

    int getCameraWindowHeight() const
    {
        return cameraWindowHeight;
    }

    int getCameraWindowWidth() const
    {
        return cameraWindowWidth;
    }

    int getCameraWindowX() const
    {
        return cameraWindowX;
    }

    int getCameraWindowY() const
    {
        return cameraWindowY;
    }

    void setCameraWindowWidth(int cameraWindowWidth)
    {
        this->cameraWindowWidth = cameraWindowWidth;
    }

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

class ResizingListener : public EventToKeyPressConverter{
	TrainingWindow* trainingWindow;
public:
	ResizingListener(TrainingWindow* tw){
		trainingWindow = tw;
	}
	void action(const gcn::ActionEvent& actionEvent);
};

#endif /* TRAININGWINDOW_H_ */

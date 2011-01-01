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
#include <SDL/SDL_image.h>
#include <SDL/SDL_types.h>
#include <opencv/cv.h>
#include <opencv/cxcore.h>
#include <vector>
#include <iostream>
#include <string>

#include "MenuWindow.h"
#include "EventToKeyPressConverter.h"
#include "../gameLogic/MovesSet.h"
#include "../acquisitionSection/Camera.h"

#define TRAINING_WINDOW_WIDTH 1024
#define TRAINING_WINDOW_HEIGHT 690

using namespace std;

class TrainingWindow: public MenuWindow {
	Move* move;
	Camera* cam;

	int	oldScreenWidth;
	int oldScreenHeight;

	//Move description
	gcn::Label *moveTitle;
    gcn::Label *moveName;
    gcn::Label *moveElement;
    gcn::Label *moveRank;
    gcn::Label *moveType;
    gcn::Label *labelName;
    gcn::Label *labelElement;
    gcn::Label *labelRank;
    gcn::Label *labelType;

    //Seals:
    //Current Seal
    gcn::Icon *bigImageIcon;
    gcn::Image *bigImage;
    std::vector<gcn::Icon*> icoVector;
    gcn::Label *bigImageLabel;

    //Thumbnail seals in the bottom row
    gcn::Window *bottomRow;
    gcn::ScrollArea *bottomRowScroll;

    //Shot Button
    gcn::Button *shotButton;

    //Seconds Label
    int seconds;
    gcn::Label *secondsLabel;
    gcn::Label *secondsTitle;

    //Scores box
    gcn::TextBox* scoresBox;
    gcn::ScrollArea* scoresBoxScroll;
    gcn::Label *actualScoreTitle;
    gcn::Label *actualScoreLabel;
    double scores;
    double totalScore;
    double actualScore;

    //Camera
    int cameraWindowWidth;
    int cameraWindowHeight;
    int cameraWindowX;
    int cameraWindowY;
    gcn::Window *cameraWindow;
    gcn::Icon* cameraIcon;
    gcn::Image* cameraImage;

    int currentSealIndex;

    //Contours of the track in the camera window:
    IplImage*	g_gray;
    int		g_thresh;
    CvMemStorage* 	g_storage;
    CvSeq* contours;

    void buildMoveDescription(int x, int y);
    void buildCameraWindow();
    void buildBottomRow(int x, int y);
    void buildShotButton();
    void translateTitleLabel();
    void buildScoresBox();
    void buildTimerLabel();

    void createTemplateContours();

    //Camera Functions Facilities
    gcn::Image* convertIplImageToGcnImage(IplImage* iplImage);
    SDL_Surface* ipl_to_surface (IplImage *opencvimg);

public:

    TrainingWindow(string targetMove);
    ~TrainingWindow();
    void buildWindow();
    void restoreOldSizeWindow();
    void display();

    void updateScore(double scores);
    void setTotalScore(double score);

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

    void incrementCurrentSealIndex();

	int getCurrentSealIndex() const
    {
        return currentSealIndex;
    }

    void setCurrentSealIndex(int currentSealIndex)
    {
        this->currentSealIndex = currentSealIndex;
    }

    int getSeconds(){
    	return seconds;
    }

    void setSeconds(int sec){
    	seconds = sec;
    }

    void setActualScore(double actScore){
    	actualScore = actScore;
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

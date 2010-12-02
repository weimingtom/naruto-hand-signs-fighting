/*
 ******************************************************
 * NAME:
 * TrainingSection.cxx
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Nov 30, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#include "TrainingSection.h"

static const char* CAMERA_WINDOW = "Camera";

TrainingSection::TrainingSection(Move* m, AbstractController* ctrl){
	TrainingWindow* trwin = (TrainingWindow*) graphicWindow;
	trainingSectionController = ctrl;
	move = m;
	graphicWindow = new TrainingWindow(m->getMoveName());
	graphicWindow->buildWindow();
	((TrainingSectionController*)trainingSectionController)->setTrainingWindow(
			(TrainingWindow*)graphicWindow);
	enabledCameraWindow = -1;
//	cam = Camera::getCameraInstance();
}

TrainingSection::~TrainingSection() {
	cvDestroyWindow(CAMERA_WINDOW);
}

void TrainingSection::openOpenCVWindow(){
	enabledCameraWindow = cvNamedWindow( CAMERA_WINDOW, CV_WINDOW_AUTOSIZE );
//	cvMoveWindow(CAMERA_WINDOW, graphicWindow->getCameraWindowX(), graphicWindow->getCameraWindowY());
//	cvResizeWindow(CAMERA_WINDOW, graphicWindow->getCameraWindowWidth(),
//			graphicWindow->getCameraWindowHeight());
	cvMoveWindow(CAMERA_WINDOW, 800, 200);
	cvResizeWindow(CAMERA_WINDOW, 220, 150);
}

void TrainingSection::loopFunction(){
	SDL_Event event;
	if(SDL_PollEvent(&event)){
		trainingSectionController->dispatchEvent(&event);
		graphicWindow->getInput()->pushInput(event);
	}
//	if(enabledCameraWindow<0)
//		openOpenCVWindow();
//	if(cam->capturing() < 0){
//		cout<<"camera problem!!\n";
//	}
//	cvShowImage(CAMERA_WINDOW, cam->getFrame());
	graphicWindow->display();

}

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

TrainingSection::TrainingSection(Move* m, AbstractController* ctrl){
	TrainingWindow* trwin = (TrainingWindow*) graphicWindow;
	trainingSectionController = ctrl;
	move = m;
	graphicWindow = new TrainingWindow(m->getMoveName());
	graphicWindow->buildWindow();
	((TrainingSectionController*)trainingSectionController)->setTrainingWindow(
			(TrainingWindow*)graphicWindow);
	cam = Camera::getCameraInstance();
	cam->setCapture(cvCaptureFromCAM( CV_CAP_ANY ));
	enabledCameraWindow = -1;
	openOpenCVWindow();
}

TrainingSection::~TrainingSection() {
	cvDestroyWindow(CAMERA_WINDOW);
}

void TrainingSection::openOpenCVWindow(){
	enabledCameraWindow = cvNamedWindow( CAMERA_WINDOW, CV_WINDOW_AUTOSIZE );
	cvMoveWindow(CAMERA_WINDOW, graphicWindow->getCameraWindowX(), graphicWindow->getCameraWindowY());
//	cvResizeWindow(CAMERA_WINDOW, graphicWindow->getCameraWindowWidth(),
//			graphicWindow->getCameraWindowHeight());
}

void TrainingSection::loopFunction(){
	SDL_Event event;
//	if(enabledCameraWindow<0)
//		openOpenCVWindow();
	if(SDL_PollEvent(&event)){
		trainingSectionController->dispatchEvent(&event);
		graphicWindow->getInput()->pushInput(event);
	}
	if(cam->capturing() < 0){
		cout<<"camera problem!!\n";
	}
	cvShowImage(CAMERA_WINDOW, cam->getFrame());
	graphicWindow->display();

}

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

	trainingSectionController = ctrl;
	move = m;

	graphicWindow = new TrainingWindow(m->getMoveName());
	TrainingWindow* trwin = (TrainingWindow*) graphicWindow;
	graphicWindow->buildWindow();

	TrainingSectionController* trainingSectionCtrl = (TrainingSectionController*) ctrl;
	trainingSectionCtrl->setTrainingWindow(trwin);

	trainingSectionCtrl->setDirector(new TrainingDirector(trwin, recognitionEngine, cam, m));

}

TrainingSection::~TrainingSection() {
}

void TrainingSection::loopFunction(){
	SDL_Event event;
	if(SDL_PollEvent(&event)){
		trainingSectionController->dispatchEvent(&event);
		graphicWindow->getInput()->pushInput(event);
	}
	graphicWindow->display();

}

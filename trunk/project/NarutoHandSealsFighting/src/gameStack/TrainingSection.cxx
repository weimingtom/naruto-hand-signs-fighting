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

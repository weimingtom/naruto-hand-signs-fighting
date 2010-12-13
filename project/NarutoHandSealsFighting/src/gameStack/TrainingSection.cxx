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
#include "../DebugPrint.h"

static const char* CAMERA_WINDOW = "Camera";

TrainingSection::TrainingSection(Move* m, AbstractController* ctrl){
//	debugPrint("TrainingSection constructor\ncamera? %s\n", cam->getPiggyBackCamera());
	trainingSectionController = ctrl;
	move = m;
	graphicWindow = new TrainingWindow(m->getMoveName());
	graphicWindow->buildWindow();

	TrainingWindow* trwin = (TrainingWindow*) graphicWindow;
	TrainingSectionController* trainingSectionCtrl = (TrainingSectionController*) ctrl;
	trainingSectionCtrl->setTrainingWindow(trwin);
	trainingSectionCtrl->setDirector(new TrainingDirector(trwin,recognitionEngine, cam, m));
}

TrainingSection::~TrainingSection() {
//	debugPrint("TrainingSection destructor\n");
	delete graphicWindow;
	delete trainingSectionController;
}

void TrainingSection::loopFunction(){
	SDL_Event event;
	if(SDL_PollEvent(&event)){
		trainingSectionController->dispatchEvent(&event);
		graphicWindow->getInput()->pushInput(event);
	}
	graphicWindow->display();

}

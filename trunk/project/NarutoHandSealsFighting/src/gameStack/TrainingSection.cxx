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

const int PHYS_SAMPLING_STEP= 80; // ms simulated by a physic step
unsigned int nstep=0; //physics steps
bool beginning;

// Frames Per Seconds
const int FPS_SAMPLING = 1500; // fps length
float fpsPrec=0; // precedent fps value
int fpsNow=0; // actual fps value
Uint32 timeLastInterval=0;
Uint32 timeNow;

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
	nstep = 0;
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
	//IDLE
	timeNow=SDL_GetTicks();


	if (timeLastInterval+FPS_SAMPLING<timeNow) {
		fpsPrec = 1000.0*((float)fpsNow) /(timeNow-timeLastInterval);
		fpsNow=0;
		timeLastInterval = timeNow;
	}

	bool doneSomething=false;
	int guard=0;

	//While the simulated time is back respect to the real time
	//we run
	while (nstep*PHYS_SAMPLING_STEP < timeNow ) {
		nstep++;
		doneSomething=true;
		timeNow=SDL_GetTicks();
		if (guard++>1000) {
			// we are too slow...
			graphicWindow->display();
			break;
		}
	}

	if (doneSomething){
		graphicWindow->display();
		fpsNow++;
	}else {
		// free time!!!

	}

}

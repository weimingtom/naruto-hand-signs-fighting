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
#include <iostream>
#include <unistd.h>
#include "../DebugPrint.h"

using namespace std;

static const char* CAMERA_WINDOW = "Camera";
static double actualScore = 0;

const int PHYS_SAMPLING_STEP= 80; // ms simulated by a physic step
unsigned int nstep=0; //physics steps
bool beginning;

// Frames Per Seconds
const int FPS_SAMPLING = 15000; // fps length
float fpsPrec=0; // precedent fps value
int fpsNow=0; // actual fps value
Uint32 timeLastInterval=0;
Uint32 timeNow;

// Refresh actual score ratio
const int REFRESH_SCORE_FPS_RATIO = 3;


TrainingSection::TrainingSection(Move* m, AbstractController* ctrl){
//	debugPrint("TrainingSection constructor\ncamera? %s\n", cam->getPiggyBackCamera());
	trainingSectionController = ctrl;
	move = m;
	graphicWindow = new TrainingWindow(m->getMoveName());
	graphicWindow->buildWindow();

	TrainingWindow* trwin = (TrainingWindow*) graphicWindow;
	TrainingSectionController* trainingSectionCtrl = (TrainingSectionController*) ctrl;
	trainingSectionCtrl->setTrainingWindow(trwin);
	director = new TrainingDirector(trwin,recognitionEngine, cam, m);
	trainingSectionCtrl->setDirector(director);
	nstep = 0;
}

TrainingSection::~TrainingSection() {
//	debugPrint("TrainingSection destructor\n");
	delete graphicWindow;
	delete trainingSectionController;
}

void TrainingSection::loopFunction(){
	SDL_Event event;
//	if(pidt == 0)
	{
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
			if( fpsNow % REFRESH_SCORE_FPS_RATIO == 0){
				actualScoreFunction();
				graphicWindow->setActualScore( (double) actualScore );
//				cout<<"refresh actualScore\n";
			}
			graphicWindow->display();
			fpsNow++;
//			cout<<"fpsNow: "<<fpsNow<<"\n";
		}else {
			// free time!!!

		}
//	}else{
//		actualScoreFunction();
	}

}

void TrainingSection::actualScoreFunction(){
	actualScore = director->processActualScore();
	cout<<"actualScore:"<<actualScore<<"\n";

}

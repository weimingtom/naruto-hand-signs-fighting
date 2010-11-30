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
	trainingSectionController = ctrl;
	move = m;
	graphicWindow = new TrainingWindow(m->getMoveName());
}

TrainingSection::~TrainingSection() {
	// TODO Auto-generated destructor stub
}

void TrainingSection::loopFunction(){
	SDL_Event event;
	if(SDL_PollEvent(&event)){
		trainingSectionController->dispatchEvent(&event);
		graphicWindow->getInput()->pushInput(event);
	}
	graphicWindow->display();
}

/*
 ******************************************************
 * NAME:
 * MenuElement.cxx
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Nov 25, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#include "MenuElement.h"
#include "../../DebugPrint.h"

const int PHYS_SAMPLING_STEP=30; // ms simulated by a physic step
unsigned int nstep=0; //physics steps

// Frames Per Seconds
const int FPS_SAMPLING = 1500000; // fps length
float fpsPrec=0; // precedent fps value
int fpsNow=0; // actual fps value
Uint32 timeLastInterval=0;
Uint32 timeNow;

void MenuElement::loopFunction(){
	SDL_Event event;
	if(SDL_PollEvent(&event)){
		controllerElement->dispatchEvent(&event);
		elementGraphic->getInput()->pushInput(event);
	}
	else {
		//IDLE

		timeNow=SDL_GetTicks();

		if (timeLastInterval+FPS_SAMPLING<timeNow) {
			fpsPrec = 1000.0*((float)fpsNow) /(timeNow-timeLastInterval);
			fpsNow=0;
			timeLastInterval = timeNow;
		}

		bool doneSomething=false;

		//While the simulated time is back respect to the real time
		//we run
		while (nstep*PHYS_SAMPLING_STEP < timeNow ) {
			nstep++;
			doneSomething=true;
			timeNow=SDL_GetTicks();
		}

		if (doneSomething){
			displayMenuElement();
			fpsNow++;
		}else {
			// free time!!!

		}
	}
}

MenuElement::~MenuElement(){
//	debugPrint("menuElement destructor\n");
	delete controllerElement;
	delete elementGraphic;
}

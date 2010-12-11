/*
 ******************************************************
 * NAME:
 * CountdownTimer.cxx
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Dec 3, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */
#include <stdio.h>
#include "CountdownTimer.h"
#include "../../gameStack/TrainingDirector.h"

Uint32 countdownFunction(Uint32 interval, void* pointer);

SDL_TimerID UNSET_TIMER = NULL;

CountdownTimer::~CountdownTimer() {
	// TODO Auto-generated destructor stub
}

CountdownTimer::CountdownTimer(TrainingWindow* tw): TimerNHSF(0, countdownFunction){
	trainingWindow = tw;
	timerID = UNSET_TIMER;
}


int CountdownTimer::countDown(int sec){
	if(timerID == UNSET_TIMER){
		seconds = sec;
		return startTimer();
	}else{
		return -1;
	}

}

void CountdownTimer::unsetTimerID(){
	timerID = UNSET_TIMER;
}

Uint32 countdownFunction(Uint32 interval, void* pointer){
	CountdownTimer* t = (CountdownTimer*)pointer;

	t->setSeconds(t->getSeconds() - 1);
//	cout<<"countdown: "<<t->getSeconds()<<"\n"; fflush(stdout);
	t->getTrainingWindow()->setSeconds(t->getSeconds());
	if(t->getSeconds() == 0){
//		cout<<"elapsed timer\n";
		t->unsetTimerID();
//		trainingDirector->elapsedTimer();

		//In order to de-coupling the Timer from a director we send a
		//new SDL_Event that have to be collected by a listener or a
		//controller. In our case will be the TrainingSectionController
		//!!!Warning!!!
		//take care about what controller is still running in the main loop! ;)
		SDL_Event sdlEvent;
		sdlEvent.type = SDL_KEYDOWN;
		//we need a symbol difficult to reproduce by the keyboard
		sdlEvent.key.keysym.sym = SDLK_ASTERISK; //<- what do you thing about that?
		SDL_PushEvent(&sdlEvent);
		return 0;
	}
	return 1000;
}

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
		trainingDirector->elapsedTimer();
		return 0;
	}
	return 1000;
}

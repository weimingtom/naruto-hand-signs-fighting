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

CountdownTimer::~CountdownTimer() {
	// TODO Auto-generated destructor stub
}

CountdownTimer::CountdownTimer(TrainingWindow* tw): TimerNHSF(0, countdownFunction){
	trainingWindow = tw;
}


int CountdownTimer::countDown(int sec){
	seconds = sec;
	return startTimer();
}

Uint32 countdownFunction(Uint32 interval, void* pointer){
	CountdownTimer* t = (CountdownTimer*)pointer;

	t->setSeconds(t->getSeconds() - 1);
//	cout<<"countdown: "<<t->getSeconds()<<"\n"; fflush(stdout);
	t->getTrainingWindow()->setSeconds(t->getSeconds());
	if(t->getSeconds() == 0){
//		cout<<"elapsed timer\n";
		trainingDirector->elapsedTimer();
		return 0;
	}
	return 1000;
}

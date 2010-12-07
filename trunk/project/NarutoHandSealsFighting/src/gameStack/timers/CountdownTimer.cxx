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

Uint32 countdownFunction(Uint32 interval, void* pointer);

CountdownTimer::~CountdownTimer() {
	// TODO Auto-generated destructor stub
}

CountdownTimer::CountdownTimer(): TimerNHSF(0, countdownFunction){
}

CountdownTimer::CountdownTimer(Uint32 delay, SDL_NewTimerCallback callbackFunc) :
		TimerNHSF(delay, callbackFunc){
}

int CountdownTimer::countDown(int sec){
	seconds = sec;
//	timerID = SDL_AddTimer(0, timerCallback, this);
	return startTimer();
}

//Uint32 callbackFunction(Uint32 interval, void* pointer){
//	CountdownTimer* t = (CountdownTimer*)pointer;
//	seconds--;
//	cout<<"countdown: "<<seconds<<"\n";
//}

Uint32 countdownFunction(Uint32 interval, void* pointer){
	CountdownTimer* t = (CountdownTimer*)pointer;

	t->setSeconds(t->getSeconds() - 1);
	cout<<"countdown: "<<t->getSeconds()<<"\n"; fflush(stdout);
	if(t->getSeconds() == 0){
		cout<<"elapsed timer\n";
		return 0;
	}
	return 1000;
}

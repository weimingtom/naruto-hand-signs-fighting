/*
 ******************************************************
 * NAME:
 * TimerNHSF.cxx
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

#include "TimerNHSF.h"

TimerNHSF::TimerNHSF(Uint32 delay, SDL_NewTimerCallback callback){
	initVariables();
	delayInterval = delay;
	timerCallback = callback;
}

TimerNHSF::~TimerNHSF() {
	SDL_RemoveTimer(timerID);
}

void TimerNHSF::setCallbackFunction(SDL_NewTimerCallback callbakcFun){
	timerCallback = callbakcFun;
}

int TimerNHSF::startTimer(){
	if(timerCallback != NULL){
		timerID = SDL_AddTimer(delayInterval, timerCallback, this);
		return 1;
	}
	else{
		cout<<"ERROR: TimerNHSF::uninitialized timerCallback\n";
		return -1;
	}
}

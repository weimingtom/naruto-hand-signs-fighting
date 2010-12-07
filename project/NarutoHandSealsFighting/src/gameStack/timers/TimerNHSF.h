/*
 ******************************************************
 * NAME:
 * TimerNHSF.h
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

#ifndef TIMERNHSF_H_
#define TIMERNHSF_H_

#include <SDL/SDL.h>
#include <SDL/SDL_timer.h>
#include <SDL/SDL_types.h>
#include <iostream>

//typedef Uint32 (*SDL_TimerCallback)(Uint32 interval);
typedef Uint32 (*SDL_NewTimerCallback)(Uint32 interval, void* pointer);

using namespace std;

class TimerNHSF {

protected:
	Uint32 delayInterval;
	SDL_TimerID timerID;
	SDL_NewTimerCallback timerCallback;

	//Each new specialized timer that inherits from this class
	//must implement its specific callback function
//	virtual Uint32 callbackFunction(Uint32 interval, void* pointer) = 0;

private:
	void initVariables(){
		timerID = NULL;
		timerCallback = NULL;
		delayInterval = 0;
	}

protected:
	TimerNHSF(){
		initVariables();
	}

public:
	TimerNHSF(Uint32 delay, SDL_NewTimerCallback callback);
	virtual ~TimerNHSF();

	void setCallbackFunction(SDL_NewTimerCallback callbakcFunction);
	int startTimer();

};

#endif /* TIMERNHSF_H_ */

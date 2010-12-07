/*
 ******************************************************
 * NAME:
 * CountdownTimer.h
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

#ifndef COUNTDOWNTIMER_H_
#define COUNTDOWNTIMER_H_

#include "TimerNHSF.h"

class CountdownTimer : public TimerNHSF {
	int seconds;

public:

	CountdownTimer();
	CountdownTimer(Uint32 delay ,SDL_NewTimerCallback callbackFunction);
	virtual ~CountdownTimer();

	//inherited from TimerNHSF.h
//	friend Uint32 callbackFunction(Uint32 interval, void* pointer);

	int countDown(int sec);

    int getSeconds() const
    {
        return seconds;
    }

    void setSeconds(int seconds)
    {
        this->seconds = seconds;
    }

};

#endif /* COUNTDOWNTIMER_H_ */

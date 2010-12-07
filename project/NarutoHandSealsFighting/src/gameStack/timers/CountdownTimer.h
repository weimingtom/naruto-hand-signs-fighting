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
#include "../../gui/TrainingWindow.h"

class CountdownTimer : public TimerNHSF {
	int seconds;
	TrainingWindow* trainingWindow;

public:

	CountdownTimer(TrainingWindow* trainingWindow);
	virtual ~CountdownTimer();
    int countDown(int sec);
    TrainingWindow *getTrainingWindow() const
    {
        return trainingWindow;
    }

    void setTrainingWindow(TrainingWindow *trainingWindow)
    {
        this->trainingWindow = trainingWindow;
    }

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

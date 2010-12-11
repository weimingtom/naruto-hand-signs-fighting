/*
 ******************************************************
 * NAME:
 * TrainingDirector.h
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Dec 1, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#ifndef TRAININGDIRECTOR_H_
#define TRAININGDIRECTOR_H_

#include <SDL/SDL_timer.h>
#include "../recognitionEngine/RecognitionEngine.h"
#include "../gui/TrainingWindow.h"
#include "../acquisitionSection/Camera.h"
#include "timers/CountdownTimer.h"

using namespace std;

class TrainingDirector {
    TrainingWindow *trainingWindow;
    RecognitionEngine *recognitionEngine;
//    Camera *cam;
    Move *targetMove;
    CountdownTimer *timer;

    double totalScore;

    bool lastSealInMove();

public:
    TrainingDirector(TrainingWindow *tw, RecognitionEngine *re, Camera *c, Move *m);
    virtual ~TrainingDirector();
    void handleShot(int seconds, int sealIndex);

    void elapsedTimer();


    CountdownTimer *getTimer() const
    {
        return timer;
    }

//    Camera *getCam() const
//    {
//        return cam;
//    }
//
//    void setCam(Camera *cam)
//    {
//        this->cam = cam;
//    }

    void setRecognitionEngine(RecognitionEngine *recognitionEngine)
    {
        this->recognitionEngine = recognitionEngine;
    }

    void setTimer(CountdownTimer *timer)
    {
        this->timer = timer;
    }

    void setTrainingWindow(TrainingWindow *trainingWindow)
    {
        this->trainingWindow = trainingWindow;
    }

    Move *getTargetMove() const
    {
        return targetMove;
    }

    void setTargetMove(Move *targetMove)
    {
        this->targetMove = targetMove;
    }

};

//extern TrainingDirector* trainingDirector;

#endif /* TRAININGDIRECTOR_H_ */

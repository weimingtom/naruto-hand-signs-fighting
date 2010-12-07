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
	TrainingWindow* trainingWindow;
	RecognitionEngine* recognitionEngine;
	Camera* cam;
	Move* targetMove;
	CountdownTimer* timer;

public:
	TrainingDirector(TrainingWindow* tw, RecognitionEngine* re, Camera* c, Move* m);
	virtual ~TrainingDirector();

	void handleShot(int seconds, int sealIndex);

	//Used by the timer
	void fire();
};

#endif /* TRAININGDIRECTOR_H_ */

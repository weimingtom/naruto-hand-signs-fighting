/*
 ******************************************************
 * NAME:
 * TrainingDirector.cxx
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

#include <iostream>
#include <stdio.h>
#include "TrainingDirector.h"

TrainingDirector* trainingDirector;

TrainingDirector::TrainingDirector(TrainingWindow* tw, RecognitionEngine* re, Camera* c, Move* m){
	trainingWindow = tw;
	recognitionEngine = re;
	cam = c;
	targetMove = m;
}

TrainingDirector::~TrainingDirector() {
	// TODO Auto-generated destructor stub
}

void TrainingDirector::handleShot(int seconds, int sealIndex){
	timer = new CountdownTimer(trainingWindow);
	timer->countDown(15);
}

void TrainingDirector::elapsedTimer(){
	cout<<"elapsed timer!\n";
}

/*
 ******************************************************
 * NAME:
 * TrainingSection.h
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Nov 30, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#ifndef TRAININGSECTION_H_
#define TRAININGSECTION_H_

#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv/cvaux.h>

#include "GameElement.h"
#include "../gameLogic/Move.h"
#include "../gui/AbstractFactory.h"
#include "../gui/TrainingWindow.h"
#include "../acquisitionSection/Camera.h"
#include "../recognitionEngine/RecognitionEngine.h"
#include "controller/AbstractController.h"
#include "controller/TrainingSectionController.h"
#include "TrainingDirector.h"
//Look... this isn't a god class... she only knows a lot of things.... ;)


class TrainingSection: public GameElement {
	AbstractController* trainingSectionController;
	Move* move;
	TrainingWindow* graphicWindow;
	TrainingDirector *director;

	int pidt;

	void actualScoreFunction();

public:
	TrainingSection(Move* m, AbstractController* ctrl);
	virtual ~TrainingSection();
	void loopFunction();
};

#endif /* TRAININGSECTION_H_ */

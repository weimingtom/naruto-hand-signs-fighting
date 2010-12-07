/*
 ******************************************************
 * NAME:
 * TrainingSectionController.h
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

#ifndef TRAININGSECTIONCONTROLLER_H_
#define TRAININGSECTIONCONTROLLER_H_

#include "AbstractController.h"
#include "../../gui/TrainingWindow.h"
#include "../TrainingDirector.h"

class TrainingSectionController: public AbstractController {
	TrainingWindow* trainingWindow;
	TrainingDirector* director;

	void dispatchKeyboardEvent(SDL_Event* e);

public:
	TrainingSectionController(GameMachine* gm);
	virtual ~TrainingSectionController();

	void dispatchEvent(SDL_Event* e);
    TrainingDirector *getDirector() const
    {
        return director;
    }

    void setDirector(TrainingDirector *director)
    {
        this->director = director;
    }

    TrainingWindow *getTrainingWindow() const
    {
        return trainingWindow;
    }

    void setTrainingWindow(TrainingWindow *trainingWindow)
    {
        this->trainingWindow = trainingWindow;
    }

};

#endif /* TRAININGSECTIONCONTROLLER_H_ */

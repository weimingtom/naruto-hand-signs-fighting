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

class TrainingSectionController: public AbstractController {
	TrainingWindow* trainingWindow;
	void dispatchKeyboardEvent(SDL_Event* e);
public:
	TrainingSectionController(GameMachine* gm);
	virtual ~TrainingSectionController();

	void dispatchEvent(SDL_Event* e);
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

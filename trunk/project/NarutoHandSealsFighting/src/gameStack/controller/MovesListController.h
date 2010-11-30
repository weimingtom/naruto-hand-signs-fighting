/*
 ******************************************************
 * NAME:
 * MovesListController.h
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Nov 29, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#ifndef MOVESLISTCONTROLLER_H_
#define MOVESLISTCONTROLLER_H_

#include "GeneralKeyboardController.h"
#include "../controller/TrainingSectionController.h"
#include "../TrainingSection.h"
#include "../../gameLogic/MovesSet.h"
#include "../GameMachine.h"

class MovesListController: public GeneralKeyboardController {
	std::string targetMove;
public:
	MovesListController(GameMachine* gm) : GeneralKeyboardController(gm){};
	virtual ~MovesListController();
	void dispatchEvent(SDL_Event* e);

    std::string getTargetMove() const
    {
        return targetMove;
    }

    void setTargetMove(std::string targetMove)
    {
        this->targetMove = targetMove;
    }

};

extern MovesListController* movesListController_Kagi;

#endif /* MOVESLISTCONTROLLER_H_ */

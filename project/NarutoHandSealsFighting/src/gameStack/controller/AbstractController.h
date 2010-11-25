/*
 ******************************************************
 * NAME:
 * AbstractController.h
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Nov 25, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#ifndef ABSTRACTCONTROLLER_H_
#define ABSTRACTCONTROLLER_H_

#include <SDL/SDL.h>
#include "../GameMachine.h"

class AbstractController{
protected:
	GameMachine* gameMachine;

public:
	AbstractController(GameMachine* gm){
		gameMachine = gm;
	}
	virtual void dispatchEvent(SDL_Event* e) = 0;

    GameMachine *getGameMachine() const
    {
        return gameMachine;
    }

    void setGameMachine(GameMachine *gameMachine)
    {
        this->gameMachine = gameMachine;
    }

};


#endif /* ABSTRACTCONTROLLER_H_ */

/*
 ******************************************************
 * NAME:
 * GameElement.h
 ******************************************************
 * DESCRIPTION:
 *
 * PATTERN: State Pattern
 * A GameElement is a portion of the game in the sense
 * that it provides the specific function to insert in
 * the "main loop" of the application in order to
 * accomplish a feature.
 * In this way for example the menu element will
 * display a textual menu, instead a game element will
 * probably launch the main function of the application.
 *
 * GameElement is a pure virtual class that defines the
 * mandatory method:
 *    virtual void loopFunction() = 0;
 * that every game module must implement.
 *
 * Remember that GameElement[s] alone are not sufficient
 * to run the game, so one needs a GameMachine able to
 * collect and manage them.
 *
 ******************************************************
 *	Created on: Nov 25, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#ifndef GAMEELEMENT_H_
#define GAMEELEMENT_H_

#include <SDL/SDL.h>
#include "../DebugPrint.h"

using namespace std;

class GameElement {

public:
	virtual ~GameElement(){
//		debugPrint("GameElement destructor\n");
	}
	virtual void loopFunction() = 0;
};


#endif /* GAMEELEMENT_H_ */

/*
 ******************************************************
 * NAME:
 * AbstractGUIObject.h
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Nov 28, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#ifndef ABSTRACTGUIOBJECT_H_
#define ABSTRACTGUIOBJECT_H_

#include "guichan-0.8.2/include/guichan.hpp"
#include "guichan-0.8.2/include/guichan/sdl.hpp"

class AbstractGUIObject {

	int xPosition;
	int yPosition;

public:

	AbstractGUIObject(int xPos, int yPos);
	~AbstractGUIObject();

	void setPosition(int xPos, int yPos){
		xPosition = xPos;
		yPosition = yPos;
	}

};

#endif /* ABSTRACTGUIOBJECT_H_ */

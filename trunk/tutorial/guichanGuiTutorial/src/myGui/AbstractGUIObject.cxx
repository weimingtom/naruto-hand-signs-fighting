/*
 ******************************************************
 * NAME:
 * AbstractGUIObject.cxx
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

#include "AbstractGUIObject.h"

AbstractGUIObject::AbstractGUIObject(int xPos, int yPos) {
	setPosition(xPos, yPos);
}

AbstractGUIObject::~AbstractGUIObject() {
	// TODO Auto-generated destructor stub
}

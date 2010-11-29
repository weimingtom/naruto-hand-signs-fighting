/*
 ******************************************************
 * NAME:
 * MenuElement.h
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

#ifndef MENUELEMENT_H_
#define MENUELEMENT_H_

#include "../GameElement.h"
#include "../controller/AbstractController.h"
#include "../../gui/AbstractFactory.h"

class MenuElement : public GameElement{
	AbstractController* controllerElement;
protected:
	AbstractFactory *elementGraphic;

public:
	MenuElement(AbstractController* absCtrl){
		controllerElement = absCtrl;
	}
	void loopFunction();

	virtual void displayMenuElement() = 0;

    AbstractController *getControllerElement() const
    {
        return controllerElement;
    }

    void setControllerElement(AbstractController *controllerElement)
    {
        this->controllerElement = controllerElement;
    }

};


#endif /* MENUELEMENT_H_ */

/*
 ******************************************************
 * NAME:
 * MovesList.h
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

#ifndef MOVESLIST_H_
#define MOVESLIST_H_

#include "MenuElement.h"
#include "../controller/AbstractController.h"
#include "../../gui/MovesListWindow.h"
#include "../../gameLogic/MovesSet.h"

class MovesList: public MenuElement {
public:
	MovesList(AbstractController* ctrlI, MovesSet* ms): MenuElement(ctrlI){
		elementGraphic = new MovesListWindow(ms);
		elementGraphic->buildWindow();
	}
	virtual ~MovesList();
	void displayMenuElement(){
		elementGraphic->display();
	}
};

#endif /* MOVESLIST_H_ */

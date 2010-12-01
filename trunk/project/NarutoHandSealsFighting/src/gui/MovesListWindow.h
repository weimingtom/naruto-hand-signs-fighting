/*
 ******************************************************
 * NAME:
 * MovesListWindow.h
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

#ifndef MOVESLISTWINDOW_H_
#define MOVESLISTWINDOW_H_

#include "MenuWindow.h"
#include "../gameLogic/MovesSet.h"
#include "MovesListListener.h"

class MovesListModel : public gcn::ListModel{
	MovesSet *movesSet;
public:
	MovesListModel(MovesSet* ms){
		movesSet = ms;
	}
	int getNumberOfElements()
	{
		return movesSet->getMoveSet().size();
	}

	std::string getElementAt(int i){
		Move* m;
		map<string, Move*>::iterator it = movesSet->getMoveSet().begin();
		for(int j=0; j<i; j++)
			it++;
		m = it->second;
		return m->getMoveName();
	}
};

class MovesListWindow: public MenuWindow {
	gcn::ListBox* listBox;
	gcn::ScrollArea* listBoxScrollArea;
	MovesListModel* movesList;
	gcn::Button* tryMove;
	int listBoxWidth;
	int listBoxHeight;
public:
	MovesListWindow(MovesSet* ms);
	virtual ~MovesListWindow();
	void buildWindow();
};

#endif /* MOVESLISTWINDOW_H_ */

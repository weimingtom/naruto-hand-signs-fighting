/*
 ******************************************************
 * NAME:
 * MovesListBoxListener.cxx
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Dec 1, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#include "MovesListBoxListener.h"

MovesListBoxListener::MovesListBoxListener() {
	// TODO Auto-generated constructor stub

}

MovesListBoxListener::~MovesListBoxListener() {
	// TODO Auto-generated destructor stub
}

void MovesListBoxListener::action(const gcn::ActionEvent& actionEvent){
	updateTargetMove(actionEvent);

}

void MovesListBoxListener::focusGained(const gcn::Event& event){
	updateTargetMove(event);
}

void MovesListBoxListener::focusLost(const gcn::Event& event){
	updateTargetMove(event);
}

void MovesListBoxListener::valueChanged(const gcn::SelectionEvent& event){
	updateTargetMove(event);
}

void MovesListBoxListener::updateTargetMove(gcn::Event event){
	gcn::ListBox* listBox = (gcn::ListBox*) event.getSource();
	int sel = listBox->getSelected();
	movesListController_Kagi->setTargetMove(listBox->getListModel()->getElementAt(sel));
}

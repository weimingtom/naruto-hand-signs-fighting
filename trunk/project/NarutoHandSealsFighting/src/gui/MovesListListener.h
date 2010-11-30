/*
 ******************************************************
 * NAME:
 * MovesListListener.h
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

#ifndef MOVESLISTLISTENER_H_
#define MOVESLISTLISTENER_H_

#include "EventToKeyPressConverter.h"
#include "../gameStack/controller/MovesListController.h"

#define TRAINING_EVENT_ID "openTrainingSection"

class MovesListListener: public EventToKeyPressConverter {
	gcn::ListBox* listBox;
public:
	MovesListListener(gcn::ListBox* lb);
	virtual ~MovesListListener();
	void action(const gcn::ActionEvent& actionEvent);
};

#endif /* MOVESLISTLISTENER_H_ */

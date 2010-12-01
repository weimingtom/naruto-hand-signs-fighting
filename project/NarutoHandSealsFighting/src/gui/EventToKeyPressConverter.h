/*
 ******************************************************
 * NAME:
 * EventToKeyPressConverter.h
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

#ifndef EVENTTOKEYPRESSCONVERTER_H_
#define EVENTTOKEYPRESSCONVERTER_H_

#include <SDL/SDL.h>
#include "AbstractEventListener.h"

class EventToKeyPressConverter : public AbstractEventListener {
public:
	EventToKeyPressConverter();
	virtual ~EventToKeyPressConverter();

	void action(const gcn::ActionEvent& actionEvent);
};

#endif /* EVENTTOKEYPRESSCONVERTER_H_ */

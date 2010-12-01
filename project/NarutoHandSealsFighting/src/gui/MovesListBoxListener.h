/*
 ******************************************************
 * NAME:
 * MovesListBoxListener.h
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

#ifndef MOVESLISTBOXLISTENER_H_
#define MOVESLISTBOXLISTENER_H_

#include "AbstractEventListener.h"
#include "guichan-0.8.2/include/guichan/platform.hpp"
#include "../gameStack/controller/MovesListController.h"

//ooohh man this is GOD class!!!
//no, of course not, this is a GOOD class... :P
class MovesListBoxListener : public AbstractEventListener, public gcn::FocusListener,
	public gcn::SelectionListener{
	void updateTargetMove(gcn::Event event);
public:
	MovesListBoxListener();
	virtual ~MovesListBoxListener();
	void action(const gcn::ActionEvent& actionEvent);
	void focusGained(const gcn::Event& event);
	void focusLost(const gcn::Event& event);
	void valueChanged(const gcn::SelectionEvent& event);
};

#endif /* MOVESLISTBOXLISTENER_H_ */

/*
 ******************************************************
 * NAME:
 * AbstractEventListener.h
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

#ifndef ABSTRACTEVENTLISTENER_H_
#define ABSTRACTEVENTLISTENER_H_

#include "guichan-0.8.2/include/guichan.hpp"

class AbstractEventListener : public gcn::ActionListener {
public:
	virtual void action(const gcn::ActionEvent& actionEvent) = 0;

};

#endif /* ABSTRACTEVENTLISTENER_H_ */

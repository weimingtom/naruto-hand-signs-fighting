/*
 ******************************************************
 * NAME:
 * myButtonListener.h
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

#ifndef MYBUTTONLISTENER_H_
#define MYBUTTONLISTENER_H_

#include "../guichan-0.8.2/include/guichan.hpp"


class MyButtonListener : public gcn::ActionListener {
public:
	MyButtonListener();
	~MyButtonListener();
	void action(const gcn::ActionEvent& actionEvent);
};

#endif /* MYBUTTONLISTENER_H_ */

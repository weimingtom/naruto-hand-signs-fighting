/*
 ******************************************************
 * NAME:
 * myButtonListener.cxx
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

#include <iostream>
#include "myButtonListener.h"

using namespace std;

MyButtonListener::MyButtonListener() {
	// TODO Auto-generated constructor stub

}

MyButtonListener::~MyButtonListener() {
	// TODO Auto-generated destructor stub
}

void MyButtonListener::action(const gcn::ActionEvent& actionEvent){
	cout<<actionEvent.getSource() <<" through an id event of: "<<actionEvent.getId()<<"\n";
}

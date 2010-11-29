/*
 ******************************************************
 * NAME:
 * OptionsWindow.cxx
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

#include "OptionsWindow.h"

OptionsWindow::OptionsWindow() : MenuWindow(){
	title = "OPTIONS WINDOW";
}

OptionsWindow::~OptionsWindow() {
	// TODO Auto-generated destructor stub
}

void OptionsWindow::buildWindow(){
	buildTitle();
}

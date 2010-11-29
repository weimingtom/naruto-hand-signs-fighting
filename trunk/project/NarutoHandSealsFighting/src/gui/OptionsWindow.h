/*
 ******************************************************
 * NAME:
 * OptionsWindow.h
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

#ifndef OPTIONSWINDOW_H_
#define OPTIONSWINDOW_H_

#include "MenuWindow.h"

class OptionsWindow: public MenuWindow {
public:
	OptionsWindow();
	virtual ~OptionsWindow();
	void buildWindow();
};

#endif /* OPTIONSWINDOW_H_ */

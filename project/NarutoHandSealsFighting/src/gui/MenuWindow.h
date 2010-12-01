/*
 ******************************************************
 * NAME:
 * MenuWindow.h
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

#ifndef MENUWINDOW_H_
#define MENUWINDOW_H_

#include "AbstractFactory.h"
#include "AbstractEventListener.h"

#define MENU_ELEMENT 5

class MenuWindow: public AbstractFactory {
protected:
	AbstractEventListener* backButtonListener;

protected:
	const char* title;
	gcn::Label *titleLabel;
	gcn::Button *backButton;

	int buttonWidth;
	int buttonHeight;
	int distBetweenButtons;
	int titleHeight;

	void buildTitle();
	void buildBackButton();
public:
	MenuWindow();
	virtual ~MenuWindow();
	void buildWindow();
};

#endif /* MENUWINDOW_H_ */

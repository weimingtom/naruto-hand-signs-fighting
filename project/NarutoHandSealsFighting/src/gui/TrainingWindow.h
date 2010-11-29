/*
 ******************************************************
 * NAME:
 * TrainingWindow.h
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

#ifndef TRAININGWINDOW_H_
#define TRAININGWINDOW_H_

#include "AbstractFactory.h"

class TrainingWindow: public AbstractFactory {
public:
	TrainingWindow();
	~TrainingWindow();
};

#endif /* TRAININGWINDOW_H_ */

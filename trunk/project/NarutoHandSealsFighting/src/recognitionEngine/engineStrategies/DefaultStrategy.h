/*
 ******************************************************
 * NAME:
 * DefaultStrategy.h
 ******************************************************
 * DESCRIPTION:
 *
 * Our default strategy will applies in order:
 *  1. histogram equalization
 *  2. Sobel derivation with CV_SCHARR variant of OpenCV
 *  3. blur with a gaussian curve and 3x3 kernel
 *  4. Laplacian with kernel 7x7
 *
 ******************************************************
 *	Created on: Dec 7, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#ifndef DEFAULTSTRATEGY_H_
#define DEFAULTSTRATEGY_H_

#include "AbstractStrategy.h"

class DefaultStrategy: public AbstractStrategy {
public:
	DefaultStrategy(ModulesPool* modulesPool);
	virtual ~DefaultStrategy();

	void initModules();
};

#endif /* DEFAULTSTRATEGY_H_ */

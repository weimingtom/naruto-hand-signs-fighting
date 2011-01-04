/*
 ******************************************************
 * NAME:
 * AGoodStrategy.h
 ******************************************************
 * DESCRIPTION:
 * Engine Strategy
 * It adds to the engine pool the following modules in
 * order:
 * 1. Sobel with pars: CV_SCHARR,1,0;
 * 2. Blur with pars: CV_GAUSSIAN,3,3
 * 3. Laplacian with kernel 7x7
 * 4. Canny module with kernel 7x7 and threshold centered
 * 		on the mean of the input image and wide 'range'
 * 5. ContoursFinder with the mean of the input image as
 * 		the threshold
 * 6. Closure iterated for 15 cycles.
 *
 ******************************************************
 *	Created on: Jan 1, 2011
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#ifndef AGOODSTRATEGY_H_
#define AGOODSTRATEGY_H_

#include "AbstractStrategy.h"

#define DEFAULT_RANGE 20;

class AGoodStrategy: public AbstractStrategy {
	int meanImage;
	double range;

public:
	AGoodStrategy(ModulesPool* p);
	virtual ~AGoodStrategy();

	void initModules();
};

#endif /* AGOODSTRATEGY_H_ */

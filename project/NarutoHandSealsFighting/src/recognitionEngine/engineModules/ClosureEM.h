/*
 ******************************************************
 * NAME:
 * ClosureEM.h
 ******************************************************
 * DESCRIPTION:
 * Recognition Engine Module
 * The call of the compute function will applies the
 * closure of the input image.
 * You can specify the number of iteration by inputing it
 * in the contructor of the class or by calling the
 * related function in a second moment.
 *
 ******************************************************
 *	Created on: Dec 24, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#ifndef CLOSUREEM_H_
#define CLOSUREEM_H_

#include "EngineModule.h"

class ClosureEM : public EngineModule {
	int iterations;
public:
	ClosureEM();
	ClosureEM(int iterations);
	virtual ~ClosureEM();
	int compute( const IplImage* src, IplImage* dst);

	void setNumerOfIterations(int ite){
		iterations = ite;
	}
};

#endif /* CLOSUREEM_H_ */

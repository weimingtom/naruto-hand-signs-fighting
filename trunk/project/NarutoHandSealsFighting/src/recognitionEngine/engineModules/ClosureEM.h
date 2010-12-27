/*
 ******************************************************
 * NAME:
 * ClosureEM.h
 ******************************************************
 * DESCRIPTION:
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
};

#endif /* CLOSUREEM_H_ */

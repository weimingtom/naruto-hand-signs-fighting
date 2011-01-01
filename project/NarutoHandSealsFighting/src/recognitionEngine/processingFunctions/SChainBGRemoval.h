/*
 ******************************************************
 * NAME:
 * SChainBGRemoval.h
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Jan 1, 2011
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#ifndef SCHAINBGREMOVAL_H_
#define SCHAINBGREMOVAL_H_

#include "SimpleChain.h"
#include "../engineModules/BackgroundRemovalEM.h"


class SChainBGRemoval: public SimpleChain {

	SimpleChain *simpleChain;

	BackgroundRemovalEM *backgroundRemoval;
	IplImage *myForeGroundMaskGray;

	bool firstTime;

public:
	SChainBGRemoval();
	virtual ~SChainBGRemoval();

	int processFunction(std::vector<EngineModule*> *modArray,
					const IplImage* src, IplImage* res);
};

#endif /* SCHAINBGREMOVAL_H_ */

/*
 ******************************************************
 * NAME:
 * SChainBGRemoval.h
 ******************************************************
 * DESCRIPTION:
 * Like the SimpleChain processing function but it
 * removes the background from the input image.
 * The background is captured before the application
 * of the first module and subtracted only after the end
 * of the last.
 *
 * !!!Warning!!!
 * It's up to you to determine the best instant i which
 * call the background capture!
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

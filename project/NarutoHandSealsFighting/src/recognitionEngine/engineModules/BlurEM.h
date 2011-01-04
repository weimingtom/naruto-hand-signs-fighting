/*
 ******************************************************
 * NAME:
 * BlurEM.h
 ******************************************************
 * DESCRIPTION:
 * Recognition Engine Module
 * that applies a blur filter.
 * The default settings are a GAUSSIAN with a 3x3 kernel
 * smoothing filter. You can change these settings
 * by providing them by the constructor or use the
 * different methods in a second moment.
 *
 ******************************************************
 *	Created on: Nov 15, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#ifndef BLUREM_H_
#define BLUREM_H_

#include "EngineModule.h"

#define DEFAULT_BLUR_SIZE 3
#define DEFAULT_BLUR_TYPE CV_GAUSSIAN

class BlurEM : public EngineModule{
	int blurType;
	int size1, size2;
	double sigma1, sigma2;

	void fixName();

public:
	BlurEM(){
		fixName();
		blurType = DEFAULT_BLUR_TYPE;
		size1 = size2 = DEFAULT_BLUR_SIZE;
		sigma1 = sigma2 = 0;
	}

	BlurEM(int cvType, int localSize1, int localSize2);
	BlurEM(int cvType, int localSize1, int localSize2, double sig1, double sig2);

	void setType(int cvType);
	void setSizes(int s1, int s2);
	void setSigma(double sig1, double  sig2);

	int compute(const IplImage* src, IplImage* dst);
};

#endif /* BLUREM_H_ */

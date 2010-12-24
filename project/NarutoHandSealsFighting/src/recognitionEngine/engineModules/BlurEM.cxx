/*
 * BlurEM.cxx
 *
 *  Created on: Nov 15, 2010
 *      Author: michele
 */

#include "BlurEM.h"

int BlurEM::compute(const IplImage* src, IplImage* dst){
	IplImage* temp = cvCreateImage(cvGetSize(src), src->depth, src->nChannels);
	cvSmooth(src, temp, blurType, size1, size2, sigma1, sigma2);
	cvConvertScale(temp, dst, 0.0039215, 0);
	cvReleaseImage(&temp);
}

BlurEM::BlurEM(int cvType, int localSize1, int localSize2){
	fixName();
	setType(cvType);
	setSizes(localSize1, localSize2);
}

BlurEM::BlurEM(int cvType, int localSize1, int localSize2, double sig1, double sig2){
	fixName();
	setType(cvType);
	setSizes(localSize1, localSize2);
	setSigma(sig1, sig2);
}

void BlurEM::fixName(){
	setName("BlurModule");
}

void BlurEM::setType(int cvType){
	blurType = cvType;
}

void BlurEM::setSizes(int s1, int s2){
	size1 = s1;
	size2 = s2;
}

void BlurEM::setSigma(double sig1, double  sig2){
	sigma1 = sig1;
	sigma2 = sig2;
}

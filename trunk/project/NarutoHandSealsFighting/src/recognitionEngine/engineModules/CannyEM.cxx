/*
 * CannyEM.cxx
 *
 *  Created on: Nov 15, 2010
 *      Author: michele
 */

#include "CannyEM.h"

CannyEM::CannyEM(int kernSize, double thresh1, double thresh2){
	fixName();
	kernelSize = kernSize;
	lowThresh = thresh1;
	highThresh = thresh2;
}

int CannyEM::compute( const IplImage* src, IplImage* dst){
	double mean = cvMean(src, NULL);
	IplImage* temp = cvCreateImage(cvSize(src->width, src->height), IPL_DEPTH_8U, 1);
	cvCanny(src, temp, lowThresh, highThresh, kernelSize );
	cvConvertScale(temp, dst);
}

void CannyEM::fixName(){
	setName("CannyModule");
}

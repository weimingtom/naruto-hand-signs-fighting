/*
 ******************************************************
 * NAME:
 * ClosureEM.cxx
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

#include "ClosureEM.h"

ClosureEM::ClosureEM() {
	setName("ClosureModule");
	iterations = 1;
}

ClosureEM::ClosureEM(int iterations){
	setName("ClosureModule");
	this->iterations = iterations;
}

ClosureEM::~ClosureEM() {
	// TODO Auto-generated destructor stub
}

int ClosureEM::compute( const IplImage* src, IplImage* dst){
	IplImage* temp = cvCreateImage(cvSize(src->width, src->height), IPL_DEPTH_8U, 1);
	cvDilate(src, temp, NULL, iterations);
	cvErode(temp, temp, NULL, iterations);
	cvReleaseImage(&temp);
}

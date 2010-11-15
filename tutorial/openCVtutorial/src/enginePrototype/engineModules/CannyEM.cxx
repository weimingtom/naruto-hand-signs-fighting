/*
 * CannyEM.cxx
 *
 *  Created on: Nov 15, 2010
 *      Author: michele
 */

#include "CannyEM.h"

EngineModule *canny = new CannyEM();

int CannyEM::compute( const IplImage* src, IplImage* dst){
	double mean = cvMean(src, NULL);
	IplImage* temp = cvCreateImage(cvSize(src->width, src->height), IPL_DEPTH_8U, 1);
	cvCanny(src, temp, 150, 100, 3);
	cvConvertScale(temp, dst);
}

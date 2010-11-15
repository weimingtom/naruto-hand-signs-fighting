/*
 * ContoursFinderEM.cxx
 *
 *  Created on: Nov 15, 2010
 *      Author: michele
 */

#include "ContoursFinderEM.h"

EngineModule *contours = new ContoursFinderEM;

ContoursFinderEM::ContoursFinderEM(){
	moduleName = "contoursFinder";
	g_thresh = 100;
	g_storage = cvCreateMemStorage(0);
}

int ContoursFinderEM::compute(const IplImage* src, IplImage* dst){
	IplImage* temp  = cvCreateImage(cvGetSize(src), src->depth, 1);
	cvThreshold( src, temp, g_thresh, 255, CV_THRESH_BINARY );
	cvFindContours( temp, g_storage, &contours );
	//		cvZero( g_gray );
	if( contours ){
		cvDrawContours( dst, contours, cvScalarAll(255), cvScalarAll(255), 100 );
	}
}


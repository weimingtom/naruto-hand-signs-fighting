/*
 * ContoursFinderEM.cxx
 *
 *  Created on: Nov 15, 2010
 *      Author: michele
 */

#include "ContoursFinderEM.h"

ContoursFinderEM::ContoursFinderEM(){
	initContoursModule();
	g_thresh = DEFAULT_CONTOUR_THRESHOLD;
}

ContoursFinderEM::ContoursFinderEM(int thresh){
	initContoursModule();
	g_thresh = thresh;
}

ContoursFinderEM::~ContoursFinderEM(){
	cvReleaseMemStorage(&g_storage);
	delete contours;
}

void ContoursFinderEM::initContoursModule(){
	setName("ContoursFinderModule");
	g_storage = cvCreateMemStorage(0);
}

int ContoursFinderEM::compute(const IplImage* src, IplImage* dst){
	IplImage* temp  = cvCreateImage(cvGetSize(src), src->depth, 1);
	cvClearMemStorage( g_storage ); //<- if not cleaned the memory will thrash soon...
	cvThreshold( src, temp, g_thresh, 255, CV_THRESH_BINARY );
	if( contours ){
//		cvFindContours( temp, g_storage, &contours, sizeof( contours), CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE );
		cvFindContours( temp, g_storage, &contours);
		//		cvZero( g_gray );
		cvDrawContours( dst, contours, cvScalarAll(255), cvScalarAll(255), 100 );
	}
	cvReleaseImage(&temp);
}


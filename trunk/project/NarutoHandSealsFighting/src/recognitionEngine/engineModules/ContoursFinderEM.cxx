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
}

void ContoursFinderEM::initContoursModule(){
	setName("ContoursFinderModule");
	g_storage = cvCreateMemStorage(0);
	contourRetrievalMode = CV_RETR_LIST;
	contourMethod =  CV_CHAIN_APPROX_SIMPLE;
	lineThickness = 1;
}

int ContoursFinderEM::compute(const IplImage* src, IplImage* dst){
	IplImage* temp  = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1);
	cvClearMemStorage( g_storage ); //<- if not cleaned the memory will thrash soon...
	cvThreshold( src, temp, g_thresh, 255, CV_THRESH_BINARY );
	if( contours ){
		cvFindContours( temp, g_storage, &contours, sizeof(CvContour),
				contourRetrievalMode, contourMethod);
//		cvFindContours( temp, g_storage, &contours);
//		cvZero( temp);
		cvDrawContours( dst, contours, cvScalarAll(255), cvScalarAll(255), 1, lineThickness);
	}
//	cvConvertScale(temp, dst);
	cvReleaseImage(&temp);
}


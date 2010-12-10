/*
 ******************************************************
 * NAME:
 * mainPaintedCamera.cxx
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Dec 10, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */
#include <iostream>
#include <opencv/cxcore.h>
#include <opencv/highgui.h>
#include "Camera.h"

static const char* INPUT_IMAGE =  "tiger-template-bw.png";

using namespace std;

IplImage*	g_image = NULL;
IplImage*	g_gray = NULL;
int		g_thresh = 100;
CvMemStorage* 	g_storage = NULL;

int main(int argc, char argv[]){
	IplImage* img = cam->captureImage();
	IplImage* res;
	bool done = false;
	const char* winName = "mainWin";

	cvNamedWindow( winName, CV_WINDOW_AUTOSIZE );
	res = cvCreateImage(cvSize(img->width, img->height), img->depth, 1);
	cvCvtColor(img, res, CV_BGR2GRAY);
	cvShowImage( winName, res );
	cvWaitKey(0);

	g_image = cvLoadImage(INPUT_IMAGE);
	if( g_storage == NULL ){
		g_gray = cvCreateImage( cvGetSize( g_image ), 8, 1 );
		g_storage = cvCreateMemStorage(0);
	} else {
		cvClearMemStorage( g_storage );
	}

	CvSeq* contours = 0;
	cvCvtColor( g_image, g_gray, CV_BGR2GRAY );
	cvThreshold( g_gray, g_gray, g_thresh, 255, CV_THRESH_BINARY );
	cvFindContours( g_gray, g_storage, &contours );
	cvZero( g_gray );

	/*
	 * in this section we will try to convert an IplImage in input
	 * from the console to a contour path used to highlight the shade of hands
	 */
	while(!done){
		//	cam.activateAndShow();
		if( cam->capturing() < 0){				//<- uncomment this line
			cout<<"camera problem!\n";			//<- uncomment this line
			break;								//<- uncomment this line
		}										//<- uncomment this line
		if( contours ){
			cvDrawContours(
					cam->getFrame(),
					contours,
					cvScalarAll(255),
					cvScalarAll(255),
					100 );
		}
		cvShowImage( winName, cam->getFrame());
		if( (cvWaitKey(10) & 255) == 27 ){
			done = true;
		}
	}

	cvDestroyAllWindows();
	return 0;
}

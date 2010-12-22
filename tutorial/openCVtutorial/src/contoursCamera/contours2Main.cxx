/*
 * contours2Main.cxx
 *
 *  Created on: Nov 15, 2010
 *      Author: michele
 */

#include <opencv/cv.h>
#include <opencv/cxcore.h>
#include <opencv/highgui.h>
#include <iostream>

#include <stdio.h>
#include <stdlib.h>

#include "Camera.h"
#include "HistogramEM.h"

using namespace std;

IplImage*	g_image = NULL;
IplImage*	g_gray = NULL;
double		g_thresh = 100;
CvMemStorage* 	g_storage = NULL;

void on_trackbar(int){
	if( g_storage == NULL ){
		g_gray = cvCreateImage( cvGetSize( g_image ), 8, 1 );
		g_storage = cvCreateMemStorage(0);
	} else {
		cvClearMemStorage( g_storage );
	}

	CvSeq* contours = 0;
	cvCvtColor( g_image, g_gray, CV_BGR2GRAY );
	g_thresh = cvMean(g_image);
	//with Otsu threshold
//	cvThreshold( g_gray, g_gray, g_thresh, 255, CV_THRESH_OTSU );

	cvThreshold( g_gray, g_gray, g_thresh, 255, CV_THRESH_BINARY);
	cvFindContours( g_gray, g_storage, &contours );
	cvZero( g_gray );
	if( contours ){
		cvDrawContours(
			g_gray,
			contours,
			cvScalarAll(255),
			cvScalarAll(255),
			100 );
	}
	cvShowImage( "Contours", g_gray );
}


int main(int argc, char* argv[])
{
	bool done = false;
	HistogramEM *hist = new HistogramEM();

//	g_image = cvLoadImage( argv[1] );
//	cvNamedWindow( "Contours", 1 );
//	cvCreateTrackbar( "Threshold", "Contours", &g_thresh, 255, on_trackbar );
//	on_trackbar(0);
//	cvWaitKey();

	while(!done){
		/*
		 * The following are two equivalent alternatives.
		 * Remember that you have to take care about the
		 * refresh time and the way you are handling the
		 * main loop, so depending on your purpose they
		 * may result in different behaviors!
		 */
		///////////////////////////////
		//1) using the capturing method of the Camera
		//  this is the best result looking at the refresh time
		if( cam->capturing() < 0){				//<- uncomment this line
			cout<<"camera problem!\n";			//<- uncomment this line
			break;								//<- uncomment this line
		}										//<- uncomment this line
//		cvShowImage( mu, cam->getFrame());		//<- uncomment this line
		g_image = cam->getFrame();
//		g_thresh = cvThreshold(cam->getFrame(), cam->getFrame(), g_thresh, 255, CV_THRESH_OTSU);
		on_trackbar(0);
		///////////////////////////////

		//////////////////////////////////
		//2) simply capture a single frame at time ad shows it
		//		cvShowImage(mu, cam->captureImage()); 	//<- uncomment this line
		//////////////////////////////////

		//////////////////////////////////
		//3) using the photoShot functions: the photo is
		//  simply an image such as frame, but their are split in
		//  order to differentiate the photo which one would keep
		//  and the temporary image used by the camera acquisition
		//		cam->shotAPhoto(); 						//<- uncomment this line
		//		cvShowImage(mu, cam->getPhotoShot()); 	//<- uncomment this line
		if( (cvWaitKey(10) & 255) == 27 ){
			done = true;
		}
	}

	return 0;
}

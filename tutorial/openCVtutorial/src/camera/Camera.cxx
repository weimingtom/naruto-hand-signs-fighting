/*
 * Camera.cxx
 *
 *  Created on: Nov 12, 2010
 *      Author: michele
 */

#include "Camera.h"

Camera cam;

Camera::Camera(){
	capture = cvCaptureFromCAM( CV_CAP_ANY );
//	capture = cvCreateCameraCapture( CV_CAP_ANY );
	if( !capture ) {
		fprintf( stderr, "ERROR: capture is NULL \n" );
		getchar();
		return;
	}
	frame = NULL;
}

Camera::~Camera(){
	// Release the capture device housekeeping
	cvReleaseCapture( &capture );
}

int Camera::activateAndShow(){
	int offFakeFrame = 0;

	// Create a window in which the captured images will be presented
	cvNamedWindow( CAM_WIN, CV_WINDOW_AUTOSIZE );
	// Show the image captured from the camera in the window and repeat
	while( 1 ) {
		// Get one frame
		//Or we can use:
		if(cvGrabFrame(capture)){
			frame = cvQueryFrame( capture );
			//			frame = cvRetrieveFrame( capture );
		}
		if( !frame && (offFakeFrame > OFFSET_FRAME) ) {
			fprintf( stderr, "ERROR: frame is null...\n" );
			getchar();
			break;
		}
		if(offFakeFrame <= OFFSET_FRAME)
			offFakeFrame++;
		cvShowImage( CAM_WIN, frame );
		// Do not release the frame!
		//If ESC key pressed, Key=0x10001B under OpenCV 0.9.7(linux version),
		//remove higher bits using AND operator
		if( (cvWaitKey(10) & 255) == 27 )
			break;
	}
	cvDestroyWindow( CAM_WIN );
	return 0;
}

IplImage* Camera::captureImage(){
	for(int i=0; i<OFFSET_FRAME; i++){
		if(cvGrabFrame(capture)){
			frame = cvQueryFrame( capture );
//			frame = cvRetrieveFrame( capture );
		}
	}
	return frame;
}

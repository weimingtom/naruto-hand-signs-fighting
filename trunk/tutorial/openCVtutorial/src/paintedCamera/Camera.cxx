/*
 * Camera.cxx
 *
 *  Created on: Nov 12, 2010
 *      Author: michele
 */

#include "Camera.h"
#include <iostream>

using namespace std;


Camera* Camera::camera = NULL;
Camera *cam = Camera::getCameraInstance();

void Camera::initCamera(){
	capture = cvCaptureFromCAM( CV_CAP_ANY );
	captureWidth = DEFAULT_CAPTURE_WIDTH;
	captureHeigh = DEFAULT_CAPTURE_HEIGHT;
	cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_WIDTH, captureWidth );
	cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_HEIGHT, captureHeigh );
//	capture = cvCreateCameraCapture( CV_CAP_ANY );
	if( !capture ) {
		fprintf( stderr, "ERROR: capture is NULL \n" );
		getchar();
		return;
	}
	frame = NULL;
	winX = winY = 300;
	offFakeFrame = 0;
}

Camera::~Camera(){
	// Release the capture device housekeeping
	cvReleaseCapture( &capture );
	cvReleaseImage(&frame);
	cvReleaseImage(&photoShot);
}

Camera* Camera::getCameraInstance(){
	if(camera == NULL){
		camera = new Camera();
		camera->initCamera();
		cout<<"created new camera\n";
		return camera;
	}
	return camera;
}

int Camera::activateAndShowInWindow(){

	// Create a window in which the captured images will be presented
	cvNamedWindow( CAM_WIN, CV_WINDOW_AUTOSIZE );
	cvMoveWindow(CAM_WIN, winX, winY);
	// Show the image captured from the camera in the window and repeat
	while( 1 ) {
		if(capturing()<0){
			break;
		}
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

int Camera::capturing(){
	// Get one frame
	//Or we can use:
	if(cvGrabFrame(capture)){
		frame = cvQueryFrame( capture );
		cvFlip(frame, frame, 1);
		//			frame = cvRetrieveFrame( capture );
	}
	if( !frame && (offFakeFrame > OFFSET_FRAME) ) {
		fprintf( stderr, "ERROR: frame is null...\n" );
		getchar();
		return -1;
	}
	if(offFakeFrame <= OFFSET_FRAME)
		offFakeFrame++;
}

//WARNING: NOT race condition free!!!
void Camera::shotAPhoto(){
	photoShot =captureImage();
	cvFlip(photoShot, photoShot, 1);
}

void Camera::setCaptureSize(int w, int h){
	captureWidth = w;
	captureHeigh = h;
	cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_WIDTH, captureWidth );
	cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_HEIGHT, captureHeigh );
}

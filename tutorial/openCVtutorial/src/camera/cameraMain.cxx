/*
 * cameraMain.cxx
 *
 *  Created on: Nov 12, 2010
 *      Author: michele
 */

#include "Camera.h"



using namespace std;

// A Simple Camera Capture Framework
int main(int argc, char* argv[]) {
////	CvCapture* capture = cvCaptureFromCAM( CV_CAP_ANY );
//	CvCapture* capture = cvCreateCameraCapture( CV_CAP_ANY );
//	IplImage* frame = NULL;
//	int offFakeFrame = 0;
//
//	if( !capture ) {
//		fprintf( stderr, "ERROR: capture is NULL \n" );
//		getchar();
//		return -1;
//	}
//	// Create a window in which the captured images will be presented
//	cvNamedWindow( "mywindow", CV_WINDOW_AUTOSIZE );
//	// Show the image captured from the camera in the window and repeat
//	while( 1 ) {
//		// Get one frame
//		//Or we can use:
//		if(cvGrabFrame(capture)){
//			frame = cvQueryFrame( capture );
////			frame = cvRetrieveFrame( capture );
//		}
//		if( !frame && (offFakeFrame > OFFSET_FRAME) ) {
//			fprintf( stderr, "ERROR: frame is null...\n" );
//			getchar();
//			break;
//		}
//		if(offFakeFrame <= OFFSET_FRAME)
//			offFakeFrame++;
//		cvShowImage( "mywindow", frame );
//		// Do not release the frame!
//		//If ESC key pressed, Key=0x10001B under OpenCV 0.9.7(linux version),
//		//remove higher bits using AND operator
//		if( (cvWaitKey(10) & 255) == 27 )
//			break;
//	}
//	// Release the capture device housekeeping
//	cvReleaseCapture( &capture );
//	cvDestroyWindow( "mywindow" );
//	return 0;

	//////////////////////////////////////
	//// my new code for the project ////
	/////////////////////////////////////
//	Camera* cam;
	IplImage* img = cam.captureImage();
	IplImage* res;

	cvNamedWindow( "mainWin", CV_WINDOW_AUTOSIZE );
	res = cvCreateImage(cvSize(img->width, img->height), img->depth, 1);
	cvCvtColor(img, res, CV_BGR2GRAY);
	cvShowImage( "mainWin", res );
	cvWaitKey(0);
	cvDestroyAllWindows();

//	cam.activateAndShow();

}

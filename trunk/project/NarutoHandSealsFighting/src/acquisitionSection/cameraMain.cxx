/*
 * cameraMain.cxx
 *
 *  Created on: Nov 12, 2010
 *      Author: michele
 */

#include <iostream>
#include "Camera.h"

using namespace std;

void createMuWindow();

const char* mu = "showTry";

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
//	Camera* cam = Camera::getCameraInstance();
//	Camera* cam = new Camera();
	IplImage* img = cam->captureImage();
	IplImage* res;
	bool done = false;

	cvNamedWindow( "photoWin", CV_WINDOW_AUTOSIZE );
	res = cvCreateImage(cvSize(img->width, img->height), img->depth, 1);
	cvCvtColor(img, res, CV_BGR2GRAY);
	cvShowImage( "photoWin", res );
	cvWaitKey(0);

	createMuWindow();

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
		cvShowImage( mu, cam->getFrame());		//<- uncomment this line
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
//	delete cam;

//	cam = new Camera();
	Camera *c2 = cam;
	cout<<"built a new camera! ";
	cout<<c2->getPiggyBackCamera()<<"\n";

	c2->activateAndShowInWindow();

	Camera *c3 = c2;
	cout<<"using now a new one: C3! \n";
	c3->activateAndShowInWindow();

	cvDestroyAllWindows();
}

void createMuWindow(){
	cvNamedWindow(mu, CV_WINDOW_NORMAL);
	cvMoveWindow(mu, 500, 200);
	cvResizeWindow(mu, 500, 300);
}

/*
 * Camera.h
 *
 *  Created on: Nov 12, 2010
 *      Author: michele
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <stdio.h>

/*
 * Sometimes the first picture taken from the camera isn't a
 * good image (probably only half acquired or affected by other
 * problems). In order to correct this bug we will use the
 * OFFSET_FRAME + 1 exposure picture taken from the camera.
 */
#define OFFSET_FRAME 2

#define CAM_WIN "cameraWindow"

using namespace std;

class Camera{
	CvCapture* capture;
	IplImage* frame;
public:
	Camera();
	~Camera();
	int activateAndShow();
	IplImage* captureImage();
};

extern Camera cam;


#endif /* CAMERA_H_ */

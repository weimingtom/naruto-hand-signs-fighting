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
	//PATTERN Singleton
	static Camera* camera;

	CvCapture* capture;
	IplImage* frame;

	int winX;
	int winY;

	int offFakeFrame;

public:
	~Camera();
	void initCamera();
	static Camera* getCameraInstance();
	int activateAndShow();
	int capturing();
	IplImage* captureImage();
    CvCapture *getCapture() const
    {
        return capture;
    }

    void setCapture(CvCapture *capture)
    {
        this->capture = capture;
    }

    void setCameraWindowPosition(int x, int y){
		winX = x;
		winY = y;
	}

    int getWinX() const
    {
        return winX;
    }

    int getWinY() const
    {
        return winY;
    }

    IplImage *getFrame() const
    {
        return frame;
    }

    void setFrame(IplImage *frame)
    {
        this->frame = frame;
    }

};

//extern Camera cam;


#endif /* CAMERA_H_ */

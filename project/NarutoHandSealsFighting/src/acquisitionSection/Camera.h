/*
 ******************************************************
 * NAME:
 * Camera.h
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Nov 12, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <stdio.h>

#define DEFAULT_CAPTURE_WIDTH 640
#define DEFAULT_CAPTURE_HEIGHT 480

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

	int captureWidth;
	int captureHeigh;

	//Variables used in the Video modality of the camera
	CvCapture* capture;
	IplImage* frame;

	//Variable used to shot a photo
	IplImage* photoShot;

	int winX;
	int winY;

	int offFakeFrame;

	const char* piggyBackCamera;


public:
	Camera();
	~Camera();
	void initCamera();

	// It returns an instance of the camera. Take care to the fact that
	// this variable is under the Singleton pattern.
	static Camera* getCameraInstance();

	// It activates and shows the capturing phase using an OpenCV standard
	// window. It first shot a photo and then starts the loop of capturing
	// that is stoppable by a keyboard entry.
	int activateAndShowInWindow();

	// It stars the capturing phase. It DOESN'T start a loop, so you can
	// use this function in a main loop cycle or anything else you want to
	// capture a video.
	// !!!Warning!!!
	// The captured image is flipped along the y axis in order to see the screen
	// such as a mirror, because of the aim of the application.
	int capturing();

	// Returns the captured image just in time as the method is called.
	IplImage* captureImage();

	// Generally used to pick up a frame used as a photo from the
	// capturing phase. Once you used this method you can access the
	// photoShot image by the relative method:
	//      IplImage* getPhotoShot();
	void shotAPhoto();

	void setCaptureSize(int w, int h);
    const char *getPiggyBackCamera() const
    {
        return piggyBackCamera;
    }

    IplImage *getPhotoShot() const
    {
        return photoShot;
    }

    void setPhotoShot(IplImage *photoShot)
    {
        this->photoShot = photoShot;
    }

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

extern Camera *cam;


#endif /* CAMERA_H_ */

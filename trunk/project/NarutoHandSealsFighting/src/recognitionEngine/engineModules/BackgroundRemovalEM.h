/*
 ******************************************************
 * NAME:
 * BackgroundRemovalEM.h
 ******************************************************
 * DESCRIPTION:
 * Recognition Engine Module
 * Using the compute function it removes the background
 * from the input image and filter it by the created mask
 * keep only the fore ground areas.
 * It's up to you to call the background capturing
 * function, then you can use the compute one or
 * directly the backgroundRemoval function.
 *
 * Modifying the cxx file you can show in two windows
 * the results of the
 * background and foreground (please look the file
 * BackgroundRemovalEM.cxx).
 *
 * You can visit the site:
 * http://blog.damiles.com/?p=127
 * for the theoretical base and the source of the idea
 *
 ******************************************************
 *	Created on: Dec 29, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#ifndef BACKGROUNDREMOVALEM_H_
#define BACKGROUNDREMOVALEM_H_

#include "EngineModule.h"
#include "../../acquisitionSection/Camera.h"
#include "../ImageProcessing.h"

#define BG_REMOVAL_TRAINING_FRAMES 30 //default value of the total frames used in the "training"

class BackgroundRemovalEM : public EngineModule {
	Camera *camera;

	IplImage *frame;
	IplImage *lambda_sig2; //<- this is the right condition
	IplImage *leftCond, *leftCond2; //<- the left condition
	IplImage* MEAN;

	IplImage *myForeGroundMaskGray;
	IplImage *lambda_sig2Gray;

	bool firstTime;
	int trainingFrames;

public:
	BackgroundRemovalEM();
	virtual ~BackgroundRemovalEM();

	int compute( const IplImage* src, IplImage* dst);

	/*
	 * It captures from the camera a number of
	 * BG_REMOVAL_TRAINING_FRAMES different
	 * frames in order to detect the background
	 * of the actual camera acquisition view.
	 * This function is fired only the first time
	 * the 'compute(src, dst)' function is invoked.
	 */
	void backGroundCapturing();

	/*
	 * It subtracts the background pixels found by the
	 *   backGroundCapturing()
	 * function from the input image.
	 * You can retrieve the result by getting the
	 * foreground by the function:
	 *   getForegroundMask
	 */
	void backGroundRemoval(const IplImage *localFrame);

	IplImage* getForegroundMask(){
		return myForeGroundMaskGray;
	}
};

#endif /* BACKGROUNDREMOVALEM_H_ */

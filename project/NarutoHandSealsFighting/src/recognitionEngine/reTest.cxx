/*
 ******************************************************
 * NAME:
 * reTest.cxx
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Nov 24, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv/cvaux.h>
#include <iostream>

#include "RecognitionEngine.h"
#include "RecognitionEngine.h"
#include "engineModules/EngineModule.h"
#include "evaluationFunctions/MulEvaluator.h"
#include "engineModules/All.h"
#include "ImageProcessing.h"

#include "../gameLogic/SealsFactory.h"
#include "../gameLogic/SealsMap.h"
#include "../gameLogic/MovesFactory.h"
#include "../gameLogic/MovesSet.h"

#include "../acquisitionSection/Camera.h"

#include "../DebugPrint.h"

using namespace std;

MovesSet myMoveSet;
SealsMap smap;
const char* winOrig = "originalCapture";
const char* win = "reTestWin";

int main(int argc, char* argv[]){
	IplImage *temp, *img, *res;
	bool done = false;
	int appo;

	sealsFactory->buildSealsMap(&smap);
	movesFactory->buildMovesSet(&myMoveSet, &smap);
//	recognitionEngine->initEngine();

//	recognitionEngine->addModule(new HistogramEM());
//	recognitionEngine->addModule(new SobelEM(CV_SCHARR, 1, 0));
//	recognitionEngine->addModule(new BlurEM(CV_GAUSSIAN,3,3));
//	recognitionEngine->addModule(new LaplacianEM(5));

	for(int i=0; i<10; i++)
		cam->capturing();
	img = cam->getFrame();

	debugPrint(">captured image\n");

	debugPrint(">created res\n");
	temp = cvCreateImage(cvSize(img->width, img->height),RE_INPUT_IMAGE_DEPTH, 1);
	debugPrint(">created temp\n");
	appo = cvMean(img);
	debugPrint("mean is :%d", appo);
	recognitionEngine->addModule(new CannyEM(5, 100, appo));
//	recognitionEngine->addModule(new ContoursFinderEM(appo));

	cvNamedWindow(win, CV_WINDOW_AUTOSIZE);
	cvNamedWindow(winOrig, CV_WINDOW_AUTOSIZE);
	cvMoveWindow(winOrig, 20, 100);
	cvMoveWindow(win, 700, 100);


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
			img = cam->getFrame();
			cvShowImage( winOrig, img);		//<- uncomment this line
			///////////////////////////////


			convertToGrayScale(img, temp);
//			debugPrint(">convertScale\n");
//			debugPrint(">processing\n");
			res = cvCreateImage(cvSize(img->width, img->height),RE_OUTPUT_IMAGE_DEPTH, 1);
			recognitionEngine->process(temp, res);
			cvShowImage(win, res);
			cvReleaseImage(&res);
			if( (cvWaitKey(10) & 255) == 27 ){
				done = true;
			}
		}

	cvDestroyWindow(win);
	cvDestroyWindow(winOrig);
	/*
	 * and so on...
	 */

	return 0;
}


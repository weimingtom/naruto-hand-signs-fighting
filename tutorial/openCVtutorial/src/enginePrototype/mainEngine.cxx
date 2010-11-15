/*
 * mainEngine.cxx
 *
 *  Created on: Nov 13, 2010
 *      Author: michele
 */

#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv/cvaux.h>
#include <opencv/cxtypes.h>
#include <opencv/cxcore.h>   // unnecessary - included in cv.h

#include <iostream>
#include <stdio.h>

#include "RecognitionEngine.h"
#include "engineModules/EngineModule.h"
//////////////////
//My built modules
//////////////////
#include "engineModules/CannyEM.h"
#include "engineModules/LaplacianEM.h"
#include "engineModules/SobelEM.h"
#include "engineModules/HistogramEM.h"
//////////////////

#define MAIN_WIN "mainWin"
#define RES_WIN "resWin"

const char* IMAGE_PATH = "./2010-11-02-093111.png";

int main(int argc, char* argv[] ){
	IplImage *temp, *img, *res;
	if(argc<2){
		printf("Usage: main <image-file-name>\n\7");
		exit(0);
	}
	temp = cvLoadImage(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
	img = cvCreateImage(cvSize(temp->width, temp->height), IPL_DEPTH_8U, 1);
	cvConvertScale(temp, img);
	res = cvCreateImage(cvSize(img->width, img->height), IPL_DEPTH_32F, img->nChannels);

	//The first step is to add different modules to our engine
//	recognitionEngine.addModule(laplacian);
//	recognitionEngine.addModule(sobel);
//	recognitionEngine.addModule(histogram);
	recognitionEngine.addModule(canny);

	cout<<"starting process\n"; fflush(stdout);
	//Then we launch the processing phase
	recognitionEngine.process(img, res);


	cvNamedWindow(MAIN_WIN, CV_WINDOW_AUTOSIZE);
	cvMoveWindow(MAIN_WIN, 50, 50);

	// create a second window
	cvNamedWindow(RES_WIN, CV_WINDOW_AUTOSIZE);
	cvMoveWindow(RES_WIN, 700, 50);

	cvShowImage(MAIN_WIN, img);
	cvShowImage(RES_WIN, res);

	//If you want to display the histogram...
//	HistogramEM* hist = (HistogramEM*) histogram;
//	hist->displayHistogram(RES_WIN);

	cvWaitKey(0);
	cvReleaseImage(&img);
	cvReleaseImage(&res);
	cvDestroyAllWindows();
	return 0;
}

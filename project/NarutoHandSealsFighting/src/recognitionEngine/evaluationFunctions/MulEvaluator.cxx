/*
 ******************************************************
 * NAME:
 * MulEvaluator.cxx
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Nov 23, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#include <iostream>
#include <stdio.h>
#include <opencv/highgui.h>
#include "MulEvaluator.h"
#include "../RecognitionEngine.h"
#include "../ImageProcessing.h"

#define DEF_WIDTH 640
#define DEF_HEIGHT 480

EvaluatorFunctionTemplate* mulEvaluator = new MulEvaluator();


int MulEvaluator::evaluate(IplImage* img, Move* m, int index){
	int ret, wPixelsTemplate, wPixelsRes;
	float tempRes;
	//!!! Remember !!!
	//the triple (src, mul, dst) must have the same width, height and depth
	//get the template image of the indexed seal into the move
	IplImage* originalTemplateImg = m->getMoveSeals().at(index)->getTemplateImage();

	//setting the ROI in the input img of the dimensions of the template
	cvSetImageROI(img, cvRect( img->width/2 - originalTemplateImg->width/2,
			img->height/2 - originalTemplateImg->height/2,
			originalTemplateImg->width, originalTemplateImg->height));

	//create the temp matrixes for the multiplication and the output

	IplImage* tempOut = cvCreateImage(
			cvSize(originalTemplateImg->width, originalTemplateImg->height),
			RE_OUTPUT_IMAGE_DEPTH, 1);
	IplImage* tempMul = cvCreateImage(
			cvSize(originalTemplateImg->width, originalTemplateImg->height),
			RE_OUTPUT_IMAGE_DEPTH, 1);

	//conversion from DEPTH_8U to DEPTH_32F
	convertDepth_8U_to_32F(img, tempMul);

	IplImage* tempTemplate = cvCreateImage(cvSize(originalTemplateImg->width, originalTemplateImg->height),
			RE_OUTPUT_IMAGE_DEPTH, 1);
	//conversion from DEPTH_8U to DEPTH_32F
	convertDepth_8U_to_32F(originalTemplateImg, tempTemplate);

//	cvMul(t, tempMul, tempOut);
	cvAnd(tempTemplate, tempMul, tempOut, originalTemplateImg);

//	displayResult(tempMul, tempTemplate, tempOut, 60000);

	//If we don't release the ROI it will display it instead of the "total" image
//	cvResetImageROI(img);

	wPixelsTemplate = cvCountNonZero(originalTemplateImg);
	cvThreshold(tempOut, tempOut, 0.2, 1, CV_THRESH_BINARY);
	wPixelsRes = cvCountNonZero(tempOut);

	tempRes =  float(wPixelsRes)/float(wPixelsTemplate);
	ret = tempRes * 100;
//	cout<<"wp-teplate: "<<wPixelsTemplate<<" wp-res: "<<wPixelsRes<<" div: "<<tempRes<<"\n";

	cvConvertScale(tempOut, img);

	cvReleaseImage(&tempOut);
	cvReleaseImage(&tempMul);
	cvReleaseImage(&tempTemplate);
	return ret;
}


void MulEvaluator::displayResult(IplImage* input, IplImage* templateImg, IplImage* result,
		int delay){
	const char* in = "inputImage";
	const char* templ = "template";
	const char* res = "result";

	cvNamedWindow(in, CV_WINDOW_AUTOSIZE);
	cvNamedWindow(templ, CV_WINDOW_AUTOSIZE);
	cvNamedWindow(res, CV_WINDOW_AUTOSIZE);

	cvMoveWindow(in, 20, 50);
	cvMoveWindow(templ, 220, 50);
	cvMoveWindow(res, 420, 250);

	cvShowImage(in, input);
	cvShowImage(templ, templateImg);
	cvShowImage(res, result);
	cvWaitKey(delay);

	cvDestroyWindow(in);
	cvDestroyWindow(templ);
	cvDestroyWindow(res);
}

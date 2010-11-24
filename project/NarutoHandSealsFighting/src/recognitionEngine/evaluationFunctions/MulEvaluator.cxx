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
	//!!! Remember !!!
	//the triple (src, mul, dst) must have the same width, height and depth
	//get the template image of the indexed seal into the move
	IplImage* templateImg = m->getMoveSeals().at(index)->getTemplateImage();

	//setting the ROI in the input img of the dimensions of the template
	cvSetImageROI(img, cvRect( img->width/2 - templateImg->width/2,
			img->height/2 - templateImg->height/2,
			templateImg->width, templateImg->height));

	//create the temp matrixes for the multiplication and the output

	IplImage* tempOut = cvCreateImage(cvSize(templateImg->width, templateImg->height),
			RE_OUTPUT_IMAGE_DEPTH, 1);
	IplImage* tempMul = cvCreateImage(cvSize(templateImg->width, templateImg->height),
			RE_OUTPUT_IMAGE_DEPTH, 1);
	//conversion from DEPTH_8U to DEPTH_32F
	convertDepth8UTo32F(img, tempMul);
	cvConvertScale(img, tempMul, 0.0039215, 0);
//	cvNot(tempMul, tempMul);

	IplImage* t = cvCreateImage(cvSize(templateImg->width, templateImg->height),
			RE_OUTPUT_IMAGE_DEPTH, 1);
	//conversion from DEPTH_8U to DEPTH_32F
	convertDepth8UTo32F(templateImg, t);
//	cvConvertScale(templateImg, t, 0.0039215, 0);

//	IplImage* ones =cvCreateImage(cvSize(templateImg->width, templateImg->height),
//			RE_OUTPUT_IMAGE_DEPTH, 1);
//	cvSetZero(ones);
//	cvNot(ones, ones);


	cvMul(t, tempMul, tempOut);
//	cvAnd(t,tempMul, tempOut);
//	cvOr(t, tempMul, tempOut);
	displayResult(tempMul, t, tempOut, 20000);
	//If we don't release the ROI it will display it instead of the "total" image
//	cvResetImageROI(img);

	wPixelsTemplate = cvCountNonZero(templateImg);
	wPixelsRes = cvCountNonZero(tempOut);
	cout<<"wp-teplate: "<<wPixelsTemplate<<" wp-res: "<<wPixelsRes<<"\n";
	ret = wPixelsRes/wPixelsTemplate * 10;

	cvConvertScale(tempOut, img);

//	cvReleaseImage(&temp);
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

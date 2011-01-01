/*
 ******************************************************
 * NAME:
 * BackgroundRemovalEM.cxx
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Dec 29, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#include <iostream>
#include "BackgroundRemovalEM.h"
#include "../../DebugPrint.h"
#include "../RecognitionEngineDefaults.h"

#define SHOW_BG_REMOVAL 1

using namespace std;

const char *winLeftCond = "FOREground";
const char *winBg = "BACKground";

BackgroundRemovalEM::BackgroundRemovalEM() {
	setName("Background Removal Module");
	camera = cam;
	for(int i=0; i<10; i++)
		camera->capturing();
	frame = camera->getFrame();

	leftCond = cvCreateImage(cvGetSize(frame), RE_INPUT_IMAGE_DEPTH , 1);
	leftCond2 = cvCreateImage(cvGetSize(frame),RE_INPUT_IMAGE_DEPTH , 1);
	lambda_sig2 = cvCreateImage(cvGetSize(frame),frame->depth, frame->nChannels);

	MEAN = cvCreateImage(cvGetSize(frame), RE_INPUT_IMAGE_DEPTH, 1);
	myForeGroundMaskGray = cvCreateImage(cvGetSize(frame), IPL_DEPTH_8U, 1);
	lambda_sig2Gray = cvCreateImage(cvGetSize(lambda_sig2),lambda_sig2->depth , 1);

	firstTime = true;
	trainingFrames = BG_REMOVAL_TRAINING_FRAMES;

#if SHOW_BG_REMOVAL == 1
	cvNamedWindow(winLeftCond, CV_WINDOW_NORMAL);
	cvNamedWindow(winBg, CV_WINDOW_NORMAL);
	cvMoveWindow(winLeftCond, 350, 500 );
	cvMoveWindow(winBg, 10, 500);
#endif
}

BackgroundRemovalEM::~BackgroundRemovalEM() {
	/////////////////////////
	//used for background removal:

	cvReleaseImage(&lambda_sig2);
	cvReleaseImage(&leftCond);
	cvReleaseImage(&leftCond2);

	cvReleaseImage(&MEAN);
	cvReleaseImage(&myForeGroundMaskGray);
	cvReleaseImage(&lambda_sig2Gray);
	/////////////////////////

#if SHOW_BG_REMOVAL == 1
	cvDestroyWindow(winLeftCond);
	cvDestroyWindow(winBg);
#endif
}

void BackgroundRemovalEM::backGroundCapturing(){
	/////////////////////////////////////
	//Let's try a background removal:
	/////////////////////////////////////
	unsigned long int N = 0; //Number of total frames used in the "training"
	IplImage *acc, *sqacc, *M, *M2, *sqaccM, *sig2;

	cout<<"BACKGROUND CAPTURING.\n PLEASE DON'T MOVE ... ";
//	debugPrint("trying back ground training: ...");

	acc = cvCreateImage(cvGetSize(frame), IPL_DEPTH_32F, frame->nChannels);
	sqacc = cvCreateImage(cvGetSize(frame), IPL_DEPTH_32F, frame->nChannels);
	M = cvCreateImage(cvGetSize(frame),IPL_DEPTH_32F , frame->nChannels);
	M2 = cvCreateImage(cvGetSize(frame),IPL_DEPTH_32F , frame->nChannels);
	sqaccM = cvCreateImage(cvGetSize(frame),IPL_DEPTH_32F , frame->nChannels);
	sig2 = cvCreateImage(cvGetSize(frame), IPL_DEPTH_32F, frame->nChannels);

//	debugPrint("starting cycle:... ");
	for(int i=0, N=0; i < trainingFrames; i++){
		cvAcc(frame,acc,NULL);
		cvSquareAcc(frame, sqacc, NULL);
		N++;
		cvConvertScale(acc, M, (double)(1.0/N), 0);
		cvConvertScale(sqacc, sqaccM, (double)(1.0/N),0);
		cvMul( M, M, M2, 1 );
		cvSub( sqaccM, M2, sig2, NULL);//The sig is sig2
		camera->capturing();
		frame = camera->getFrame();
	}
//	debugPrint(" out of the cycle \n");

//	debugPrint("convert scale ");
	cvConvertScale(sig2, lambda_sig2, (double)9, 0);
	IplImage *Mappo = cvCreateImage(cvGetSize(M), MEAN->depth, M->nChannels);
	cvConvertScale(M, Mappo);
	convertToGrayScale(Mappo, MEAN);
	cvReleaseImage(&Mappo);

	cvReleaseImage(&acc);
	cvReleaseImage(&sqacc);
	cvReleaseImage(&M2);
	cvReleaseImage(&sqaccM);
	cvReleaseImage(&sig2);
	cvReleaseImage(&M);
	///////////////////////////////////

	cout<<"done!\n";
//	debugPrint("it succeed!!\n");
}

void BackgroundRemovalEM::backGroundRemoval(const IplImage *localFrame){
	//For detect FG Condition
//	debugPrint(" foreground extraction operations: ");
	if(cvMean(myForeGroundMaskGray) > 240){
		trainingFrames = 10;
		backGroundCapturing();
		while(cvMean(lambda_sig2) > 200)
			backGroundCapturing();
	}
	IplImage *leftCondBis = cvCreateImage(cvGetSize(leftCond), leftCond->depth, leftCond->nChannels);
	cvSub(MEAN, localFrame, leftCond, NULL);
	cvSub(localFrame, MEAN, leftCondBis, NULL);
//	cvNot(leftCondBis, leftCondBis);
	cvXor(leftCond, leftCondBis, leftCond);
	cvReleaseImage(&leftCondBis);
//	debugPrint(" sub-> ok ");
	cvPow(leftCond, leftCond2, 2);
//	debugPrint(" mul-> ok ... \n");

//	debugPrint("converting operations...");
//	convertToGrayScale(leftCond2, leftConditionGray);
	convertToGrayScale(lambda_sig2, lambda_sig2Gray);
	cvCmp(leftCond2, lambda_sig2Gray, myForeGroundMaskGray, CV_CMP_GE );
//	debugPrint(" foreground extraction complete\n");

	//Compare
	//  leftCondition & gt(:lambda_sig2)
	//to detect foreground.
#if SHOW_BG_REMOVAL == 1
	cvShowImage(winLeftCond, leftCond2);
	cvShowImage(winBg, lambda_sig2Gray);
#endif
}

int BackgroundRemovalEM::compute( const IplImage* src, IplImage* dst){
	IplImage *tempDst = cvCreateImage(cvGetSize(dst), src->depth, src->nChannels);

	if(firstTime){
		backGroundCapturing();
		firstTime = false;
	}
	backGroundRemoval(src);
	cvAnd(src, myForeGroundMaskGray, tempDst);
	convertDepth_8U_to_32F(tempDst, dst);

	cvReleaseImage(&tempDst);
}

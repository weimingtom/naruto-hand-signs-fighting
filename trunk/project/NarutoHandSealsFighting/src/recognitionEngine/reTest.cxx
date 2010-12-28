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

void createTemplateContours();

MovesSet myMoveSet;
SealsMap smap;
const char* winOrig = "originalCapture";
const char* win = "reTestWin";
const char* evaluated = "evaluatedImage";
const char* m = "mask";

IplImage* g_image, *g_gray = NULL;
CvMemStorage* g_storage = NULL;
double g_thresh = 100;
CvSeq * contourTemplate;

int main(int argc, char* argv[]){
	IplImage *temp, *img, *res, *img8u;
	bool done = false;
	int sealIndex = 0;
	double range = 20;
	Move* move;
	int appo;

	sealsFactory->buildSealsMap(&sealsMap);
	movesFactory->buildMovesSet( movesSetGlobal, &sealsMap);
	move = movesSetGlobal->getMove("Lightning Blade");
	if(move == NULL){
		cout<<"DON'T FOUND move!!\n";
	}
	debugPrint("test move name: ");
	debugPrint("%s\n", move->getMoveName().c_str());

	recognitionEngine->setCurrentMove(move);
	recognitionEngine->setEvaluatorFunction(mulEvaluator);

//	recognitionEngine->initEngine();


	for(int i=0; i<10; i++)
		cam->capturing();
//	img = cvCreateImage(cvGetSize(cam->getFrame()), IPL_DEPTH_8U, 3);
//	cvConvertScale(cam->getFrame(), img);

	img=cam->getFrame();

	debugPrint(">captured image\n");

	debugPrint(">created res\n");
	temp = cvCreateImage(cvSize(img->width, img->height),RE_INPUT_IMAGE_DEPTH, 1);
	debugPrint(">created temp\n");
	appo = cvMean(img);
	debugPrint("mean is :%d\n", appo);

	cvNamedWindow(m, CV_WINDOW_AUTOSIZE);
	debugPrint("tryingback ground training: ...");
	/////////////////////////////////////
	//Let's try a background removal:
	/////////////////////////////////////
	const int BG_REMOVAL_TRAINING_FRAMES = 150; //default value of the total frames used in the "training"
	int N = 0; //Number of total frames used in the "training"
	IplImage *frame = cam->getFrame();
	IplImage *acc, *sqacc, *M, *M2, *sqaccM, *sig2, *lambda_sig2;
	IplImage *leftCond, *leftCond2;//, *leftCondition;

	IplImage* MEAN = cvCreateImage(cvGetSize(frame), frame->depth, frame->nChannels);
	IplImage* myForeGroundMask = cvCreateImage(cvGetSize(frame),frame->depth , frame->nChannels);
	IplImage* myForeGroundMaskGray = cvCreateImage(cvGetSize(frame), IPL_DEPTH_8U, 1);
	IplImage *leftConditionGray = cvCreateImage(cvGetSize(frame),frame->depth , 1);
	IplImage *lambda_sig2Gray = cvCreateImage(cvGetSize(frame),frame->depth , 1);

	acc = cvCreateImage(cvGetSize(frame), IPL_DEPTH_32F, frame->nChannels);
	sqacc = cvCreateImage(cvGetSize(frame), IPL_DEPTH_32F, frame->nChannels);
	M = cvCreateImage(cvGetSize(frame),IPL_DEPTH_32F , frame->nChannels);
	M2 = cvCreateImage(cvGetSize(frame),IPL_DEPTH_32F , frame->nChannels);
	sqaccM = cvCreateImage(cvGetSize(frame),IPL_DEPTH_32F , frame->nChannels);
	sig2 = cvCreateImage(cvGetSize(frame), IPL_DEPTH_32F, frame->nChannels);
	lambda_sig2 = cvCreateImage(cvGetSize(frame),frame->depth, frame->nChannels);
	leftCond = cvCreateImage(cvGetSize(frame),frame->depth , frame->nChannels);
	leftCond2 = cvCreateImage(cvGetSize(frame),frame->depth , frame->nChannels);
//	leftCondition = cvCreateImage(cvGetSize(frame), frame->depth, frame->nChannels);

	for(int i=0, N=0; i<BG_REMOVAL_TRAINING_FRAMES; i++){
		cvAcc(frame,acc,NULL);
		cvSquareAcc(frame, sqacc, NULL);
		N++;
		cvConvertScale(acc, M, (double)(1.0/N), 0);
		cvConvertScale(sqacc, sqaccM, (double)(1.0/N),0);
		cvMul( M, M, M2, 1 );
		cvSub( sqaccM, M2, sig2, NULL);//The sig is sig2
		cam->capturing();
		frame = cam->getFrame();
	}
	debugPrint(" out of the cycle ");

	//For detect FG Condition
	debugPrint("\nconvert scale ");
	cvConvertScale(sig2, lambda_sig2, (double)9, 0);
	cvConvertScale(M, MEAN);
	debugPrint(" conversion operations: ");
	cvSub(MEAN, frame, leftCond, NULL);
	debugPrint(" sub-> ok ");
	cvPow(leftCond, leftCond2, 2);
	debugPrint(" mul-> ok ... ");

//	cvShowImage(m, leftCond2);
//	cvWaitKey(0);

	//Compare
	//  leftCondition & gt(:lambda_sig2)
	//to detect foreground.


//	cvReleaseImage(&leftCondition);
	///////////////////////////////////
	debugPrint("it succeed!!\n");


	recognitionEngine->addModule(new BlurEM(CV_GAUSSIAN,25,25));
//	recognitionEngine->addModule(new BlurEM(CV_MEDIAN,27,0,0,0));
//	recognitionEngine->addModule(new HistogramEM());
//	recognitionEngine->addModule(new SobelEM(CV_SCHARR, 1, 0));

	recognitionEngine->addModule(new LaplacianEM(5));
//	recognitionEngine->addModule(new CannyEM(7, appo-range/2, appo+range/2));
//	recognitionEngine->addModule(new CannyEM(5,1,3));
//	recognitionEngine->addModule(new ContoursFinderEM(appo));
//
	recognitionEngine->addModule(new ClosureEM(15));

	cvNamedWindow(win, CV_WINDOW_AUTOSIZE);
	cvNamedWindow(winOrig, CV_WINDOW_AUTOSIZE);
	cvNamedWindow(evaluated, CV_WINDOW_NORMAL);

	cvMoveWindow(winOrig, 20, 100);
	cvMoveWindow(win, 700, 100);
	cvMoveWindow(evaluated, 700, 500);

	debugPrint("createTemplateContours...");
	g_image = move->getMoveSeals().at(sealIndex)->getTemplateImage();
	createTemplateContours();
	debugPrint("done\n");

//	IplImage* src = cam->getFrame();
//	CvScalar  hsv_min = cvScalar(0, 30, 80, 0);
//	CvScalar  hsv_max = cvScalar(20, 150, 255, 0);
//	IplImage* hsv_image = cvCreateImage( sz, 8, 3);
//	IplImage* hsv_mask = cvCreateImage( sz, 8, 1);
//	IplImage* hsv_edge = cvCreateImage( sz, 8, 1);
//	img8u = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);
//			cvCvtColor(src, hsv_image, CV_BGR2HSV);

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
			cvSub(MEAN, img, leftCond, NULL);
			cvPow(leftCond, leftCond2, 2);
//			debugPrint("calculating foreground mask...");
			convertToGrayScale(leftCond2, leftConditionGray);
			convertToGrayScale(lambda_sig2, lambda_sig2Gray);
			cvCmp(leftConditionGray, lambda_sig2Gray, myForeGroundMaskGray, CV_CMP_GE );

//			cvAnd(leftCond2, lambda_sig2, myForeGroundMask);
//			convertToGrayScale(myForeGroundMask, myForeGroundMaskGray);
//			debugPrint("done\n");
			cvShowImage("mask", myForeGroundMaskGray);
			convertToGrayScale(img, temp);

			///////////////////////////////
			cvDrawContours(img, contourTemplate, CV_RGB(255,0,0), CV_RGB(0,0,250),255, 1);
			cvShowImage(winOrig, img);
			///////////////////////////////

//			cvCvtColor(src, hsv_image, CV_BGR2HSV);
//			cvInRangeS (hsv_image, hsv_min, hsv_max, hsv_mask);
//			cvSmooth( hsv_mask, hsv_mask, CV_MEDIAN, 27, 0, 0, 0 );
//			cvCanny(hsv_mask, hsv_edge, 1, 3, 5);

			cvAnd(temp, myForeGroundMaskGray, temp);

//			debugPrint(">convertScale\n");
//			debugPrint(">processing\n");
			res = cvCreateImage(cvSize(img->width, img->height),RE_OUTPUT_IMAGE_DEPTH, 1);
			recognitionEngine->process(temp, res);
			cvShowImage(win, res);
//			debugPrint(">evaluation\n");
			cout<<"score: "<< recognitionEngine->evaluate(res, sealIndex)<<"\n";
			cvShowImage(evaluated, res);


			if( (cvWaitKey(10) & 255) == 27 ){
				done = true;
			}

			if( (cvWaitKey(10) & 255) == 115 ){
				sealIndex = ((sealIndex + 1) % move->getMoveSeals().size());
				g_image = move->getMoveSeals().at(sealIndex)->getTemplateImage();
				createTemplateContours();
			}
			cvReleaseImage(&res);
		}


	/////////////////////////
	//used for background removal:
	cvReleaseImage(&acc);
	cvReleaseImage(&sqacc);
	cvReleaseImage(&M2);
	cvReleaseImage(&sqaccM);
	cvReleaseImage(&sig2);

	cvReleaseImage(&M);
	cvReleaseImage(&lambda_sig2);
	cvReleaseImage(&leftCond);
	cvReleaseImage(&leftCond2);

	cvReleaseImage(&MEAN);

	/////////////////////////

	cvReleaseImage(&temp);
	cvReleaseImage(&img8u);
	cvDestroyWindow(win);
	cvDestroyWindow(winOrig);
	cvDestroyWindow(evaluated);
	cvDestroyWindow("mask");
//	cvDestroyAllWindows();
	/*
	 * and so on...
	 */

	return 0;
}

void createTemplateContours(){
//	IplImage* g_image = cvLoadImage(
//			move->getMoveSeals().at(currentSealIndex)->getTemplateImagePath().c_str());
	if( g_storage != NULL ){
		cvClearMemStorage( g_storage );
		cvReleaseImage(&g_gray);
	}
	g_gray = cvCreateImage( cvGetSize( g_image ), 8, 1 );
	g_storage = cvCreateMemStorage(0);

	contourTemplate = 0;
	if(g_image->nChannels == 1)
		cvConvertScale(g_image, g_gray);
	else
		cvCvtColor( g_image, g_gray, CV_BGR2GRAY );
	cvThreshold( g_gray, g_gray, g_thresh, 255, CV_THRESH_BINARY );
	cvFindContours( g_gray, g_storage, &contourTemplate );
	cvZero( g_gray );
//	cvReleaseImage(&g_image);
}

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
#include "engineModules/All.h"
#include "evaluationFunctions/MulEvaluator.h"
#include "evaluationFunctions/ContoursChecker.h"

#include "processingFunctions/AllProcessingFunctions.h"
#include "engineStrategies/AllStrategies.h"

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
const char *winOrig = "originalCapture";
const char *win = "reTestWin";
const char *evaluated = "evaluatedImage";
const char *m = "mask";

IplImage* g_image, *g_gray = NULL;
CvMemStorage* g_storage = NULL;
double g_thresh = 100;
CvSeq * contourTemplate;

int main(int argc, char* argv[]){
	IplImage *temp, *img, *res, *imgShowing, *myForeGroundMaskGray;
	bool done = false;
	int sealIndex = 0;
	double range = 20;
	Move* move;
	int meanImage;

	/////////////////////////////////////////////
	////// WINDOWS
//	cvNamedWindow(m, CV_WINDOW_AUTOSIZE);
	cvNamedWindow(win, CV_WINDOW_AUTOSIZE);
	cvNamedWindow(winOrig, CV_WINDOW_AUTOSIZE);
	cvNamedWindow(evaluated, CV_WINDOW_NORMAL);

	cvMoveWindow(winOrig, 20, 20);
	cvMoveWindow(win, 650, 20);
	cvMoveWindow(evaluated, 700, 500);
	/////////////////////////////////////////////


	sealsFactory->buildSealsMap(&sealsMap);
	movesFactory->buildMovesSet( movesSetGlobal, &sealsMap);
//	move = movesSetGlobal->getMove("Lightning Blade");
//	move = movesSetGlobal->getMove("Water Dragon");

	//@BUG???
	//Why the Dragon seal is always score: 0 ???????
	move = movesSetGlobal->getMove("Impure World Resurrection");

	if(move == NULL){
		cout<<"DON'T FOUND move!!\n";
	}
	debugPrint("test move name: ");
	debugPrint("%s\n", move->getMoveName().c_str());

	recognitionEngine->setCurrentMove(move);


	for(int i=0; i<10; i++)
		cam->capturing();

	img=cam->getFrame();

	debugPrint(">captured image\n");

	debugPrint(">created res\n");
	temp = cvCreateImage(cvSize(img->width, img->height),RE_INPUT_IMAGE_DEPTH, 1);
	debugPrint(">created temp\n");
	meanImage = cvMean(img);
	debugPrint("mean is :%d\n", meanImage);

	BackgroundRemovalEM *backgroundRemoval = new BackgroundRemovalEM();

//	recognitionEngine->addModule(backgroundRemoval); //<<<<<

//	recognitionEngine->addModule(new HistogramEM());
//	recognitionEngine->addModule(new BlurEM(CV_MEDIAN,27,0,0,0));
//	recognitionEngine->addModule(new SobelEM(CV_SCHARR, 1, 0));
//	recognitionEngine->addModule(new BlurEM(CV_GAUSSIAN,3,3));
//	recognitionEngine->addModule(new CannyEM(7, meanImage-range/2, meanImage+range/2));
//	recognitionEngine->addModule(new ContoursFinderEM(meanImage));
//	recognitionEngine->addModule(new LaplacianEM(7));
//	recognitionEngine->addModule(new CannyEM(5,1,3));

//	recognitionEngine->addModule(new ClosureEM(15));


	//the template creation recipe is:
	////////////////////////////////////////////////////////////
//	recognitionEngine->addModule(new HistogramEM());
//	recognitionEngine->addModule(new SobelEM(CV_SCHARR, 1, 0));
//	recognitionEngine->addModule(new BlurEM(CV_GAUSSIAN,3,3));
//	recognitionEngine->addModule(new LaplacianEM(7));
	////////////////////////////////////////////////////////////


	/**
	 * FOR THE DEMO:
	 * try:
	 *  process function: DifferentTempsAdder
	 *  evaluation function: Multiplier evaluator
	 *  strategy function: AGoodStrategy
	 */

//	recognitionEngine->setProcessFunction(new ChainAdder());
//	recognitionEngine->setProcessFunction(new SimpleChain());
	recognitionEngine->setProcessFunction(new DifferentTempsAdder());
//	recognitionEngine->setProcessFunction(new SChainBGRemoval());

	recognitionEngine->setEvaluatorFunction(mulEvaluator);
	ContoursChecker *cc = new ContoursChecker();
//	recognitionEngine->setEvaluatorFunction(cc);

//	AGoodStrategy *aGoodStrat = new AGoodStrategy(recognitionEngine);
	recognitionEngine->changeEngineStrategy(new AGoodStrategy(recognitionEngine));
	XperienceStrategy *xp = new XperienceStrategy(recognitionEngine);
//	recognitionEngine->changeEngineStrategy(xp);
//	recognitionEngine->setStrategy(aGoodStrat);
//	recognitionEngine->setStrategy(new DefaultStrategy(recognitionEngine));
//	recognitionEngine->changeEngineStrategy(new AGoodStrategy(recognitionEngine));


//	if(recognitionEngine->initEngine()<0){
//		exit(0);
//	}
	//////////////////////////////////////////////

	backgroundRemoval->backGroundCapturing();

	debugPrint("createTemplateContours...");
	g_image = move->getMoveSeals().at(sealIndex)->getTemplateImage();
	createTemplateContours();
	debugPrint("done\n");

	while(!done){

		if( cam->capturing() < 0){				//<- uncomment this line
			cout<<"camera problem!\n";			//<- uncomment this line
			break;								//<- uncomment this line
		}										//<- uncomment this line
		img = cam->getFrame();

//		cvSub(MEAN, img, leftCond, NULL);
//		cvPow(leftCond, leftCond2, 2);
		//			debugPrint("calculating foreground mask...");

//		convertToGrayScale(leftCond2, leftConditionGray);
//		convertToGrayScale(lambda_sig2, lambda_sig2Gray);
//		cvCmp(leftConditionGray, lambda_sig2Gray, myForeGroundMaskGray, CV_CMP_GE );
//		cvThreshold(myForeGroundMaskGray, myForeGroundMaskGray, 200, 255, CV_THRESH_BINARY);

		//			cvAnd(leftCond2, lambda_sig2, myForeGroundMask);
		//			convertToGrayScale(myForeGroundMask, myForeGroundMaskGray);
		//			debugPrint("done\n");
		//			cvShowImage(m, myForeGroundMaskGray);
//		cvShowImage(winLeftCond, myForeGroundMaskGray);
//		cvShowImage(winBg, lambda_sig2Gray);

		///////////////////////////////
		convertToGrayScale(img, temp);
		imgShowing = cvCreateImage(cvGetSize(img), img->depth, img->nChannels);
		cvCopy(img, imgShowing);
		cvDrawContours(imgShowing, contourTemplate, CV_RGB(255,0,0), CV_RGB(0,0,250),255, 1);
		cvShowImage(winOrig, imgShowing);
		cvReleaseImage(&imgShowing);
		///////////////////////////////

		backgroundRemoval->backGroundRemoval(temp);
		myForeGroundMaskGray = backgroundRemoval->getForegroundMask();

//		cvAnd(temp, myForeGroundMaskGray , temp);

//		debugPrint(">convertScale\n");
//		debugPrint(">processing\n");

		res = cvCreateImage(cvSize(img->width, img->height),RE_OUTPUT_IMAGE_DEPTH, 1);
		recognitionEngine->process(temp, res);

//		IplImage *tempRes = cvCreateImage(cvGetSize(res), RE_INPUT_IMAGE_DEPTH, 1);
//		cvConvertScale(res, tempRes);
//		cvAnd(tempRes, myForeGroundMaskGray , tempRes);
//		convertDepth_8U_to_32F(tempRes, res);
//		cvReleaseImage(&tempRes);

		cvShowImage(win, res);

//		debugPrint(">evaluation\n");
		cout<<"score: "<< recognitionEngine->evaluate(res, sealIndex)<<"\n";

//		cout<<"foreground mean: "<< cvMean(myForeGroundMaskGray)<<"\n";

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


	cvReleaseImage(&temp);
	cvDestroyWindow(win);
	cvDestroyWindow(winOrig);
	cvDestroyWindow(evaluated);
//	cvDestroyWindow(m);
	cvDestroyAllWindows();
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
	cvFindContours( g_gray, g_storage, &contourTemplate);
	cvZero( g_gray );
//	cvReleaseImage(&g_image);
}

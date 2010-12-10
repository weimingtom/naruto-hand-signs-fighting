/*
 ******************************************************
 * NAME:
 * TrainingDirector.cxx
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Dec 1, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#include <iostream>
#include <stdio.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "TrainingDirector.h"

#include "../DebugPrint.h"

#define SHOW_SUPPL_WIN 0

TrainingDirector* trainingDirector;

TrainingDirector::TrainingDirector(TrainingWindow* tw, RecognitionEngine* re, Camera* c, Move* m){
	trainingWindow = tw;
	recognitionEngine = re;
	cam = c;
	targetMove = m;
	recognitionEngine->setCurrentMove(m);
	timer = new CountdownTimer(trainingWindow);
}

TrainingDirector::~TrainingDirector() {
	// TODO Auto-generated destructor stub
}

void TrainingDirector::handleShot(int seconds, int sealIndex){
	if(timer->countDown(5) < 0){
		cout<<"cannot start another timer... probably you have just a seal acting?\n";
	}
}

void TrainingDirector::elapsedTimer(){
	IplImage* photo;
	IplImage* grayImage;
	IplImage* res;
	int score;
	try{
		debugPrint("photo shot\n");
		cam->shotAPhoto();
		photo = cam->getPhotoShot();
		res = cvCreateImage(cvSize(photo->width, photo->height),
				IPL_DEPTH_32F, 1);
		grayImage = cvCreateImage(cvSize(photo->width, photo->height),
						DEFAULT_INPUT_DEPTH, 1);
		cvCvtColor(photo, grayImage, CV_BGR2GRAY);

		debugPrint("processing\n");
		recognitionEngine->process(grayImage, res);
		debugPrint("evaluation\n");
		score = recognitionEngine->evaluate(res, trainingWindow->getCurrentSealIndex());
		cout<<"your score is: "<<score<<"\n";
		trainingWindow->updateScore(score);
		trainingWindow->incrementCurrentSealIndex();
#if SHOW_SUPPL_WIN == 1
		cvNamedWindow("mu",CV_WINDOW_AUTOSIZE);
		cvShowImage("mu", res);
#endif

	}catch(cv::Exception e){
		cout<<e.msg;
	}catch(std::exception e){
		cout<<e.what();
	}
#if SHOW_SUPPL_WIN == 1
	cvWaitKey(3000);
	cvDestroyWindow("mu");
#endif

}

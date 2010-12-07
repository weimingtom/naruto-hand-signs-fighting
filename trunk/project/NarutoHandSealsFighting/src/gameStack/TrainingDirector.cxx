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

TrainingDirector* trainingDirector;

TrainingDirector::TrainingDirector(TrainingWindow* tw, RecognitionEngine* re, Camera* c, Move* m){
	trainingWindow = tw;
	recognitionEngine = re;
	cam = c;
	targetMove = m;
	recognitionEngine->setCurrentMove(m);
}

TrainingDirector::~TrainingDirector() {
	// TODO Auto-generated destructor stub
}

void TrainingDirector::handleShot(int seconds, int sealIndex){
	timer = new CountdownTimer(trainingWindow);
	timer->countDown(5);
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
		cvNamedWindow("mu",CV_WINDOW_AUTOSIZE);
		//	cvFlip(photo, photo, 1);
		cvShowImage("mu", res);

	}catch(cv::Exception e){
		cout<<e.msg;
	}catch(std::exception e){
		cout<<e.what();
	}
	cvWaitKey(3000);
	cvDestroyWindow("mu");

}

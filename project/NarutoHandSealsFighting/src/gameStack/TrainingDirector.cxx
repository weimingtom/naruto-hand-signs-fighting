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

//TrainingDirector* trainingDirector;

TrainingDirector::TrainingDirector(TrainingWindow* tw, RecognitionEngine* re, Camera* c, Move* m){
//	debugPrint("TrainingDirector constructor: camera? %s\n", cam->getPiggyBackCamera());
	trainingWindow = tw;
	recognitionEngine = re;
//	cam = c;
	targetMove = m;
	totalScore = 0;
	recognitionEngine->setCurrentMove(m);
	timer = new CountdownTimer(trainingWindow);
}

TrainingDirector::~TrainingDirector() {
	// TODO Auto-generated destructor stub
	delete timer;
	delete trainingWindow;
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
//		debugPrint("photo shot\n");
		cam->shotAPhoto();
		photo = cam->getPhotoShot();
		res = cvCreateImage(cvSize(photo->width, photo->height),
				IPL_DEPTH_32F, 1);
		grayImage = cvCreateImage(cvSize(photo->width, photo->height),
						DEFAULT_INPUT_DEPTH, 1);
		cvCvtColor(photo, grayImage, CV_BGR2GRAY);

//		debugPrint("processing\n");
		recognitionEngine->process(grayImage, res);
//		debugPrint("evaluation\n");
		score = recognitionEngine->evaluate(res, trainingWindow->getCurrentSealIndex());
		totalScore += score;
		cout<<"your score is: "<<score<<"\n";
		trainingWindow->updateScore(score);
		trainingWindow->incrementCurrentSealIndex();
		if(lastSealInMove()){
			totalScore = totalScore / targetMove->getMoveSeals().size();
			trainingWindow->setTotalScore(totalScore);
			debugPrint("this is the last seal...\n"
					"total score is: %g\n",totalScore);
		}

#if SHOW_SUPPL_WIN == 1
		cvNamedWindow("mu",CV_WINDOW_AUTOSIZE);
		cvShowImage("mu", res);
#endif

	}catch(cv::Exception e){
		cout<<e.msg<<"\n";
	}catch(std::exception e){
		cout<<e.what()<<"\n";
	}
#if SHOW_SUPPL_WIN == 1
	cvWaitKey(3000);
	cvDestroyWindow("mu");
#endif

}

bool TrainingDirector::lastSealInMove(){
	//we want to show the total score only after the last seal
	return trainingWindow->getCurrentSealIndex() == targetMove->getMoveSeals().size();
}

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
#include "../recognitionEngine/RecognitionEngineDefaults.h"

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
	cout<<"current move is: "<<targetMove->getMoveName()<<"\n";
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
	int score, maxScore = 0;

	try{
		for(int i=0; i<SHOOTING_FRAMES; i++){
			score = processActualScore();
			if(score > maxScore)
				maxScore = score;
		}

		if(maxScore > 100)
			maxScore = 100;
		totalScore += maxScore;

		cout<<"your score for "<<targetMove->getMoveSeals().at(
				trainingWindow->getCurrentSealIndex())->getName()
				<<" is: "<<score<<"\n";

		trainingWindow->updateScore(score);
		trainingWindow->incrementCurrentSealIndex();
		if(lastSealInMove()){
			totalScore = totalScore / targetMove->getMoveSeals().size();
			trainingWindow->setTotalScore(totalScore);
			debugPrint("this is the last seal...\n"
					"total score is: %g\n",totalScore);
		}

	}catch(cv::Exception e){
		cout<<e.msg<<"\n";
	}catch(std::exception e){
		cout<<e.what()<<"\n";
	}
}

bool TrainingDirector::lastSealInMove(){
	//we want to show the total score only after the last seal
	return trainingWindow->getCurrentSealIndex() == targetMove->getMoveSeals().size();
}

int TrainingDirector::processActualScore(){
	IplImage* frame;
	IplImage* grayImage;
	IplImage* res;
	int localScore;

//	debugPrint("photo shot\n");
//	cam->shotAPhoto();
//	photo = cam->getPhotoShot();

	if(trainingWindow->getCurrentSealIndex() < targetMove->getMoveSeals().size()){

		cam->capturing();
		frame = cam->getFrame();
		grayImage = cvCreateImage(cvGetSize(frame), RE_INPUT_IMAGE_DEPTH, 1);
		res = cvCreateImage(cvGetSize(frame), RE_OUTPUT_IMAGE_DEPTH, 1);
		cvCvtColor(frame, grayImage, CV_BGR2GRAY);

		//		debugPrint("processing\n");
		recognitionEngine->process(grayImage, res);
		//		debugPrint("evaluation\n");
		localScore = recognitionEngine->evaluate(res, trainingWindow->getCurrentSealIndex());

		cvReleaseImage(&grayImage);
		cvReleaseImage(&res); //<- should we use res for an output to the user?
	}else{
		localScore = 0;
	}

#if SHOW_SUPPL_WIN == 1
		cvNamedWindow("mu",CV_WINDOW_AUTOSIZE);
		cvShowImage("mu", res);
		cvWaitKey(3000);
		cvDestroyWindow("mu");
#endif

	return localScore;
}

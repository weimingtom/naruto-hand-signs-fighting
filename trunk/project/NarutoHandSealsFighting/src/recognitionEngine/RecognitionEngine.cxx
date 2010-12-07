/*
 * RecognitionEngine.cxx
 *
 *  Created on: Nov 13, 2010
 *      Author: michele
 */

#include <iostream>
#include <algorithm>
#include "RecognitionEngine.h"

using namespace std;

RecognitionEngine *recognitionEngine = RecognitionEngine::instantiate();

RecognitionEngine* RecognitionEngine::engine = NULL;

RecognitionEngine::RecognitionEngine(){
	temp == NULL;
	evaluator = NULL;
	currentMove = NULL;
	strategy = new DefaultStrategy();
}


void RecognitionEngine::setEvaluatorFunction(EvaluatorFunctionTemplate* eval){
	evaluator = eval;
}

int RecognitionEngine::process(const IplImage* src, IplImage* res){
//	IplImage* temp = cvCreateImage(cvSize(src->width, src->height),
//			src->depth, src->nChannels);
	//!!! #REMINDER !!!
	// each time the process enters this function needs to recreate the
	// temp image, otherwise we'll get a type check errror!
//	if(temp == NULL)
	temp = cvCreateImage(cvSize(src->width, src->height), RE_OUTPUT_IMAGE_DEPTH, src->nChannels);

	for(int i=0; i<modulesArray.size(); i++){
		try{
			modulesArray.at(i)->compute(src, temp);
		}catch(cv::Exception e){
			cout<<"EXCEPTION in " << modulesArray.at(i)->getModuleName() << "\n";
			cout<<e.err<<"\n";
		}
		cvAdd(res, temp, res);
	}
}

int RecognitionEngine::findModuleByID(EngineModule* m){
	int ret = -1;
	long int target = m->getModuleID();
	for(int i=0; i<modulesArray.size(); i++){
		if(modulesArray.at(i)->getModuleID() == target)
			ret = i;
	}
	return ret;
}

void RecognitionEngine::setCurrentMove(Move* m){
	currentMove = m;
}

int RecognitionEngine::evaluate(IplImage* img, int sealIndex){
	int ret;
	try{
		ret = evaluator->evaluate(img, currentMove, sealIndex);
	}catch(cv::Exception e){
		cout<<"Exception in the evaluator: "<<evaluator->getEvaluatorName()<<"\n";
		cout<<e.msg;
		ret = -1;
	}
	return ret;

}

int RecognitionEngine::initEngine(){
	if(strategy != NULL){
		strategy->initModules();
		return 1;
	}else
		return -1;
}

void RecognitionEngine::changeEngineStrategy(AbstractStrategy* newStrategy){
	if(newStrategy != NULL){
		modulesArray.clear();
		strategy= newStrategy;
		initEngine();
	}
}

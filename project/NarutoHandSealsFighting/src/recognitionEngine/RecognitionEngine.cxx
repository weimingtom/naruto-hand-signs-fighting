/*
 * RecognitionEngine.cxx
 *
 *  Created on: Nov 13, 2010
 *      Author: michele
 */

#include <iostream>
#include <algorithm>
#include "RecognitionEngine.h"
#include "../DebugPrint.h"

using namespace std;

RecognitionEngine *recognitionEngine = RecognitionEngine::instantiate();

RecognitionEngine* RecognitionEngine::engine = NULL;

RecognitionEngine::RecognitionEngine(){
	temp == NULL;
	currentMove = NULL;
	evaluator = NULL;
	strategy = new DefaultStrategy(this);
	processingFunction = new DifferentTempsAdder();
//	processingFunction = new ChainAdder();
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

//	temp = cvCreateImage(cvSize(src->width, src->height), RE_OUTPUT_IMAGE_DEPTH, src->nChannels);
//	IplImage * tempRes = cvCreateImage(cvSize(src->width, src->height),
//			RE_OUTPUT_IMAGE_DEPTH, src->nChannels);
//	cvConvertScale(src, tempRes);
//
////	cout<<"modules applied:\n";
//	for(int i=0; i<modulesArray.size(); i++){
//		try{
//			modulesArray.at(i)->compute(tempRes, temp);
////			cout<<modulesArray.at(i)->getModuleName()<<"\n";
//		}catch(cv::Exception e){
//			cout<<"EXCEPTION in " << modulesArray.at(i)->getModuleName() << "\n";
//			cout<<e.err<<"\n";
//		}
//		cvAdd(tempRes, temp, tempRes);
//	}
//	cvConvertScale(tempRes, res);
//	cvReleaseImage(&temp);
//	cvReleaseImage(&tempRes);

	processingFunction->processFunction(modulesArray, src, res);
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
//		debugPrint("evaluating move: %s\n", currentMove->getMoveName().c_str());
//		debugPrint("seal: %s\n", currentMove->getMoveSeals().at(sealIndex)->getName().c_str());
//		debugPrint("template path: %s\n",currentMove->getMoveSeals().at(sealIndex)->getTemplateImagePath().c_str());
		ret = evaluator->evaluate(img, currentMove, sealIndex);
	}catch(cv::Exception e){
		cout<<"Exception in the evaluator: "<<evaluator->getEvaluatorName()<<"\n";
		cout<<e.msg;
		ret = -1;
	}
	return ret;

}

int RecognitionEngine::initEngine(){
	int ret =0;
	if(strategy != NULL){
		strategy->initModules();
		ret = 1;
	}else{
		ret = -1;
		cout<<"strategy module not initialized\n";
	}
	if(evaluator == NULL){
		evaluator = mulEvaluator;
		cout<<"using default evaluator "<<evaluator->getEvaluatorName()<<"\n";
	}else{
		cout<<"evaluator: "<<evaluator->getEvaluatorName()<<"\n";
	}
	return ret;
}

void RecognitionEngine::changeEngineStrategy(AbstractStrategy* newStrategy){
	if(newStrategy != NULL){
		modulesArray.clear();
		strategy= newStrategy;
		initEngine();
	}
}

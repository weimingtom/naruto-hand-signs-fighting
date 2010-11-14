/*
 * RecognitionEngine.cxx
 *
 *  Created on: Nov 13, 2010
 *      Author: michele
 */

#include <iostream>
#include "RecognitionEngine.h"

#define OUTPUT_IMAGE_DEPTH IPL_DEPTH_32F

using namespace std;

RecognitionEngine::RecognitionEngine(){
	temp == NULL;
}

int RecognitionEngine::process(IplImage* src, IplImage* res){
//	IplImage* temp = cvCreateImage(cvSize(src->width, src->height),
//			src->depth, src->nChannels);
	if(temp == NULL)
		temp = cvCreateImage(cvSize(src->width, src->height), OUTPUT_IMAGE_DEPTH, src->nChannels);

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


void RecognitionEngine::addModule(EngineModule* m){
	modulesArray.push_back(m);
}

void RecognitionEngine::removeModule(EngineModule* m){
	long int targetIndex = m->getModuleID();
	int i=0;
	for(vector<EngineModule*>::iterator it = modulesArray.begin();
			it != modulesArray.end();
			it++, i++){
		if( modulesArray.at(i)->getModuleID() == targetIndex )
			modulesArray.erase(it);
	}
}

/*
 * RecognitionEngine.cxx
 *
 *  Created on: Nov 13, 2010
 *      Author: michele
 */

#include "RecognitionEngine.h"

//RecognitionEngine recognitionEngine;

int RecognitionEngine::process(IplImage* src, IplImage* res){
	IplImage* temp = cvCreateImage(cvSize(src->width, src->height),
			src->depth, src->nChannels);
	for( int i=0; i<modulesArray.size(); i++){
		modulesArray.at(i)->compute(src, temp);

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

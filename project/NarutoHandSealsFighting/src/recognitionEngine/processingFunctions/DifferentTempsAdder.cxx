/*
 ******************************************************
 * NAME:
 * DifferentTempsAdder.cxx
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Dec 27, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#include "DifferentTempsAdder.h"
#include <iostream>
#include "../RecognitionEngineDefaults.h"

DifferentTempsAdder::DifferentTempsAdder() {
	processingFunctionName = "DifferentTempsAdder";
}

DifferentTempsAdder::~DifferentTempsAdder() {
}

int DifferentTempsAdder::processFunction(std::vector<EngineModule*> *modArray,
		const IplImage* src, IplImage* res){

	IplImage* temp = cvCreateImage(cvSize(src->width, src->height), RE_OUTPUT_IMAGE_DEPTH, src->nChannels);

//	cout<<"modules applied:\n";
	for(int i=0; i<modArray->size(); i++){
		try{
			modArray->at(i)->compute(src, temp);
			cvAdd(res, temp, res);
//			cout<<modArray.at(i)->getModuleName()<<"\n";
		}catch(cv::Exception e){
			cout<<"EXCEPTION in " << modArray->at(i)->getModuleName() << "\n";
			cout<<e.err<<"\n";
		}
	}
	cvReleaseImage(&temp);
}

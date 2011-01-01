/*
 ******************************************************
 * NAME:
 * ChainAdder.cxx
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

#include "ChainAdder.h"
#include <iostream>
#include "../ImageProcessing.h"
#include "../RecognitionEngineDefaults.h"

ChainAdder::ChainAdder() {
	processingFunctionName = "Chain Adder";
}

ChainAdder::~ChainAdder() {
	// TODO Auto-generated destructor stub
}

int ChainAdder::processFunction(std::vector<EngineModule*> *modArray,
		const IplImage* src, IplImage* res){

	IplImage * tempSrc = cvCreateImage(cvGetSize(src), RE_INPUT_IMAGE_DEPTH, src->nChannels);
	IplImage* tempRes = cvCreateImage(cvGetSize(res), RE_OUTPUT_IMAGE_DEPTH, res->nChannels);
	cvConvertScale(src, tempSrc);
	cvZero(res);

	//	cout<<"modules applied:\n";
	for(int i=0; i<modArray->size(); i++){
		try{
			modArray->at(i)->compute(tempSrc, tempRes);
			cvAdd(res, tempRes, res);
			cvConvertScale(res, tempSrc);
//			cout<<modArray.at(i)->getModuleName()<<"\n";
		}catch(cv::Exception e){
			cout<<"EXCEPTION in " << modArray->at(i)->getModuleName() << "\n";
			cout<<e.err<<"\n";
		}
	}

	cvReleaseImage(&tempRes);
	cvReleaseImage(&tempSrc);
}

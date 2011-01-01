/*
 ******************************************************
 * NAME:
 * SimpleChain.cxx
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Dec 30, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#include "SimpleChain.h"
#include <iostream>
#include "../ImageProcessing.h"
#include "../RecognitionEngineDefaults.h"

using namespace std;

SimpleChain::SimpleChain() {
	processingFunctionName = "SimpleChain";
}

SimpleChain::~SimpleChain() {
	// TODO Auto-generated destructor stub
}

int SimpleChain::processFunction(std::vector<EngineModule*> *modArray,
		const IplImage* src, IplImage* res){

	IplImage * tempSrc = cvCreateImage(cvGetSize(src), RE_INPUT_IMAGE_DEPTH, src->nChannels);
	cvConvertScale(src, tempSrc);

	//	cout<<"modules applied:\n";
	for(int i=0; i<modArray->size(); i++){
		try{
			modArray->at(i)->compute(tempSrc, res);
			cvConvertScale(res, tempSrc);
//			cout<<modArray.at(i)->getModuleName()<<"\n";
		}catch(cv::Exception e){
			cout<<"EXCEPTION in " << modArray->at(i)->getModuleName() << "\n";
			cout<<e.err<<"\n";
		}
	}

	cvReleaseImage(&tempSrc);
}

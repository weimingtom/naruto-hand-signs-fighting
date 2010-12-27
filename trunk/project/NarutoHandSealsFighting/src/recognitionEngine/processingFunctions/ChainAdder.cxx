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
#include "../RecognitionEngineDefaults.h"

ChainAdder::ChainAdder() {
	// TODO Auto-generated constructor stub

}

ChainAdder::~ChainAdder() {
	// TODO Auto-generated destructor stub
}

int ChainAdder::processFunction(std::vector<EngineModule*> modArray,
		const IplImage* src, IplImage* res){

	IplImage* temp = cvCreateImage(cvSize(src->width, src->height), RE_OUTPUT_IMAGE_DEPTH, src->nChannels);
	IplImage * tempRes = cvCreateImage(cvSize(src->width, src->height),
			RE_INPUT_IMAGE_DEPTH, src->nChannels);
	cvConvertScale(src, res);

	//	cout<<"modules applied:\n";
	for(int i=0; i<modArray.size(); i++){
		try{
			cvConvertScale(res, tempRes);
			modArray.at(i)->compute(tempRes, temp);
			cvAdd(res, temp, res);
//			cout<<modArray.at(i)->getModuleName()<<"\n";
		}catch(cv::Exception e){
			cout<<"EXCEPTION in " << modArray.at(i)->getModuleName() << "\n";
			cout<<e.err<<"\n";
		}
	}
	cvReleaseImage(&temp);
	cvReleaseImage(&tempRes);
}

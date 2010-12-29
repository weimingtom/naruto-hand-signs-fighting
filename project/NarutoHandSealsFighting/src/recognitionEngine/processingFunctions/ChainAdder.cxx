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
	// TODO Auto-generated constructor stub

}

ChainAdder::~ChainAdder() {
	// TODO Auto-generated destructor stub
}

int ChainAdder::processFunction(std::vector<EngineModule*> modArray,
		const IplImage* src, IplImage* res){

	IplImage* temp = cvCreateImage(cvGetSize(src), RE_OUTPUT_IMAGE_DEPTH, src->nChannels);
	IplImage * tempRes = cvCreateImage(cvGetSize(src), RE_INPUT_IMAGE_DEPTH, src->nChannels);
//	convertDepth_8U_to_32F(src, res);
	cvConvertScale(src, tempRes);

	//	cout<<"modules applied:\n";
	for(int i=0; i<modArray.size(); i++){
		try{
			modArray.at(i)->compute(tempRes, temp);
			cvAdd(res, temp, res);
			cvConvertScale(res, tempRes);
//			cvMul(res,temp,res);
//			cout<<modArray.at(i)->getModuleName()<<"\n";
		}catch(cv::Exception e){
			cout<<"EXCEPTION in " << modArray.at(i)->getModuleName() << "\n";
			cout<<e.err<<"\n";
		}
	}
	cvReleaseImage(&temp);
	cvReleaseImage(&tempRes);
}

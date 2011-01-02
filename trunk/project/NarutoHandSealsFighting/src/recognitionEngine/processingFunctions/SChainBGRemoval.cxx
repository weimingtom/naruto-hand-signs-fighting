/*
 ******************************************************
 * NAME:
 * SChainBGRemoval.cxx
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Jan 1, 2011
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#include "SChainBGRemoval.h"
#include <iostream>
#include "../../DebugPrint.h"
#include "../RecognitionEngineDefaults.h"

using namespace std;

SChainBGRemoval::SChainBGRemoval() {
	processingFunctionName = "SChainBGRemoval";
	backgroundRemoval = new BackgroundRemovalEM();
	backgroundRemoval->backGroundCapturing();
	myForeGroundMaskGray = backgroundRemoval->getForegroundMask();
	simpleChain = new SimpleChain();
}

SChainBGRemoval::~SChainBGRemoval() {
	// TODO Auto-generated destructor stub
}

int SChainBGRemoval::processFunction(std::vector<EngineModule*> *modArray,
				const IplImage* src, IplImage* res){
//	if(firstTime){
//		backgroundRemoval->backGroundCapturing();
//		firstTime = false;
//	}

	//check:
//	debugPrint("inserted modules:\n");
//	for(int i=0; i<modArray->size(); i++){
//		debugPrint(" ->%s\n", modArray->at(i)->getModuleName());
//	}
	try{
//		IplImage *temp = cvCreateImage(cvSize(src->width, src->height),RE_INPUT_IMAGE_DEPTH, 1);
//		convertToGrayScale(src, temp);
		backgroundRemoval->backGroundRemoval(src);

//		debugPrint("before processFunction ... ");
//		SimpleChain::processFunction(modArray, src, res);
		simpleChain->processFunction(modArray, src, res);
//		debugPrint("done\n");

		IplImage *tempRes = cvCreateImage(cvGetSize(res), RE_INPUT_IMAGE_DEPTH, 1);
		cvConvertScale(res, tempRes);
//		debugPrint("before And\n");
		cvAnd(tempRes, myForeGroundMaskGray , tempRes);
		convertDepth_8U_to_32F(tempRes, res);
//		debugPrint("done conversion and filtering\n");

		cvReleaseImage(&tempRes);
//		cvReleaseImage(&temp);

//		debugPrint("end of SChainBGRemoval processFunction\n");
	}catch(cv::Exception e){
		cout<<e.what()<<"\n";

	}

}

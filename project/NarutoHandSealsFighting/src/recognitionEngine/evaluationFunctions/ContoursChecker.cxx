/*
 ******************************************************
 * NAME:
 * ContoursChecker.cxx
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

#include <iostream>
#include <opencv/highgui.h>
#include "ContoursChecker.h"
#include "../ImageProcessing.h"
#include "../../DebugPrint.h"

using namespace std;

ContoursChecker::ContoursChecker() {
	contourTemplate = new ContoursFinderEM();
	contourImage = new ContoursFinderEM();
}

ContoursChecker::~ContoursChecker() {
	delete contourTemplate;
	delete contourImage;
}

int ContoursChecker::evaluate(IplImage* img, Move* currMove, int sealIndex){
	int result = 0;
	double appoRes;
	IplImage *templateImg = currMove->getMoveSeals().at(sealIndex)->getTemplateImage();
	int resultW = img->width - templateImg->width + 1;
	int resultH = img->height - templateImg->height +1;
	CvSeq *contourTempl, *contourImg;
	IplImage *resImg = cvCreateImage(cvSize(resultW, resultH), IPL_DEPTH_32F, 1) ;
	CvContourTree *imgTree, *templTree;
	CvMemStorage *memImgTree = cvCreateMemStorage(0), *memTemplTree = cvCreateMemStorage(0);

	const char* u = "imageContour";
	const char* v = "templateContour";
	cvNamedWindow(u, CV_WINDOW_NORMAL);
	cvNamedWindow(v, CV_WINDOW_NORMAL);

	try{
		IplImage *templateContourImg = cvCreateImage(cvGetSize(templateImg), IPL_DEPTH_32F, 1);
//		contourTemplate->setContourRetrievalMode(CV_RETR_TREE);
		contourTemplate->compute(templateImg, templateContourImg);
		contourTempl = contourTemplate->getContours();
//		templTree = cvCreateContourTree(contourTempl, memTemplTree, 0);

//		debugPrint("contourTemplate: done\n");

		IplImage *inputContImg = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);
		IplImage *imageContourImg = cvCreateImage(cvGetSize(img), IPL_DEPTH_32F, 1);
//		cvConvertScale(img, inputContImg);
		convertDepth_8U_to_32F(img, inputContImg);
//		contourImage->setContourRetrievalMode(CV_RETR_TREE);
		contourImage->compute(inputContImg, imageContourImg);
		contourImg = contourImage->getContours();
//		debugPrint("contourImage: done\n");

//		debugPrint("creating contour tree:...");
//		imgTree = cvCreateContourTree(contourImg, memImgTree, 0);
//		debugPrint("done\n");

		cvShowImage(v, templateContourImg);
		cvShowImage(u, imageContourImg);

		debugPrint("starting the match ...");
		if(!contourImg || !contourTempl)
			result = 0;
		else{
			appoRes = cvMatchShapes(contourTempl, contourImg, CV_CONTOURS_MATCH_I2);
//			appoRes = cvMatchContourTrees(templTree, imgTree, CV_CONTOUR_TREES_MATCH_I1, 0);
			//		debugPrint("done\n");

			cout<<"appoRes: "<<appoRes<<"\n";


			result = appoRes*100;

			//		cvAdd(img, resImg, img);
			//		cvConvertScale(resImg, img);
		}
		cvReleaseMemStorage(&memImgTree);
		cvReleaseMemStorage(&memTemplTree);

		cvReleaseImage(&templateContourImg);
		cvReleaseImage(&imageContourImg);
		cvReleaseImage(&inputContImg);

	}catch(cv::Exception e ){
		cout<<e.msg<<"\n";
	}

	cvReleaseImage(&resImg);
	return result;

}

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

//	const char* u = "imageContour";
//	const char* v = "templateContour";
//	cvNamedWindow(u, CV_WINDOW_AUTOSIZE);
//	cvNamedWindow(v, CV_WINDOW_AUTOSIZE);

	try{
		IplImage *templateContourImg = cvCreateImage(cvGetSize(templateImg), IPL_DEPTH_32F, 1);
		contourTemplate->compute(templateImg, templateContourImg);
		contourTempl = contourTemplate->getContours();
//		debugPrint("contourTemplate: done\n");
		//		cvShowImage(u, templateContourImg);
		//		cvWaitKey(1);

		IplImage *imageContourImg = cvCreateImage(cvGetSize(img), IPL_DEPTH_32F, 1);
		IplImage *inputContImg = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);
		cvConvertScale(img, inputContImg);
		contourImage->compute(inputContImg, imageContourImg);
		contourImg = contourImage->getContours();
//		debugPrint("contourImage: done\n");

//		debugPrint("starting the match ...");
		appoRes = cvMatchShapes(contourTempl, contourImg, CV_CONTOURS_MATCH_I3);
//		debugPrint("done\n");

		cout<<"appoRes: "<<appoRes<<"\n";

//		cvShowImage(u, imageContourImg);
//		cvShowImage(v, templateContourImg);
//		cvWaitKey(1);

		result = appoRes*100;

//		cvConvertScale(resImg, img);
		img->maskROI = resImg;

		cvReleaseImage(&templateContourImg);
		cvReleaseImage(&imageContourImg);
		cvReleaseImage(&inputContImg);

	}catch(cv::Exception e ){
		cout<<e.msg<<"\n";
	}

	cvReleaseImage(&resImg);
	return result;

}

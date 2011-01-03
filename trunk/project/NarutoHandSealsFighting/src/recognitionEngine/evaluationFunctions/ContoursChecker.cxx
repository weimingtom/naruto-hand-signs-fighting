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
#include "../RecognitionEngineDefaults.h"
#include "../ImageProcessing.h"
#include "../../DebugPrint.h"

#define SHOW_WINDOWS 0

using namespace std;

ContoursChecker::ContoursChecker() {
	contourTemplate = new ContoursFinderEM();
	contourImage = new ContoursFinderEM();
	evaluatorName = "ContoursChecker";
}

ContoursChecker::~ContoursChecker() {
	delete contourTemplate;
	delete contourImage;
}

int ContoursChecker::evaluate(IplImage* img, Move* currMove, int sealIndex){
	int result = 0;
	double appoRes;
	IplImage *templateImg = currMove->getMoveSeals().at(sealIndex)->getTemplateImage();
	CvMemStorage *g_storage_templ = cvCreateMemStorage(0), *g_storage_img = cvCreateMemStorage(0);
	CvSeq *contourTempl, *contourImg;
//	CvSeq *hullTempl, *hullImg;

//	int resultW = img->width - templateImg->width + 1;
//	int resultH = img->height - templateImg->height +1;
//	IplImage *resImg = cvCreateImage(cvSize(resultW, resultH), RE_OUTPUT_IMAGE_DEPTH, 1) ;
//	CvContourTree *imgTree, *templTree;
//	CvMemStorage *memImgTree = cvCreateMemStorage(0), *memTemplTree = cvCreateMemStorage(0);

#if SHOW_WINDOWS ==1
	const char* winImageContour = "imageContour";
	const char* winTemplateContour = "templateContour";
	cvNamedWindow(winImageContour, CV_WINDOW_NORMAL);
	cvNamedWindow(winTemplateContour, CV_WINDOW_NORMAL);
	cvMoveWindow(winImageContour, 800, 800);
	cvMoveWindow(winTemplateContour, 1200,800);
#endif


	try{
//		contourTemplate->setContourRetrievalMode(CV_RETR_TREE);
//		contourTemplate->compute(templateImg, templateContourImg);
//		contourTempl = contourTemplate->getContours();
		cvFindContours( templateImg, g_storage_templ, &contourTempl, sizeof(CvContour), CV_RETR_LIST,
				CV_CHAIN_APPROX_NONE, cvPoint(0,0));
//		if (contourTempl)
//			contourTempl = cvApproxPoly( contourTempl, sizeof(CvContour), g_storage_templ,
//					CV_POLY_APPROX_DP, 3, 1 );
//		hullTempl = cvConvexHull2( contourTempl, 0, CV_CLOCKWISE, 0 );
//		templTree = cvCreateContourTree(contourTempl, memTemplTree, 0);
//		debugPrint("contourTemplate: done\n");


		IplImage *imgTemp = cvCreateImage(cvGetSize(img), RE_INPUT_IMAGE_DEPTH, img->nChannels);
		cvConvertScale(img, imgTemp);
		cvThreshold(imgTemp, imgTemp, 0, 255, CV_THRESH_OTSU);
//		convertDepth_8U_to_32F(img, imgTemp);
//		contourImage->setContourRetrievalMode(CV_RETR_TREE);
//		contourImage->compute(imgTemp, imageContourImg);
//		contourImg = contourImage->getContours();
		cvFindContours( imgTemp, g_storage_img, &contourImg, sizeof(CvContour), CV_RETR_LIST,
				CV_CHAIN_APPROX_NONE, cvPoint(0,0));
//		if (contourImg)
//			contourImg = cvApproxPoly( contourImg, sizeof(CvContour), g_storage_img,
//					CV_POLY_APPROX_DP, 3, 1 );
//		hullImg = cvConvexHull2( contourImg, 0, CV_CLOCKWISE, 0 );
//		debugPrint("creating contour tree:...");
//		imgTree = cvCreateContourTree(contourImg, memImgTree, 0);
//		debugPrint("done\n");
//		debugPrint("contourImage: done\n");

#if SHOW_WINDOWS ==1
		IplImage *templateContourImg = cvCreateImage(cvGetSize(templateImg), RE_OUTPUT_IMAGE_DEPTH, 1);
		cvDrawContours( templateContourImg, contourTempl, cvScalarAll(255), cvScalarAll(255), 1,1);
		IplImage *imageContourImg = cvCreateImage(cvGetSize(img), RE_OUTPUT_IMAGE_DEPTH, 1);
		cvDrawContours( imageContourImg, contourImg, cvScalarAll(255), cvScalarAll(255), 1,1);
		cvShowImage(winTemplateContour, templateContourImg);
		cvShowImage(winImageContour, imageContourImg);
#endif

//		debugPrint("starting the match ...");
		if(!contourImg || !contourTempl){
			if(!contourImg){
				cout<<"didn't find a contour for the image\n";
			}else if(!contourTempl){
				cout<<"didn't find a contour into the template\n";
			}
			result = 0;
		}else{
			appoRes = cvMatchShapes(contourTempl, contourImg, CV_CONTOURS_MATCH_I3);
//			appoRes = cvMatchContourTrees(templTree, imgTree, CV_CONTOUR_TREES_MATCH_I1, 0);
//			debugPrint("done\n");

//			cout<<"appoRes: "<<appoRes<<"\n";


			result = appoRes*100;

			//		cvAdd(img, resImg, img);
			//		cvConvertScale(resImg, img);
		}

//		cvReleaseMemStorage(&memImgTree);
//		cvReleaseMemStorage(&memTemplTree);

		cvReleaseMemStorage(&g_storage_img);
		cvReleaseMemStorage(&g_storage_templ);
		cvReleaseImage(&imgTemp);

#if SHOW_WINDOWS ==1
		cvReleaseImage(&templateContourImg);
		cvReleaseImage(&imageContourImg);
#endif

	}catch(cv::Exception e ){
		cout<<e.msg<<"\n";
	}

//	cvReleaseImage(&resImg);
	return result;

}

/*
 ******************************************************
 * NAME:
 * templateCreatorLauncer.cxx
 ******************************************************
 * DESCRIPTION:
 *
 * Produces a template for each image found in the input path
 ******************************************************
 *	Created on: Nov 22, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#include <iostream>
#include <string>
#include "strings.h"
#include "TemplateCreator.h"
//#include "templateCreatorLauncher.h"

using namespace std;

const string outPath = "../movesTemplates/";
const string srcPath = "../../src/templatesCreationSection/sourceRawImages/";

void help();

int main(int argc, char* argv[]){
	IplImage *temp, *img, *res;
	string outName, imgPath;

	if(argc < 3){
		cout<<"usage:\n";
		cout<<argv[0]<<" <source/Path> <destinationPath>\n";
		help();
	}else{

		//for one file
		imgPath = argv[1];

		temp = cvLoadImage(imgPath.c_str(), CV_LOAD_IMAGE_GRAYSCALE);
		img = cvCreateImage(cvSize(temp->width, temp->height), IPL_DEPTH_8U, 1);
		cvConvertScale(temp, img);
		res = cvCreateImage(cvSize(img->width, img->height), IPL_DEPTH_32F, img->nChannels);

		templateCreator.makeTemplates(img, res);

//		outName = outPath;
//		outName.append("template-");
//		outName.append(imgPath);
		outName = argv[2];

		cvSaveImage(outName.c_str(), res);

	}

	cvReleaseImage(&img);
	cvReleaseImage(&temp);
	cvReleaseImage(&res);

	return 0;
}

void help(){
//	cout<<"current default destination path:\n";
//	cout<<DEFAULT_DST_PATH<<"\n";
}

/*
 * Histogram.cxx
 *
 *  Created on: Nov 11, 2010
 *      Author: michele
 */

#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <stdio.h>
#include <iostream>

#include "HistogramEM.h"

using namespace std;

EngineModule *histogram = new HistogramEM();

float range_0[]={0,256};
float* ranges[] = { range_0 };
int histSizes = 64;
int histDim = 1;

HistogramEM::HistogramEM(){
	min_value = max_value = 0;
	min_idx = max_idx = bin_w = 0;

	hist = NULL;
	histImage = grayImage = NULL;
}

HistogramEM::~HistogramEM(){
	cvReleaseImage(&histImage);
	cvRelease((void**)&hist);
}

int HistogramEM::createHistogram(const IplImage* inputImage){
	if(inputImage->nChannels > 1){
		grayImage = cvCreateImage(cvSize(inputImage->width, inputImage->height),
				inputImage->depth, 1);
		cvCvtColor(inputImage, grayImage, CV_BGR2GRAY);
	}else
		grayImage = (IplImage*) inputImage;

	//create a histogram to store the information from the image
	try{
		hist = cvCreateHist(1, &histSizes, CV_HIST_ARRAY, ranges, 1);
		if(hist == NULL){
			cout<<"couldn't create an histogram \n";
		}
		//calculate the histogram and apply to hist
		cvCalcHist(&grayImage, hist, 0, NULL);

		//grab the min and max values and their indeces
		cvGetMinMaxHistValue(hist, &min_value, &max_value, &min_idx, &max_idx);
//		cout<<"Image Statistics: \n";
//		cout<<"min value: " << min_value <<" max value: " << max_value <<"\n";
//		cout<<"min idx: " << min_idx << " max idx: " << max_idx << "\n";

		//set all histogram values to 255
		histImage = cvCreateImage(cvSize(320,200), 8, 1);
		cvSet( histImage, cvScalarAll(255), 0 );

		//scale the bin values so that they will fit in the image representation
		cvConvertScale( hist->bins, hist->bins, ((double)histImage->height)/max_value, 0 );

		//create a factor for scaling along the width
		bin_w = cvRound((double)histImage->width/histSizes);
		return 1;

	}catch(cv::Exception e){
		cout << e.err <<"\n";
		return e.code;
	}
}

void HistogramEM::displayHistogram(const char* win){
	double mean, variance, hist_size = histSizes;

	//create an image to hold the histogram
	for(int i = 0; i < hist_size  ; i++ ) {
		//draw the histogram data onto the histogram image
		cvRectangle( histImage, cvPoint(i*bin_w, histImage->height),
				cvPoint((i+1)*bin_w,
						histImage->height - cvRound(cvGetReal1D(hist->bins,i))),
						cvScalarAll(0), -1, 8, 0 );
		//get the value at the current histogram bucket
		float* bins = cvGetHistValue_1D(hist,i);
		//increment the mean value
		mean += bins[0];
	}
	//finish mean calculation
	mean /= hist_size;
	//go back through now that mean has been calculated in order to calculate variance
	for(int i = 0; i < hist_size; i++ ) {
		float* bins = cvGetHistValue_1D(hist,i);
		variance += pow((bins[0] - mean),2);
	}
	//finish variance calculation
	variance /= hist_size;

	cout<<"Histogram of image " << grayImage->ID << "\n";
	cout<<"Mean: " << mean <<" variance: " << variance << "\n";

	cvShowImage(win, histImage);
}

int HistogramEM::equalize(const IplImage* src, IplImage* dst){
	cvEqualizeHist(src, dst);
}

int HistogramEM::compute(const IplImage* src, IplImage* dst){
	IplImage* temp = cvCreateImage(cvSize(src->width, src->height), IPL_DEPTH_8U, 1);
	cvEqualizeHist(src, temp);
	cvConvertScale(temp, dst);
}

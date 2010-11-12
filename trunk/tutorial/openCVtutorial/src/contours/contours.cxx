/*
 * contours.cxx
 *
 *  Created on: Nov 11, 2010
 *      Author: michele
 */

#include <opencv/cv.h>
#include <opencv/cvaux.h>
#include <opencv/highgui.h>
#include <opencv/cxtypes.h>
#include <opencv/cxcore.h>   // unnecessary - included in cv.h

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "Histogram.h"

#define MAIN_WIN "mainWin"
#define RES_WIN "resWin"

#define HIST_DIM 1

using namespace std;

int main(int argc, char *argv[])
{
  int height,width,step,channels;
  uchar *data;
  int i,j,k;

  IplImage* img = NULL;
  IplImage* temp2, *res;
  double ave;
  Histogram imgHist;

  if(argc<2){
    printf("Usage: main <image-file-name>\n\7");
    exit(0);
  }

  try{
//	  load an image
	  img=cvLoadImage(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
	  if(img == NULL){
		printf("Could not load image file: %s\n",argv[1]);
		printf("%s\n", cvErrorStr(cvGetErrStatus()));
		exit(0);
	  }
  }catch(cv::Exception e){
	  printf("%s\n", e.what());
  }


  // get the image data
  height    = img->height;
  width     = img->width;
  step      = img->widthStep;
  channels  = img->nChannels;
  data      = (uchar *)img->imageData;
  ave = cvAvg(img).val[0];
  printf("Processing a %dx%d image with %d channels and average: %g \n"
		  ,height,width,channels, ave);

  //build the histogram
  imgHist.createHistogram(img);

  // create a window
  cvNamedWindow(MAIN_WIN, CV_WINDOW_AUTOSIZE);
  cvMoveWindow(MAIN_WIN, 50, 100);

  // create a second window
  cvNamedWindow(RES_WIN, CV_WINDOW_AUTOSIZE);
  cvMoveWindow(RES_WIN, 700, 100);

  // simple identity to avoid run-time errors
  res = cvCreateImage(cvSize(img->width, img->height), img->depth, 1);
  temp2 = cvCloneImage(img);

  //put the transformations here:
  cvAdaptiveThreshold(img, res, ave, CV_ADAPTIVE_THRESH_MEAN_C, CV_THRESH_BINARY, 3, 5);
  cvCanny(img, res, ave/2, ave + ave/2, 3);
//  cvFindContours(img, )

  // show the image
  cvShowImage(MAIN_WIN, img );
  cvShowImage(RES_WIN, res);
//  imgHist.displayHistogram(RES_WIN);


  // wait for a key
  cvWaitKey(0);

  // release the image
  cvReleaseImage(&img );
  cvReleaseImage(&temp2);
  return 0;
}

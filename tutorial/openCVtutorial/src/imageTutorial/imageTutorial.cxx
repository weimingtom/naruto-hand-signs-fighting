/*
 * imageTutorial.cxx
 *
 *  Created on: Nov 6, 2010
 *      Author: michele
 */

/*
 * helloWorld.cpp
 *
 *  Created on: Nov 2, 2010
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

#include "MyFourier.h"

#define MAIN_WIN "mainWin"
#define RES_WIN "resWin"
#define FILTER_WIN "filtWin"

#define TYPE_IMAGES CV_32FC1

using namespace std;

//int main(int argc, char* argv[]){
//
//	return 0;
//}

////////////////////////////////////////////////////////////////////////
//
// hello-world.cpp
//
// This is a simple, introductory OpenCV program. The program reads an
// image from a file, inverts it, and displays the result.
//
////////////////////////////////////////////////////////////////////////


int main(int argc, char *argv[])
{
  IplImage* img = NULL;
  IplImage* temp2;

  CvImage *temp, *res;
  int height,width,step,channels;
  uchar *data;
  int i,j,k;

  CvMat *filter = NULL;
  CvMat *cvMatImg, *cvMatTemp;
  double mean;

  if(argc<2){
    printf("Usage: main <image-file-name>\n\7");
    exit(0);
  }

  try{
//	  load an image
//	  img=cvLoadImage(argv[1], CV_LOAD_IMAGE_UNCHANGED);
	  img=cvLoadImage(argv[1], CV_LOAD_IMAGE_GRAYSCALE);

//	  img = cvLoadImage(argv[1]);
	  temp2 = cvCreateImage(cvSize(img->width, img->height), IPL_DEPTH_8U, 1);
//	  temp = new CvImage(img);

	  cvMatTemp = cvCreateMat(img->width, img->height, TYPE_IMAGES);
	  filter = cvCreateMat(img->width, img->height, TYPE_IMAGES);
	  cvMatImg = cvCreateMat(img->width, img->height, TYPE_IMAGES);
	  cvMatImg = cvGetMat(img, cvMatImg, NULL, 0 );
//	  cvCopy(cvMatTemp, cvMatImg);

	  if ( myFourier.buildFilter(img->width, img->height, TYPE_IMAGES,
			  FILTER_TYPE_HIGHPASS, 2, 50.3, filter ) < 0){
		  cout<<"ERROR: problem building the filter\n";
	  }

	  cvNormalize(img, temp2);
	  mean = cvAvg(img).val[0];
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
  printf("Processing a %dx%d image with %d channels mean: %g\n",height,width,channels, mean);

  // create a window
  cvNamedWindow(MAIN_WIN, CV_WINDOW_AUTOSIZE);
  cvMoveWindow(MAIN_WIN, 50, 50);
//  cvCreateTrackbar("myTrackBar", MAIN_WIN, /)

  // create a second window
  cvNamedWindow(RES_WIN, CV_WINDOW_AUTOSIZE);
  cvMoveWindow(RES_WIN, 700, 50);

  cvNamedWindow(FILTER_WIN, CV_WINDOW_AUTOSIZE);
  cvMoveWindow(FILTER_WIN, 50, 600);

  // simple identity to avoid run-time errors
//  res = temp;
//  temp2 = cvCloneImage(img);


  // invert the image
//  for(i=0;i<height;i++) for(j=0;j<width;j++) for(k=0;k<channels;k++)
//    data[i*step+j*channels+k]=255-data[i*step+j*channels+k];

  // find edges
  // they don't work!!!
//  cvSobel( temp->operator _IplImage *() ,res->operator _IplImage *() , res->width(), res->height(), 3);
//  cvSobel(img, temp2,  )
  cvSmooth(img, temp2, CV_GAUSSIAN, 5, 0, 0, 0);

  if(filter == NULL){
	  cout << "couldn't apply the convolution!\n";
  }else{
	  myFourier.speedyConvolution( cvMatImg, filter, cvMatTemp);
//	  cvShowImage(FILTER_WIN, filter);
  }

  // show the image
  cvShowImage(MAIN_WIN, img );
  cvShowImage(RES_WIN, cvMatTemp);
//  res->show(RES_WIN);

  // wait for a key
  cvWaitKey(0);

  // release the image
  cvReleaseImage(&img );
  cvReleaseImage(&temp2);
  return 0;
}


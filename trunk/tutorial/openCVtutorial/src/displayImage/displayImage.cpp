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

#define MAIN_WIN "mainWin"
#define RES_WIN "resWin"

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

  if(argc<2){
    printf("Usage: main <image-file-name>\n\7");
    exit(0);
  }

  try{
//	  load an image
//	  img=cvLoadImage(argv[1], CV_LOAD_IMAGE_UNCHANGED);
	  img=cvLoadImage(argv[1]);
//	  img = new CvImage( cvLoadImage(argv[1]) );
	  temp = new CvImage(img);
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
  printf("Processing a %dx%d image with %d channels\n",height,width,channels);

  // create a window
  cvNamedWindow(MAIN_WIN, CV_WINDOW_AUTOSIZE);
  cvMoveWindow(MAIN_WIN, 50, 100);
//  cvCreateTrackbar("myTrackBar", MAIN_WIN, /)

  // create a second window
  cvNamedWindow(RES_WIN, CV_WINDOW_AUTOSIZE);
  cvMoveWindow(RES_WIN, 700, 100);

  // simple identity to avoid run-time errors
  res = temp;
  temp2 = cvCloneImage(img);


  // invert the image
//  for(i=0;i<height;i++) for(j=0;j<width;j++) for(k=0;k<channels;k++)
//    data[i*step+j*channels+k]=255-data[i*step+j*channels+k];

  // find edges
  // they don't work!!!
//  cvSobel( temp->operator _IplImage *() ,res->operator _IplImage *() , res->width(), res->height(), 3);
  cvSmooth(img, temp2, CV_GAUSSIAN, 5, 0, 0, 0);


  // show the image
  cvShowImage(MAIN_WIN, img );
  cvShowImage(RES_WIN, temp2);
//  res->show(RES_WIN);

  // wait for a key
  cvWaitKey(0);

  // release the image
  cvReleaseImage(&img );
  cvReleaseImage(&temp2);
  return 0;
}


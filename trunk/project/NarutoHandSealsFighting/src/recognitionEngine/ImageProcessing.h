/*
 ******************************************************
 * NAME:
 * ImageProcessing.h
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Nov 24, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#ifndef IMAGEPROCESSING_H_
#define IMAGEPROCESSING_H_

#include <opencv/cv.h>

void convertDepth8UTo32F(const IplImage* src, IplImage* dst);


#endif /* IMAGEPROCESSING_H_ */

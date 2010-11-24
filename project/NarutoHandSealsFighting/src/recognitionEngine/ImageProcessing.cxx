/*
 ******************************************************
 * NAME:
 * ImageProcessing.cxx
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

#include "ImageProcessing.h"

void convertDepth8UTo32F(const IplImage* src, IplImage* dst){
	cvConvertScale(src, dst, 0.0039215, 0);
}

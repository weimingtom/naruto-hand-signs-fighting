/*
 ******************************************************
 * NAME:
 * HistogramEM.h
 ******************************************************
 * DESCRIPTION:
 * This class implements some useful feature that one will need in order to
 * visualize or use an histogram of an image.
 *
 ******************************************************
 *	Created on: Nov 11, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#ifndef HISTOGRAM_H_
#define HISTOGRAM_H_

#include "EngineModule.h"

class HistogramEM : public EngineModule{

	float min_value, max_value;
	int min_idx, max_idx, bin_w;

public:
	IplImage* histImage;
	IplImage* grayImage;
	CvHistogram* hist ;

	/*
	 * Constructor simply initialize all internal variable
	 */
	HistogramEM();
	~HistogramEM();

	/*
	 * It build the histogram from the input image.
	 * It converts automatically the image to grayscale if it's needed.
	 */
	int createHistogram(const IplImage* grayImage);

	/*
	 * Display the histogram in the windows passed as parameter
	 * and print in terminal some statistics values such as
	 * mean and variance.
	 */
	void displayHistogram(const char* windowName);

	//*****************
	//Inherited methods
	//*****************
	/*
	 * The computation feature of the current class performs the
	 * histogram equalization of the source image in input 'src'
	 * and writes the new image in 'dst'.
	 * A conversion is applied to the source (from any input to
	 * CV_8U) in order to perform the operation, and then it restore
	 * the output used in the Eecognition Engine.
	 */
	int compute( const IplImage* src, IplImage* dst);
};

extern EngineModule *histogram;

#endif /* HISTOGRAM_H_ */

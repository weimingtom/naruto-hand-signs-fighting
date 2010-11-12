/*
 * Histogram.h
 *
 *  Created on: Nov 11, 2010
 *      Author: michele
 */

#ifndef HISTOGRAM_H_
#define HISTOGRAM_H_

class Histogram{

	float min_value, max_value;
	int min_idx, max_idx, bin_w;

public:
	IplImage* histImage;
	IplImage* grayImage;
	CvHistogram* hist ;

	Histogram();
	~Histogram();
	int createHistogram(IplImage* grayImage);
	void displayHistogram(const char* windowName);
};


#endif /* HISTOGRAM_H_ */

/*
 * Histogram.h
 *
 *  Created on: Nov 11, 2010
 *      Author: michele
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

	HistogramEM();
	~HistogramEM();
	int createHistogram(const IplImage* grayImage);
	void displayHistogram(const char* windowName);
	int equalize(const IplImage* src, IplImage* dst);

	//inherited methods
	int compute( const IplImage* src, IplImage* dst);
};

extern EngineModule *histogram;

#endif /* HISTOGRAM_H_ */

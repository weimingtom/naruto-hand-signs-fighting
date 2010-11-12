/*
 * MyFourier.h
 *
 *  Created on: Nov 9, 2010
 *      Author: michele
 */

#ifndef MYFOURIER_H_
#define MYFOURIER_H_

#include <opencv/cv.h>

#define FILTER_TYPE_LOWPASS 0
#define FILTER_TYPE_HIGHPASS 1

class MyFourier{

public:
	void speedyConvolution(const CvMat* A, const CvMat* B, CvMat* C);

	/*
	 *
	 */
	int buildFilter(int rows, int columns, int type,
			int filterType, int order, double fc,
			CvMat* outputFilter);
};

extern MyFourier myFourier;


#endif /* MYFOURIER_H_ */

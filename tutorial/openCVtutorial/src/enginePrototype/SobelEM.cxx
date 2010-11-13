/*
 * SobelEM.cxx
 *
 *  Created on: Nov 13, 2010
 *      Author: michele
 */

#include <opencv/cv.h>
#include "SobelEM.h"

int compute( const IplImage* src, IplImage* dst){
	cvSobel(src, dst, 1, 1, 3);
}

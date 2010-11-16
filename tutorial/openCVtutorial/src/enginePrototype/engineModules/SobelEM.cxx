/*
 * SobelEM.cxx
 *
 *  Created on: Nov 13, 2010
 *      Author: michele
 */

#include <opencv/cv.h>
#include "SobelEM.h"

SobelEM::SobelEM(int kernSize, int dx, int dy){
	fixName();
	kernelSize = kernSize;
	sobelDX = dx;
	sobelDY = dy;
}

int SobelEM::compute( const IplImage* src, IplImage* dst){
	cvSobel(src, dst, sobelDX, sobelDY, kernelSize);
}

void SobelEM::fixName(){
	setName("SobelModule");
}

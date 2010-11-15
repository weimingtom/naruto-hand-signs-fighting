/*
 * LaplacianEM.cxx
 *
 *  Created on: Nov 14, 2010
 *      Author: michele
 */

#include "LaplacianEM.h"

EngineModule *laplacian = new LaplacianEM();

int LaplacianEM::compute( const IplImage* src, IplImage* dst){
	cvLaplace(src, dst, kernelSize);
}


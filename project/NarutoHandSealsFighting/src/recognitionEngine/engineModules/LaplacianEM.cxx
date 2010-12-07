/*
 * LaplacianEM.cxx
 *
 *  Created on: Nov 14, 2010
 *      Author: michele
 */

#include "LaplacianEM.h"

EngineModule *laplacian = new LaplacianEM();

LaplacianEM::LaplacianEM(int inputKernelSize){
	setName("LaplacianModule");
	 kernelSize = inputKernelSize;
}

int LaplacianEM::compute( const IplImage* src, IplImage* dst){
	cvLaplace(src, dst, kernelSize);
}


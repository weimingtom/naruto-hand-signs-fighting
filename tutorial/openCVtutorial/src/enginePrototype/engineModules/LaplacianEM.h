/*
 ******************************************************
 * NAME:
 * LaplacianEM.h
 ******************************************************
 * DESCRIPTION:
 * Class that simply applies a Laplacian filtering.
 * One can set the kernel size of the filter, or keep the
 * default one set to DEFAULT_KERNEL_SIZE.
 *
 ******************************************************
 *	Created on: Nov 14, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#ifndef LAPLACIANEM_H_
#define LAPLACIANEM_H_

#include "EngineModule.h"

#define DEFAULT_LAPLACIAN_KERNEL_SIZE 9

class LaplacianEM : public EngineModule{
	int kernelSize;
public:

	LaplacianEM(){
		setName("LaplacianModule");
		kernelSize = DEFAULT_LAPLACIAN_KERNEL_SIZE;
	}

	LaplacianEM(int kernelSize);

	void setKernelSize(int kerSize){
		kernelSize = kerSize;
	}

	int getKernelSize(){
		return kernelSize;
	}



	int compute( const IplImage* src, IplImage* dst);
};

extern EngineModule *laplacian;

#endif /* LAPLACIANEM_H_ */

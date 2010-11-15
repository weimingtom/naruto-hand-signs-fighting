/*
 * LaplacianEM.h
 *
 *  Created on: Nov 14, 2010
 *      Author: michele
 */

#ifndef LAPLACIANEM_H_
#define LAPLACIANEM_H_

#include "EngineModule.h"

#define DEFAULT_KERNEL_SIZE 9

class LaplacianEM : public EngineModule{
	int kernelSize;
public:

	LaplacianEM(){
		moduleName = "sobelModule";
		kernelSize = DEFAULT_KERNEL_SIZE;
	}
	int compute( const IplImage* src, IplImage* dst);
};

extern EngineModule *laplacian;

#endif /* LAPLACIANEM_H_ */

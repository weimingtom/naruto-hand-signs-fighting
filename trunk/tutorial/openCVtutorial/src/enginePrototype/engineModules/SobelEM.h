/*
 * SobelEM.h
 *
 *  Created on: Nov 13, 2010
 *      Author: michele
 */

#ifndef SOBELEM_H_
#define SOBELEM_H_

#include "EngineModule.h"

#define DERIVATE_DEFAULT_GRADE 1
#define DEFAULT_SOBEL_KERNEL_SIZE 3

class SobelEM : public EngineModule{

	//They indicate the grade of derivation used by the Sobel function
	int sobelDX, sobelDY;

	//The kernel size known in image processing theory, and the aperture_size
	//of the cvSobel function
	int kernelSize;

public:
	SobelEM(){
		moduleName = "sobelModule";
		sobelDX = sobelDY = DERIVATE_DEFAULT_GRADE;
		kernelSize = DEFAULT_SOBEL_KERNEL_SIZE;
	}


	//*****************
	// Inherited method
	//*****************
	int compute( const IplImage* src, IplImage* dst);

    int getKernelSize() const
    {
        return kernelSize;
    }

    int getSobelDX() const
    {
        return sobelDX;
    }

    int getSobelDY() const
    {
    	return sobelDY;
    }

    void setKernelSize(int kernelSize)
    {
        this->kernelSize = kernelSize;
    }

    void setSobelDerivates(int dx, int dy){
    	sobelDX = dx;
    	sobelDY = dy;
    }


};

extern EngineModule *sobel;

#endif /* SOBELEM_H_ */

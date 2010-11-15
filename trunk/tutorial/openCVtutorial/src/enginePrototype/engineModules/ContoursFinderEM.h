/*
 * ContoursFinderEM.h
 *
 *  Created on: Nov 15, 2010
 *      Author: michele
 */

#ifndef CONTOURSFINDEREM_H_
#define CONTOURSFINDEREM_H_

#include <opencv/cv.h>
#include "EngineModule.h"

class ContoursFinderEM : public EngineModule{
	CvMemStorage * memPointer;
public:
	int compute( const IplImage* src, IplImage* dst);
};


#endif /* CONTOURSFINDEREM_H_ */

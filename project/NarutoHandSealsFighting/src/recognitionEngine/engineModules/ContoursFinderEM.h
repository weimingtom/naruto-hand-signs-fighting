/*
 ******************************************************
 * NAME:
 * ContoursFinderEM.h
 ******************************************************
 * DESCRIPTION:
 * Recognition Engine Module
 * It uses the cvFindContour function by collecting the
 * contours of the input image.
 * The contours are then painted on the image given in
 * output.
 * You can set the threshold at which value the cotour
 * finder should operates, the lineThickness and also
 * the retrieval mode of the contours and the
 * contour algorithm.
 * So the compute function will execute:
 *   cvThreshold(..., g_thresh,...);
 *   cvFindContours(..., contourRetrievalMode,
 *   					 contourMethod);
 *
 ******************************************************
 *	Created on: Nov 15, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */
#ifndef CONTOURSFINDEREM_H_
#define CONTOURSFINDEREM_H_

#include <opencv/cv.h>
#include "EngineModule.h"

#define DEFAULT_CONTOUR_THRESHOLD 100

class ContoursFinderEM : public EngineModule{
	CvMemStorage * g_storage;
	CvSeq* contours;

	int g_thresh;
	int lineThickness;

	int contourRetrievalMode;
	int contourMethod;

	void initContoursModule();

public:
	ContoursFinderEM();

	ContoursFinderEM(int threshold);
	~ContoursFinderEM();

	int compute( const IplImage* src, IplImage* dst);

	CvSeq* getContours(){
		return contours;
	}

	CvMemStorage* getMemStorage(){
		return g_storage;
	}

	void setContourMethod(int cvMethod){
		contourMethod = cvMethod;
	}

	void setContourRetrievalMode(int retMode){
		contourRetrievalMode = retMode;
	}

	void setLineThickness(int lineThick){
		lineThickness = lineThick;
	}

};

#endif /* CONTOURSFINDEREM_H_ */

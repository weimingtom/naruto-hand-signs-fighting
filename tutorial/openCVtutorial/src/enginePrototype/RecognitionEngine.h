/*
 * RecognitionEngine.h
 *
 *  Created on: Nov 13, 2010
 *      Author: michele
 */

#ifndef RECOGNITIONENGINE_H_
#define RECOGNITIONENGINE_H_

#include <vector>
#include <opencv/cv.h>

#include "EngineModule.h"
#include "Move.h"

using namespace std;

/**
 * It applies all the module added in the moduleArray
 * structure to the input image.
 * The input image is supposed to be in the GRAYSCALE
 * format. Other different ones are no guarantee to
 * produce a good result.
 * All the inserted module are supposed to be applied as
 * a chain, so the order in which they're added is
 * very relevant.
 */
class RecognitionEngine{
	std::vector<EngineModule*> modulesArray;
	IplImage* temp;

	int findModuleByID(EngineModule* m);

public:

	RecognitionEngine();

	void addModule(EngineModule* m);

	void removeModule(EngineModule* m);

	/**
	 * Applies all the module chain modulesArray to
	 * the input image *src, giving as result
	 * a new image *res
	 */
	int process(IplImage* src, IplImage* res);

	/**
	 * Evaluates
	 */
	int evaluate(IplImage* img, Move m);

}recognitionEngine;

extern RecognitionEngine recognitionEngine;

#endif /* RECOGNITIONENGINE_H_ */

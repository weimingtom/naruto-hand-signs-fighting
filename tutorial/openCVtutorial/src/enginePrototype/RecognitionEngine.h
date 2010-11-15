/*
 ******************************************************
 * NAME:
 * RecognitionEngine.h
 ******************************************************
 * DESCRIPTION:
 * Design pattern applied: Strategy
 * It contains an array of Engine Module pointers called moduleArray,
 * so one can think the structure of the Recognition Engine such as modular.
 * It applies all the module added in the moduleArray structure to the input image.
 * The input image is supposed to be in the GRAYSCALE format.
 * Other different ones are no guarantee to produce a good result.
 * Once the input image is ready, a match occurs between it and the
 * appropriate template image, corresponding to the hand seal that the input image
 * is supposed to represents.
 *
 * We split the Recognition process in two phases:
 *   - process phase
 *   - evaluation phase
 * In the first one we go trough all inserted modules in the engine in order
 * to extract a good edge representation.
 * In the second one we apply a match between the result of the preceding phase
 * and the template image of the hand seal (or sign).
 *
 ******************************************************
 *	Created on: Nov 13, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#ifndef RECOGNITIONENGINE_H_
#define RECOGNITIONENGINE_H_

#include <vector>
#include <opencv/cv.h>

#include "engineModules/EngineModule.h"
#include "Move.h"

#define RE_OUTPUT_IMAGE_DEPTH IPL_DEPTH_32F

using namespace std;

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

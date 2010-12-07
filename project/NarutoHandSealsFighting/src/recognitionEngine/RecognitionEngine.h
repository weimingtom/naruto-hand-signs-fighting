/*
 ******************************************************
 * NAME:
 * RecognitionEngine.h
 ******************************************************
 * DESCRIPTION:
 * Design pattern applied: Strategy
 * It contains an array of Engine Module pointers, called moduleArray,
 * that's inherited from the ModulesPool class.
 * One can think the structure of the Recognition Engine such as modular.
 * It applies all the module added in the ModulesPool to the input image.
 * The input image is supposed to be in the GRAYSCALE format.
 * Other different ones are no guarantee to produce a good result.
 * Once the input image is ready, a match occurs between it and the
 * appropriate template image, corresponding to the hand seal that the input image
 * is supposed to represents.
 *
 * We split the Recognition process in two important phases:
 *   - process phase
 *   - evaluation phase
 *
 * In the first one we go trough all inserted modules in the engine in order
 * to extract a good edge representation (that's probably different from the
 * common use of the term).
 * In the second one we apply a match between the result of the preceding phase
 * and the template image of the hand seal (or sign).
 *
 * Remember that before to use the Recognition Engine you have to initialize it,
 * otherwise you have to provide you own set of modules.
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

#include <opencv/cv.h>

#include "engineModules/EngineModule.h"
#include "engineStrategies/AbstractStrategy.h"
#include "engineStrategies/DefaultStrategy.h"
#include "evaluationFunctions/EvaluatorFunctionTemplate.h"
#include "../gameLogic/Move.h"

#define RE_OUTPUT_IMAGE_DEPTH IPL_DEPTH_32F
#define RE_INPUT_IMAGE_DEPTH IPL_DEPTH_8U

using namespace std;

class RecognitionEngine : public ModulesPool{

	//the Recognition Engine is a SINGLETON
	static RecognitionEngine* engine;

	//PATTERN: Template Method
	EvaluatorFunctionTemplate * evaluator;

	//Internal variable used in the process phase to pass
	//image among the modules
	IplImage* temp;

	//The strategy defines what modules are put into the engine
	//and their order
	AbstractStrategy* strategy;

	//This is the current Move to keep track of.
	//The inserted images are supposed to be part of
	//the seals need by the currentMove.
	Move *currentMove;

	int findModuleByID(EngineModule* m);

	RecognitionEngine();
public:

	static RecognitionEngine* instantiate(){
		if(engine == NULL){
			engine = new RecognitionEngine();
		}
		return engine;
	}
	~RecognitionEngine(){
		currentMove = NULL;
		cvReleaseImage(&temp);
		delete evaluator;
	}

	/*****************
	 * Process Phase
	 *****************
	 * Applies all the module chain modulesArray to
	 * the input image *src, giving as result
	 * a new image *res
	 */
	int process(const IplImage* src, IplImage* res);

	/********************
	 * Evaluation Phase
	 ********************
	 *
	 */
	int evaluate(IplImage* img, int sealIndex);

	void setEvaluatorFunction(EvaluatorFunctionTemplate *eval);

	// currentMove management
	void setCurrentMove(Move *m);
	Move* getCurrentMove(){
		return currentMove;
	}

    EvaluatorFunctionTemplate *getEvaluator() const
    {
        return evaluator;
    }

    IplImage *getTemp() const
    {
        return temp;
    }

    void setEvaluator(EvaluatorFunctionTemplate *evaluator)
    {
        this->evaluator = evaluator;
    }

    int initEngine();

    void changeEngineStrategy(AbstractStrategy* newStrategy);

};

extern RecognitionEngine* recognitionEngine;

#endif /* RECOGNITIONENGINE_H_ */

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
 * The engine initialization provoke the loading off all modules selected by the
 * strategy into the ModulesPool. If you haven't changed the strategy policy
 * then the default one will be applied.
 *
 * In the evaluation phase you have to choose one of the proposed
 * evaluator stored in the directory evaluationFunctions.
 * These algorithms, once the input image has been processed,
 * apply their own function comparing the result with the
 * original template of the target seal.
 * The way in which one operates and the score depends on the
 * function provided. The default function is a multiplier
 * of the templated and the result image.
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
#include "evaluationFunctions/MulEvaluator.h"

#include "processingFunctions/AbstractProcessingFunction.h"
#include "processingFunctions/DifferentTempsAdder.h"
#include "processingFunctions/ChainAdder.h"

#include "RecognitionEngineDefaults.h"
#include "../gameLogic/Move.h"

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

	AbstractProcessingFunction* processingFunction;

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

    /*
     * Initializes the engine with the modules brought by the current
     * strategy selected. The default is the:
     * "DefaultStrategy".
     */
    int initEngine();

    void changeEngineStrategy(AbstractStrategy* newStrategy);

    void setProcessFunction(AbstractProcessingFunction* procFunc){
    	processingFunction = procFunc;
    }

    AbstractProcessingFunction* getProcessFunction(){
    	return processingFunction;
    }

    AbstractStrategy* setStrategy(AbstractStrategy* strat){
    	if(strategy != NULL)
    		delete strategy;
    	strategy = strat;
    }

};

extern RecognitionEngine* recognitionEngine;

#endif /* RECOGNITIONENGINE_H_ */

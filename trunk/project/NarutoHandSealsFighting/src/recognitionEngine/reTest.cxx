/*
 ******************************************************
 * NAME:
 * reTest.cxx
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Nov 24, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv/cvaux.h>
#include <opencv/cxtypes.h>

#include "RecognitionEngine.h"
#include "RecognitionEngine.h"
#include "engineModules/EngineModule.h"
#include "evaluationFunctions/MulEvaluator.h"
#include "engineModules/All.h"

#include "../gameLogic/SealsFactory.h"
#include "../gameLogic/SealsMap.h"
#include "../gameLogic/MovesFactory.h"
#include "../gameLogic/MovesSet.h"

#include "../DebugPrint.h"

MovesSet myMoveSet;
SealsMap smap;

int main(int argc, char* argv[]){
	IplImage *temp, *img, *res;

	sealsFactory->buildSealsMap(&smap);
	movesFactory->buildMovesSet(&myMoveSet, &smap);

//	recognitionEngine->addModule(new HistogramEM());
//	recognitionEngine->addModule(new SobelEM(CV_SCHARR, 1, 0));
//	recognitionEngine->addModule(new BlurEM(CV_GAUSSIAN,3,3));
//	recognitionEngine->addModule(new LaplacianEM(7));

	recognitionEngine->initEngine();

	/*
	 * and so on...
	 */

	return 0;
}

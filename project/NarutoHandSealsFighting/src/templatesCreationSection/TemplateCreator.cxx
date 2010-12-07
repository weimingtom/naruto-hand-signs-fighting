/*
 ******************************************************
 * NAME:
 * TemplateCreator.cxx
 ******************************************************
 * DESCRIPTION:
 *
 * Implementation of the TemplateCreator class
 ******************************************************
 *	Created on: Nov 22, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#include "TemplateCreator.h"

TemplateCreator templateCreator = TemplateCreator();

TemplateCreator::TemplateCreator(){
	internalEngine = RecognitionEngine::instantiate();
}

/*
 * WARNING: we are using the engine without initializing it,
 * so we have to add our own modules.
 */
int TemplateCreator::makeTemplates(IplImage* srcImage, IplImage* outImage){

	HistogramEM *hist = new HistogramEM();
	//If you want to display the histogram...
	hist->createHistogram(srcImage);

	//equalization
	internalEngine->addModule(hist);

	//Sobel
	//	internalEngine.addModule(new SobelEM(7, 2, 2));
	internalEngine->addModule(new SobelEM(CV_SCHARR, 1, 0)); //<-
	//	internalEngine.addModule(new SobelEM(CV_SCHARR, 0, 1));

	//Canny
	//	internalEngine.addModule(new CannyEM(5, 200, 40));

	//blurring
	internalEngine->addModule(new BlurEM(CV_GAUSSIAN,3,3)); //<-(?)

	//Laplacian
	internalEngine->addModule(new LaplacianEM(7)); //<-

	//contours extraction
	//	internalEngine.addModule(new ContoursFinderEM(120));
	internalEngine->process(srcImage, outImage);
}

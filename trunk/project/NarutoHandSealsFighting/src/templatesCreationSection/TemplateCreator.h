/*
 ******************************************************
 * NAME:
 * TemplateCreator.h
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Nov 22, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#ifndef TEMPLATECREATOR_H_
#define TEMPLATECREATOR_H_

#include "../recognitionEngine/RecognitionEngine.h"
#include "../recognitionEngine/engineModules/All.h"

class TemplateCreator{
	RecognitionEngine internalEngine;

public:
	TemplateCreator();

	int makeTemplates(IplImage* srcImage, IplImage* outImage);
};

extern TemplateCreator templateCreator;

#endif /* TEMPLATECREATOR_H_ */

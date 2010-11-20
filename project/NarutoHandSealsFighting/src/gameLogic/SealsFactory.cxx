/*
 * SealsFactory.cxx
 *
 *  Created on: Nov 19, 2010
 *      Author: michele
 */

#include "SealsFactory.h"

SealsFactoryAbstract *sealsFactory = new SealsFactory();

static int sealsIDs = 0;

int SealsFactory::buildSealsMap(SealsMap* sm){
	HandSeal* temp;
	HandSealStruct* t;
	for(int i=0; i<SEALS_NUMBER; i++){
		t = &globSeals[i];
		temp = new HandSeal(t->month, t->japaneseName, t->name, sealsIDs++);
		temp->setImages(t->templatePath, t->thumbnailPath);
		sm->addSeal(temp, temp->getName().c_str());
	}

}

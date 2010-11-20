/*
 ******************************************************
 * NAME:
 * sealsTest.cxx
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Nov 20, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#include <iostream>

#include "SealsFactory.h"
#include "SealsMap.h"


int main(int argc, char* argv[]){
	SealsMap smap;
	HandSeal *hs;
	HandSealStruct hst;

	sealsFactory->buildSealsMap(&smap);
	cout<<"**********\n";
	cout<<"Seals Test \n";
	cout<<"**********\n";
	cout<<"inserted seals:\n";
	cout<<"|Name|JapanName|Month|ID|template|thumbnail\n";
	for(int i=0; i<smap.getSeals().size(); i++){
		hs = smap.getSeal(globSeals[i].name);
		cout<<i+1<<") "<<
				hs->getName()<<"|"<<
				hs->getJapaneseName()<<"|"<<
				hs->getMonth()<<"|"<<
				hs->getTemplateImagePath()<<"|"<<
				hs->getThumbnailImagePath()<<
				"\n";
	}
	cout<<"end\n";
	cout<<"**********\n";

	return 0;
}

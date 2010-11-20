/*
 ******************************************************
 * NAME:
 * SealsFactory.h
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Nov 19, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#ifndef SEALSFACTORY_H_
#define SEALSFACTORY_H_

#include "SealsFactoryAbstract.h"
#include "SealsSettings.h"

using namespace std;

class SealsFactory : public SealsFactoryAbstract{
public:
	SealsFactory(){};
	int buildSealsMap(SealsMap* sm);
};

extern SealsFactoryAbstract *sealsFactory;


#endif /* SEALSFACTORY_H_ */

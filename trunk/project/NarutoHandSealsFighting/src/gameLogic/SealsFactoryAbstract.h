/*
 ******************************************************
 * NAME:
 * SealsFactoryAstract.h
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

#ifndef SEALSFACTORYABSTRACT_H_
#define SEALSFACTORYABSTRACT_H_

#include "SealsMap.h"

class SealsFactoryAbstract{
public:
	virtual int buildSealsMap(SealsMap* sm) = 0;
};


#endif /* SEALSFACTORYABSTRACT_H_ */

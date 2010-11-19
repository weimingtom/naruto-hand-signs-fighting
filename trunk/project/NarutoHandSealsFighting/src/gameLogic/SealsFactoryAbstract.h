/*
 * SealsFactoryAbstract.h
 *
 *  Created on: Nov 19, 2010
 *      Author: michele
 */

#ifndef SEALSFACTORYABSTRACT_H_
#define SEALSFACTORYABSTRACT_H_

#include "SealsMap.h"

class SealFactoryAbstract{
public:
	virtual int buildSealsMap(SealsMap* sm) = 0;
};


#endif /* SEALSFACTORYABSTRACT_H_ */

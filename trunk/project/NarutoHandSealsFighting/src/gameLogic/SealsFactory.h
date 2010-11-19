/*
 * SealsFactory.h
 *
 *  Created on: Nov 19, 2010
 *      Author: michele
 */

#ifndef SEALSFACTORY_H_
#define SEALSFACTORY_H_

#include "SealsFactoryAbstract.h"
#include "SealsSettings.h"

using namespace std;

class SealsFactory : public SealFactoryAbstract{
public:
	int buildSealsMap(SealsMap* sm);
};


#endif /* SEALSFACTORY_H_ */

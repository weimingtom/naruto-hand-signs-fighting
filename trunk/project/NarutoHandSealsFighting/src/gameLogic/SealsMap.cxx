/*
 * SealsMap.cxx
 *
 *  Created on: Nov 19, 2010
 *      Author: michele
 */

#include "SealsMap.h"

using namespace std;

void SealsMap::addSeal(HandSeal* hs, string sealKey){
	seals.insert(std::pair<HandSeal*, string>(hs, sealKey));
}

HandSeal* SealsMap::getSeal(string sealKey){
	return seals.find(sealKey);
}

/*
 * SealsMap.cxx
 *
 *  Created on: Nov 19, 2010
 *      Author: michele
 */

#include "SealsMap.h"

SealsMap sealsMap;

void SealsMap::addSeal(string sealKey, HandSeal* hs){
//	seals.insert(std::pair<HandSeal*, const char*>(hs, sealKey.c_str()));
	seals[sealKey] = hs;
}

HandSeal* SealsMap::getSeal(string sealKey){
	map<string, HandSeal*>::iterator it = seals.find(sealKey);
	if(it == seals.end()){
		return NULL;
	}
	return it->second;
}

HandSeal* SealsMap::getSeal(const char* sealKey){
	string s(sealKey);
	return getSeal(s);
}

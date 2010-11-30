/*
 ******************************************************
 * NAME:
 * SealsMap.h
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

#ifndef SEALSMAP_H_
#define SEALSMAP_H_

#include <map>
#include <string>
#include "HandSeal.h"

#define NOT_FOUND_SEAL -1

using namespace std;

class SealsMap{
	map<string, HandSeal*> seals;
public:
	SealsMap(){}
	~SealsMap(){
		seals.clear();
	}

	map<string, HandSeal*> getSeals(){
		return seals;
	}

	void addSeal(string sealKey, HandSeal* hs);
	HandSeal* getSeal(string sealKey);
	HandSeal* getSeal(const char* sealKey);
};

extern SealsMap sealsMap;


#endif /* SEALSMAP_H_ */

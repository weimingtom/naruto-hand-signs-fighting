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

using namespace std;

class SealsMap{
	map<HandSeal*, string> seals;
public:
	SealsMap(){

	}

	map<HandSeal*, string> getSeals(){
		return seals;
	}

	void addSeal(HandSeal* hs, string sealKey);
	HandSeal* getSeal(string sealKey);
};


#endif /* SEALSMAP_H_ */

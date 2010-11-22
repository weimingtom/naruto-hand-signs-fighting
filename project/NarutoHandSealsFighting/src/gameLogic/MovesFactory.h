/*
 ******************************************************
 * NAME:
 * MovesFactory.h
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

#ifndef MOVESFACTORY_H_
#define MOVESFACTORY_H_

#include <iostream>
#include <fstream>
#include <strings.h>

#include "tinyxml/tinystr.h"
#include "tinyxml/tinyxml.h"

#include "MovesFactoryAbstract.h"
//#include "MovesSettings.h"
#include "Move.h"

class MovesFactory : public MovesFactoryAbstract {
	ifstream fileSealsInput;
	int commentLines;
public:
	MovesFactory(){};
	~MovesFactory(){
		fileSealsInput.close();
	}
	void buildMovesSet(MovesSet* mSet, SealsMap* sm);
};

extern MovesFactoryAbstract *movesFactory;

#endif /* MOVESFACTORY_H_ */

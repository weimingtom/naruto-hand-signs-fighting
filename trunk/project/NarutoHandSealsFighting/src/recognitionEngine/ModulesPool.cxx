/*
 ******************************************************
 * NAME:
 * ModulesPool.cxx
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Dec 7, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#include "ModulesPool.h"

ModulesPool::ModulesPool() {

}

ModulesPool::~ModulesPool() {
	// TODO Auto-generated destructor stub
}

void ModulesPool::addModule(EngineModule* m){
	modulesArray.push_back(m);
}

void ModulesPool::removeModule(EngineModule* m){
	long int targetIndex = m->getModuleID();
	int i=0;
	for(vector<EngineModule*>::iterator it = modulesArray.begin();
			it != modulesArray.end();
			it++, i++){
		if( modulesArray.at(i)->getModuleID() == targetIndex )
			modulesArray.erase(it);
	}
}

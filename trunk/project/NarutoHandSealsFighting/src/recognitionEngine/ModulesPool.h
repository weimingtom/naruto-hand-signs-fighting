/*
 ******************************************************
 * NAME:
 * ModulesPool.h
 ******************************************************
 * DESCRIPTION:
 *
 * It the container of all modules. We use a std::vector
 * as a high level container in order to keep them sorted.
 * So take care to the order in building new strategies.
 * The ModulesPool simply gives the methods to add and
 * remove single modules.
 *
 ******************************************************
 *	Created on: Dec 7, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#ifndef MODULESPOOL_H_
#define MODULESPOOL_H_

#include <vector>
#include "engineModules/EngineModule.h"

using namespace std;

class ModulesPool {
protected:
	//It the container of all inserted modules
	std::vector<EngineModule*> modulesArray;
public:
	ModulesPool();
	virtual ~ModulesPool();

	void addModule(EngineModule* m);

	void removeModule(EngineModule* m);

};

#endif /* MODULESPOOL_H_ */

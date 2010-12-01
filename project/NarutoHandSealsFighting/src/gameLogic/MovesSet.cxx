
#include "MovesSet.h"

MovesSet* movesSetGlobal = new MovesSet();

MovesSet::~MovesSet(){
	movesSet.clear();
}

int MovesSet::addMove(Move* m){
//	pair<map<string,Move*>::iterator,bool> ret;

//	ret = movesSet.insert(m->getMoveName(), m);
	movesSet[m->getMoveName()] = m;
//	if(ret.second == false){
//		return -1;
//	}
	return 1;
}

Move* MovesSet::getMove(const char* mName){
	string k = string(mName);
	return getMove(k);
}

Move* MovesSet::getMove(string k){
	map<string, Move*>::iterator t;
	t = movesSet.find(k);
	if(t == movesSet.end() )
		return NULL;
	return t->second;
}

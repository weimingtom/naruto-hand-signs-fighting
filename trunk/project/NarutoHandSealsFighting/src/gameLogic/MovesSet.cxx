
#include "MovesSet.h"

int MovesSet::addMove(Move* m){
	pair<set<Move*>::iterator,bool> ret;

	ret = movesSet.insert(m);
	if(ret.second == false){
		return -1;
	}
	return 1;
}


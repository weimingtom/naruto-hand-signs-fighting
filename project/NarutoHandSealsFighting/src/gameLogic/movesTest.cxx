/*
 ******************************************************
 * NAME:
 * movesTest.cxx
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
#include <iostream>
#include "MovesFactory.h"
#include "MovesSet.h"

using namespace std;

int main(int argc, char* argv[]){
	MovesSet myMoveSet;
	Move* temp;
	movesFactory->buildMovesSet(&myMoveSet);
	cout<<"**********\n";
	cout<<"Moves Test \n";
	cout<<"**********\n";

	for(set<Move*>::iterator it = myMoveSet.getMoveSet().begin();
			it != myMoveSet.getMoveSet().end(); it++){
		temp = *it;
		cout<<"move: "<<temp->getMoveName()<<"\n";
		vector<HandSeal*> s = temp->getMoveSeals();
		cout<<"seals: ";
		for(int i=0; i<s.size(); i++){
			cout<<" "<< s.at(i)->getName();
		}
		cout<<"\n";
	}

	cout<<"**********\n";

	return 0;
}


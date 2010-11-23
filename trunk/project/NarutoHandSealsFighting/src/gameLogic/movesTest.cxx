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
#include "SealsFactory.h"
#include "SealsMap.h"
#include "MovesFactory.h"
#include "MovesSet.h"

using namespace std;

int main(int argc, char* argv[]){
	MovesSet myMoveSet;
	SealsMap smap;
	Move* temp;
	sealsFactory->buildSealsMap(&smap);
	movesFactory->buildMovesSet(&myMoveSet, &smap);
	cout<<"**********\n";
	cout<<"Moves Test \n";
	cout<<"**********\n";

	if(myMoveSet.getMoveSet().size()>0){
		for(set<Move*>::iterator it = myMoveSet.getMoveSet().begin();
				it != myMoveSet.getMoveSet().end(); it++){
			temp = *it;
			cout<<"move: "<<temp->getMoveName()<<"\n";
			cout<<"type: "<<temp->getType().japName <<", "<<temp->getType().engName <<"\n";
			cout<<"element: "<<temp->getElementStr()<<"\n";
			cout<<"difficulty: "<<temp->getRankStr()<<"\n";
			vector<HandSeal*> s = temp->getMoveSeals();
			cout<<"seals: ";
			for(int i=0; i<s.size(); i++){
				cout<<" "<< s.at(i)->getName();
			}
			cout<<"\n\n";
		}
	}else{
		cout<<"empty move set\n";
	}

	cout<<"**********\n";

	return 0;
}


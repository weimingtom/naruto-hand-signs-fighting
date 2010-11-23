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
	const char* s;
	sealsFactory->buildSealsMap(&smap);
	movesFactory->buildMovesSet(&myMoveSet, &smap);
	cout<<"**********\n";
	cout<<"Moves Test \n";
	cout<<"**********\n";

	if(myMoveSet.getMoveSet().size()>0){
		for(map<string,Move*>::iterator it = myMoveSet.getMoveSet().begin();
				it != myMoveSet.getMoveSet().end(); it++){
			temp = it->second;
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

	cout<<"Testing the finder method\n";
	s = "balubba";
	cout<<"try with "<<s<<" ... returned: ";
	fflush(stdout);
	temp =myMoveSet.getMove(s);
	if(temp != NULL)
		cout<<temp->getMoveName();
	else
		cout<<"NULL ";
	cout<<"must be NULL... "<< "\n";

	s = "Lightning Blade";
	cout<<"try with "<<s<<" ... returned: ";
	temp = myMoveSet.getMove(s);
	if(temp != NULL)
		cout<<temp->getMoveName();
	else
		cout<<"NULL ";
	cout<<" must be "<<s<<"\n";
	cout<<"**********\n";
	cout<<"Let's now see the seals of the extracted move: ... \n";
	for(int i=0; i<temp->getMoveSeals().size(); i++){
		cout<<i+1<<") is: "<<temp->getMoveSeals().at(i)->getName()<<"\n";
		temp->getMoveSeals().at(i)->displayTemplateImage(3000);
	}
	cout<<"done... wasn't it sweet?!?! =) \n";

	cout<<"**********\n";

	return 0;
}


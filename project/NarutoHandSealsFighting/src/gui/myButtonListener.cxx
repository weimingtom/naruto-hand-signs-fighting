/*
 ******************************************************
 * NAME:
 * myButtonListener.cxx
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Nov 28, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#include <iostream>
#include <string.h>
#include <SDL/SDL.h>
#include "myButtonListener.h"

using namespace std;

MyButtonListener::MyButtonListener() {
	// TODO Auto-generated constructor stub

}

MyButtonListener::~MyButtonListener() {
	// TODO Auto-generated destructor stub
}

void MyButtonListener::action(const gcn::ActionEvent& actionEvent){
	cout<<actionEvent.getSource() <<" through an id event of: "<<actionEvent.getId()<<"\n";

	if(strcmp(actionEvent.getId().c_str(), "quit")==0){
		SDL_Event e;
		e.type = SDL_KEYDOWN;
		e.key.keysym.sym = SDLK_ESCAPE;
		SDL_PushEvent(&e);
	}
}

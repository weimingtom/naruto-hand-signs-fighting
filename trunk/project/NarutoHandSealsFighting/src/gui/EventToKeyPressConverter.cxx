/*
 ******************************************************
 * NAME:
 * EventToKeyPressConverter.cxx
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Nov 29, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#include <iostream>
#include "EventToKeyPressConverter.h"
#include "MenuWindow.h"

using namespace std;

EventToKeyPressConverter::EventToKeyPressConverter() {
	// TODO Auto-generated constructor stub

}

EventToKeyPressConverter::~EventToKeyPressConverter() {
	// TODO Auto-generated destructor stub
}

void EventToKeyPressConverter::action(const gcn::ActionEvent & event){
	SDL_Event sdlEvent;
	sdlEvent.type = SDL_KEYDOWN;

	//how sweet programming style... isn't it?? =)
	if(strcmp(event.getId().c_str(),"play")==0)
			sdlEvent.key.keysym.sym = SDLK_p;

	else if(strcmp(event.getId().c_str(),"training")==0)
			sdlEvent.key.keysym.sym = SDLK_t;

	else if(strcmp(event.getId().c_str(),"instructions")==0)
			sdlEvent.key.keysym.sym = SDLK_i;

	else if(strcmp(event.getId().c_str(),"options")==0)
			sdlEvent.key.keysym.sym = SDLK_o;

	else if(strcmp(event.getId().c_str(),"quit")==0)
		sdlEvent.key.keysym.sym = SDLK_ESCAPE;

	SDL_PushEvent(&sdlEvent);
}

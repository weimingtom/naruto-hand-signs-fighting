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
#include "../DebugPrint.h"

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

	else if(strcmp(event.getId().c_str(),"back")==0)
			sdlEvent.key.keysym.sym = SDLK_b;

	else if(strcmp(event.getId().c_str(),"shot")==0)
				sdlEvent.key.keysym.sym = SDLK_SPACE;

//	debugPrint("generated key: %s\n", SDL_GetKeyName(sdlEvent.key.keysym.sym));

	SDL_PushEvent(&sdlEvent);
}

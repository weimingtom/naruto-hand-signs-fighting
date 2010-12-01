/*
 ******************************************************
 * NAME:
 * MovesListListener.cxx
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Nov 30, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#include "MovesListListener.h"

MovesListListener::MovesListListener(gcn::ListBox* lb) {
	listBox = lb;
}

MovesListListener::~MovesListListener() {
	// TODO Auto-generated destructor stub
}

void MovesListListener::action(const gcn::ActionEvent& actionEvent){
	int sel;
	std::string moveKey;
	if(strcmp(actionEvent.getId().c_str(), TRAINING_EVENT_ID) ==0){
		sel = listBox->getSelected();
		moveKey = listBox->getListModel()->getElementAt(sel);
		//and this is the pure magic phenomenon: "'accio' MovesListController!"
		movesListController_Kagi->setTargetMove(moveKey);
		SDL_Event sdlEvent;
		sdlEvent.type = SDL_KEYDOWN;
		sdlEvent.key.keysym.sym = SDLK_s;
		SDL_PushEvent(&sdlEvent);

	}else{
		EventToKeyPressConverter::action(actionEvent);
	}
}

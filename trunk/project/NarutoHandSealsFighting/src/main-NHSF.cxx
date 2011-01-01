/*
 * main-NHSF.cxx
 *
 *  Created on: Nov 19, 2010
 *      Author: michele
 */

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "gui/Gui.h"
#include "gameLogic/GameLogic.h"
#include "gameStack/GameStack.h"
#include "recognitionEngine/RecognitionEngine.h"
#include "recognitionEngine/engineModules/All.h"
#include "recognitionEngine/evaluationFunctions/ContoursChecker.h"
#include "recognitionEngine/engineStrategies/AGoodStrategy.h"
#include "recognitionEngine/processingFunctions/SChainBGRemoval.h"

#include "DebugPrint.h"

void initialization();

int main(int argc, char* argv[]){
	SealsMap smap;
	MovesSet *myMoveSet = movesSetGlobal;
	sealsFactory->buildSealsMap(&smap);
	movesFactory->buildMovesSet(myMoveSet, &smap);
	GameMachine *gm;

	initialization();

	recognitionEngine->setEvaluator(new ContoursChecker());
	recognitionEngine->setStrategy(new AGoodStrategy(recognitionEngine));
	recognitionEngine->setProcessFunction(new SChainBGRemoval());
	recognitionEngine->initEngine();

	cout<<"**********\n";
	cout<<"NARUTO HAND SEALS FIGHTING\n";
	cout<<"**********\n";
	try{
		gm = GameMachine().getGameMachineInstance();
		debugPrint("Initializing the GameMachine ... ");
		factoryGameMachine->initGameMachine(gm);
		debugPrint("done\n");

		debugPrint("Starting the machine: ");
		gm->startGameMachine();
		debugPrint("done\n");
		gm->mainLoop();

	}catch(gcn::Exception e){
		cout<<e.getMessage().c_str()<<"\n";
	}catch(cv::Exception e){
		cout<<e.msg<<"\n";
	}catch(std::exception e){
		cout<<e.what()<<"\n";
	}

	SDL_Quit();

	return 0;
}

void initialization(){
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Init(SDL_INIT_TIMER);
}

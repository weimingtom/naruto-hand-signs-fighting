/*
 ******************************************************
 * NAME:
 * boh.cxx
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Nov 25, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#include <iostream>

//#include <iostream>
//#include <SDL/SDL.h>
//#include <SDL/SDL_image.h>
//#include "boh.h"
//#include "guichan-0.8.2/include/guichan.hpp"
//#include "guichan-0.8.2/include/guichan/sdl.hpp"

#include <iostream>
#include <guichan.hpp>
#include <guichan/sdl.hpp>
#include "SDL.h"

using namespace std;

SDL_Surface* screen;
SDL_Event event;
gcn::SDLInput* input;
gcn::SDLGraphics* graphics;
gcn::SDLImageLoader* imageLoader;
gcn::Gui* gui;
gcn::Container* top;
gcn::ImageFont* font;
gcn::Label* label;


void init();
void run();
void halt();


int main(int argc, char* argv[]){
	try
	{
		init();

		imageLoader = new gcn::SDLImageLoader();
		gcn::Image::setImageLoader(imageLoader);
		graphics = new gcn::SDLGraphics();
		graphics->setTarget(screen);
		input = new gcn::SDLInput();
		font = new gcn::ImageFont("fixedfont.bmp",
				" abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
		gcn::Widget::setGlobalFont(font);

		gui = new gcn::Gui();
		gui->setGraphics(graphics);
		gui->setInput(input);

		top = new gcn::Container();
		top->setDimension(gcn::Rectangle(0, 0, 640, 480));
		gui->setTop(top);

		label = new gcn::Label("Hello World");
		label->setPosition(280, 220);
		top->add(label);


		run();
		halt();
	}
	catch (gcn::Exception e)
	{
		std::cout << e.getMessage() << std::endl;
	}
	catch (std::exception e)
	{
		std::cout << "Std exception: " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Unknown exception" << std::endl;
	}

	return 1;

}

void init()
{
	SDL_Init(SDL_INIT_VIDEO);
	screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
	SDL_EnableUNICODE(1);
	SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);

}

void run()
{
	bool running = true;

	while (running)
	{
		while(SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
					running = false;
				}

			}
			else if(event.type == SDL_QUIT)
			{
				running = false;
			}

			input->pushInput(event);
		}

		gui->logic();
		gui->draw();

		SDL_Flip(screen);
	}

}

void halt()
{
	delete label;
	delete font;
	delete top;
	delete gui;

	delete input;
	delete graphics;
	delete imageLoader;

	SDL_Quit();

}


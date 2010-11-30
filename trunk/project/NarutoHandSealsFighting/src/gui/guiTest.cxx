/*
 ******************************************************
 * NAME:
 * guiTutorial.cxx
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
#include "guichan-0.8.2/include/guichan.hpp"
#include "guichan-0.8.2/include/guichan/sdl.hpp"
#include "MenuWindow.h"

void run();

//COMMONS:
//gcn::Gui* gui;
//SDL_Surface* screen;
//gcn::Container* panel;
//gcn::ImageFont* font;


// All back ends contain objects to make Guichan work on a
// specific target - in this case SDL - and they are a Graphics
// object to make Guichan able to draw itself using SDL, an
// input objec to make Guichan able to get user input using SDL
// and an ImageLoader object to make Guichan able to load images
// using SDL.
//gcn::SDLGraphics* graphics;
//gcn::SDLInput* input;
//gcn::SDLImageLoader* imageLoader;

//Elements:
gcn::Button* button;
gcn::Image *image;
gcn::Window *window;
gcn::Label* label;
gcn::Icon* icon;

bool running = true;

AbstractFactory* menu;

int main(int argc, char* argv[]){
	cout<<"**********\n";
	cout<<"GUI TEST \n";
	cout<<"**********\n";
	cout<<"remenber: you cannot surf the menu...\n";

//	init();

//	button = new gcn::Button("Button");
//	panel->add(button, 200, 10);
//
//	image = gcn::Image::load("images/Hitsuji.png");
//	icon = new gcn::Icon(image);
//	panel->add(icon, 10, 30);

	menu = new MenuWindow();
	menu->buildWindow();
	run();

	return 0;
}

/**
 * Runs the SDL application.
 */
void run()
{
	// The main loop
	while(running)
	{
		// Check user input
		SDL_Event event;
		while(SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
					running = false;
				}
				if (event.key.keysym.sym == SDLK_f)
				{
					if (event.key.keysym.mod & KMOD_CTRL)
					{
						// Works with X11 only
						SDL_WM_ToggleFullScreen(menu->getScreen());
					}
				}
			}
			else if(event.type == SDL_QUIT)
			{
				running = false;
			}

			// After we have manually checked user input with SDL for
			// any attempt by the user to halt the application we feed
			// the input to Guichan by pushing the input to the Input
			// object.
			menu->getInput()->pushInput(event);
		}
		// Now we let the Gui object perform its logic.
		menu->getGui()->logic();
		// Now we let the Gui object draw itself.
		menu->getGui()->draw();
		// Finally we update the screen.
		SDL_Flip(menu->getScreen());
	}
}

/**
 * Initialises the SDL application. This function creates the global
 * Gui object that can be populated by various examples.
 */
//void init()
//{
//	// We simply initialise SDL as we would do with any SDL application.
//	SDL_Init(SDL_INIT_VIDEO);
//	screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
//	// We want unicode for the SDLInput object to function properly.
//	SDL_EnableUNICODE(1);
//	// We also want to enable key repeat.
//	SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
//
//	// Now it's time to initialise the Guichan SDL back end.
//
//	imageLoader = new gcn::SDLImageLoader();
//	// The ImageLoader Guichan should use needs to be passed to the Image object
//	// using a static function.
//	gcn::Image::setImageLoader(imageLoader);
//	graphics = new gcn::SDLGraphics();
//	// The Graphics object needs a target to draw to, in this case it's the
//	// screen surface, but any surface will do, it doesn't have to be the screen.
//	graphics->setTarget(screen);
//	input = new gcn::SDLInput();
//
//	// Now we create the Gui object to be used with this SDL application.
//	gui = new gcn::Gui();
//	// The Gui object needs a Graphics to be able to draw itself and an Input
//	// object to be able to check for user input. In this case we provide the
//	// Gui object with SDL implementations of these objects hence making Guichan
//	// able to utilise SDL.
//	gui->setGraphics(graphics);
//	gui->setInput(input);
//
//	// We first create a container to be used as the top widget.
//	// The top widget in Guichan can be any kind of widget, but
//	// in order to make the Gui contain more than one widget we
//	// make the top widget a container.
//	panel = new gcn::Container();
//	// We set the dimension of the top container to match the screen.
//	panel->setDimension(gcn::Rectangle(0, 0, 640, 480));
//	// Finally we pass the top widget to the Gui object.
//	gui->setTop(panel);
//
//	// Now we load the font used in this example.
//	font = new gcn::ImageFont("fixedfont.bmp",
//			" abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
//	// Widgets may have a global font so we don't need to pass the
//	// font object to every created widget. The global font is static.
//	gcn::Widget::setGlobalFont(font);
//}

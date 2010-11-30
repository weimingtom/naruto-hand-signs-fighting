/*
 ******************************************************
 * NAME:
 * AbstractFactory.cxx
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

#include "AbstractFactory.h"


AbstractFactory::AbstractFactory() {
	screenWidth = DEFAULT_SCREEN_WIDTH;
	screenHeight = DEFAULT_SCREEN_HEIGHT;
	init();
}

AbstractFactory::~AbstractFactory() {
	delete gui;
	SDL_FreeSurface(screen);
	delete panel;
	delete font;
	delete graphics;
	delete input;
	delete imageLoader;
}

void AbstractFactory::display(){
	gui->logic();
	gui->draw();
	SDL_Flip(screen);
}

/**
 * Initialises the SDL application. This function creates the global
 * Gui object that can be populated by various examples.
 */
void AbstractFactory::init()
{
	// We simply initialise SDL as we would do with any SDL application.
	SDL_Init(SDL_INIT_VIDEO);
	screen = SDL_SetVideoMode(screenWidth, screenHeight, 32, SDL_HWSURFACE);
	// We want unicode for the SDLInput object to function properly.
	SDL_EnableUNICODE(1);
	// We also want to enable key repeat.
	SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);

	// Now it's time to initialise the Guichan SDL back end.

	imageLoader = new gcn::SDLImageLoader();
	// The ImageLoader Guichan should use needs to be passed to the Image object
	// using a static function.
	gcn::Image::setImageLoader(imageLoader);
	graphics = new gcn::SDLGraphics();
	// The Graphics object needs a target to draw to, in this case it's the
	// screen surface, but any surface will do, it doesn't have to be the screen.
	graphics->setTarget(screen);
	input = new gcn::SDLInput();

	// Now we create the Gui object to be used with this SDL application.
	gui = new gcn::Gui();
	// The Gui object needs a Graphics to be able to draw itself and an Input
	// object to be able to check for user input. In this case we provide the
	// Gui object with SDL implementations of these objects hence making Guichan
	// able to utilise SDL.
	gui->setGraphics(graphics);
	gui->setInput(input);

	// We first create a container to be used as the top widget.
	// The top widget in Guichan can be any kind of widget, but
	// in order to make the Gui contain more than one widget we
	// make the top widget a container.
	panel = new gcn::Container();
	// We set the dimension of the top container to match the screen.
	panel->setDimension(gcn::Rectangle(0, 0, screenWidth, screenHeight));
	// Finally we pass the top widget to the Gui object.
	gui->setTop(panel);

	// Now we load the font used in this example.
	font = new gcn::ImageFont("rpgfont.bmp",
			" abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,!?-+/():;%&`'*#=[]\"");

	// Widgets may have a global font so we don't need to pass the
	// font object to every created widget. The global font is static.
	gcn::Widget::setGlobalFont(font);
}

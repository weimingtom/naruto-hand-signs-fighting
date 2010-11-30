/*
 ******************************************************
 * NAME:
 * AbstractFactory.h
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

#ifndef ABSTRACTFACTORY_H_
#define ABSTRACTFACTORY_H_

#include "../guichan-0.8.2/include/guichan.hpp"
#include "../guichan-0.8.2/include/guichan/sdl.hpp"
#include "AbstractGUIObject.h"

#define DEFAULT_SCREEN_WIDTH 640
#define DEFAULT_SCREEN_HEIGHT 480

using namespace std;


class AbstractFactory {


	void init();

protected:
	int screenWidth;
	int screenHeight;

    gcn::Gui *gui;
    SDL_Surface *screen;
    gcn::Container *panel;
    gcn::ImageFont *font;
    gcn::SDLGraphics *graphics;
    gcn::SDLInput *input;
    gcn::SDLImageLoader *imageLoader;

public:
    AbstractFactory();
    virtual ~AbstractFactory();
    virtual void buildWindow() = 0;

    int getScreenHeight() const
    {
        return screenHeight;
    }

    int getScreenWidth() const
    {
        return screenWidth;
    }

    void setGraphics(gcn::SDLGraphics *graphics)
    {
        this->graphics = graphics;
    }

    gcn::ImageFont *getFont() const
    {
        return font;
    }

    gcn::SDLGraphics *getGraphics() const
    {
        return graphics;
    }

    gcn::Gui *getGui() const
    {
        return gui;
    }

    gcn::SDLImageLoader *getImageLoader() const
    {
        return imageLoader;
    }

    gcn::SDLInput *getInput() const
    {
        return input;
    }

    gcn::Container *getPanel() const
    {
        return panel;
    }

    SDL_Surface *getScreen() const
    {
        return screen;
    }

    void setGui(gcn::Gui *gui)
    {
        this->gui = gui;
    }

};

#endif /* ABSTRACTFACTORY_H_ */

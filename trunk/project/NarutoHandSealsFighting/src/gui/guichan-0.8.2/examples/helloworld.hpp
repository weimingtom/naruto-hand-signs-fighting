/**
 * Code to populate a global Gui object with a simple
 * Hello World example.
 */


namespace helloworld
{
    gcn::Container* top;
    gcn::ImageFont* font;
    gcn::Label* label;

    /**
     * Initialises the Hello World example by populating the global Gui
     * object.
     */
    void init()
    {
        // We first create a container to be used as the top widget.
        // The top widget in Guichan can be any kind of widget, but
        // in order to make the Gui contain more than one widget we
        // make the top widget a container.
        top = new gcn::Container();
        // We set the dimension of the top container to match the screen.
        top->setDimension(gcn::Rectangle(0, 0, 640, 480));
        // Finally we pass the top widget to the Gui object.
        globals::gui->setTop(top);

        font = new gcn::ImageFont("rpgfont.bmp", " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
        // Widgets may have a global font so we don't need to pass the
        // font object to every created widget. The global font is static.
        gcn::Widget::setGlobalFont( font);

        // Now we create a label with the text "Hello World".
        label = new gcn::Label("Hello World");
        gcn::TextBox* textBox;
        textBox = new gcn::TextBox("fonts:abcdefghijklmnopqrstuvwxyz\nABCDEFGHIJKLMNOPQRSTUVWXYZ\n"
        		"0123456789 ( ) [ ] . ; - +");
        gcn::ScrollArea* textBoxScrollArea;
        textBoxScrollArea = new gcn::ScrollArea(textBox);
        textBoxScrollArea->setWidth(200);
        textBoxScrollArea->setHeight(100);
        textBoxScrollArea->setFrameSize(1);
        // We give the label a position.
        label->setPosition(280, 220);
        textBoxScrollArea->setPosition(200, 350);
        // And finally we add the label to the top container.
        top->add(label);
        top->add(textBoxScrollArea);
    }
    
    /**
     * Halts the Hello World example.
     */
    void halt()
    {
        delete label;
        delete font;
        delete top;
    }
}

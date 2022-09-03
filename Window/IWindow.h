//
// Created by MH on 2022-09-03.
//

#ifndef CMH_CLIENT_IWINDOW_H
#define CMH_CLIENT_IWINDOW_H

#include <SFML/Graphics.hpp>
#include <functional>

class IWindow {

public:
    ~IWindow() = default;

    virtual void run() = 0;

    virtual sf::RenderWindow *getWindow() = 0;

    virtual void setEventHandler(std::function<void(IWindow *, sf::Event &)>) = 0;
    virtual void setGameLoop(std::function<void(IWindow *)>) = 0;
    virtual void setDrawLoop(std::function<void(IWindow *)>) = 0;

    virtual unsigned int getFrame() = 0;

protected:
    virtual void handleEvent(IWindow *, sf::Event &) = 0;

    virtual void gameloop(IWindow *) = 0;

    virtual void drawloop(IWindow *) = 0;

private:

};

#endif //CMH_CLIENT_IWINDOW_H

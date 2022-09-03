//
// Created by MH on 2022-09-03.
//

#ifndef CMH_CLIENT_GAMEWINDOW_H
#define CMH_CLIENT_GAMEWINDOW_H

#include <functional>

#include "IWindow.h"
#include "../WindowBuilder/IWindowBuilder.h"

class GameWindow : public IWindow {

public:
    explicit GameWindow(IWindowBuilder &builder);

    sf::RenderWindow *getWindow() override;

    void run() override;

    void setEventHandler(std::function<void(IWindow *, sf::Event &)> function) override;

    void setGameLoop(std::function<void(IWindow *)> function) override;

    void setDrawLoop(std::function<void(IWindow *)> function) override;

    unsigned int getFrame() override;

protected:
    void handleEvent(IWindow *window, sf::Event &event) override;

    void gameloop(IWindow *window) override;

    void drawloop(IWindow *window) override;

    unsigned int m_frame;
    sf::RenderWindow *m_window;
    std::function<void(IWindow *, sf::Event &)> m_eventHandlerFunction;
    std::function<void(IWindow *)> m_gameLoopFunction;
    std::function<void(IWindow *)> m_drawLoopFunction;


private:

};


#endif //CMH_CLIENT_GAMEWINDOW_H

//
// Created by MH on 2022-09-03.
//

#include "GameWindow.h"

GameWindow::GameWindow(IWindowBuilder &builder) {

    this->m_window = builder.build();
    this->m_frame = 0;
}

void GameWindow::run() {

    while (m_window->isOpen()) {

        sf::Event event{};

        while (m_window->pollEvent(event)) {
            this->handleEvent(this, event);
        }

        this->gameloop(this);

        this->drawloop(this);

    }
}

sf::RenderWindow *GameWindow::getWindow() {
    return this->m_window;
}

void GameWindow::handleEvent(IWindow *window, sf::Event &event) {

    if (m_eventHandlerFunction == nullptr) {
        switch (event.type) {
            case sf::Event::Closed:
                window->getWindow()->close();
                break;

            default:
                break;
        }

        return;
    }

    m_eventHandlerFunction(window, event);
}

void GameWindow::gameloop(IWindow *window) {

    m_frame++;

    if (m_gameLoopFunction == nullptr) {
        return;
    }

    m_gameLoopFunction(window);
}

void GameWindow::drawloop(IWindow *window) {

    if (m_drawLoopFunction == nullptr) {
        window->getWindow()->clear(sf::Color(10, 20, 50));
        window->getWindow()->display();

        return;
    }

    m_drawLoopFunction(window);
}

void GameWindow::setEventHandler(std::function<void(IWindow *, sf::Event &)> function) {

    this->m_eventHandlerFunction = function;
}

void GameWindow::setGameLoop(std::function<void(IWindow *)> function) {

    this->m_gameLoopFunction = function;
}

void GameWindow::setDrawLoop(std::function<void(IWindow *)> function) {

    this->m_drawLoopFunction = function;
}

unsigned int GameWindow::getFrame() {
    return m_frame;
}

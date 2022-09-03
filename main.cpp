#include "WindowBuilder/GameWindowBuilder.h"
#include "Window/GameWindow.h"

#include <iostream>
#include <chrono>
#include <random>

int main(int argc, char **argv) {

    auto windowBuilder = new GameWindowBuilder();
    windowBuilder->setTitle("Game Window")
            ->setWidth(1200)
            ->setHeight(900)
            ->setVSyncEnabled(true)
            ->setStyle(sf::Style::Default)
            ->removeStyle(sf::Style::Resize);

    GameWindow *window;
    window = new GameWindow(*windowBuilder);
    window->setEventHandler([](IWindow *window, sf::Event &event){
        switch (event.type) {
            case sf::Event::Closed:
                std::cout << "Good bye" << std::endl;
                window->getWindow()->close();
                break;

            default:
                break;
        }
    });
    window->setGameLoop([](IWindow *window) {
        std::cout << "game loop called" << std::endl;
    });
    window->setDrawLoop([](IWindow *window) {

        if (window->getFrame() % 6000 == 1) {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dist(0, 255);

            unsigned int red = dist(gen);
            unsigned int green = dist(gen);
            unsigned int blue = dist(gen);

            window->getWindow()->clear(sf::Color(red, green, blue));
            window->getWindow()->display();
        }

    });
    window->run();

    return EXIT_SUCCESS;
}

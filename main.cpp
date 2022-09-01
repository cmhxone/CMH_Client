#include "WindowBuilder/GameWindowBuilder.h"


int main(int argc, char** argv) {

    auto windowBuilder = new GameWindowBuilder();
    windowBuilder->setTitle("Game Window")
        ->setWidth(1200)
        ->setHeight(900)
        ->setVSyncEnabled(true)
        ->setStyle(sf::Style::Default)
        ->removeStyle(sf::Style::Resize);

    auto window = windowBuilder->build();
    window->setVerticalSyncEnabled(true);

    while (window->isOpen()) {

        sf::Event event{};
        while (window->pollEvent(event)) {

            switch (event.type) {
                case sf::Event::Closed:
                    window->close();
                    break;

                default:
                    break;
            }
        }

        window->clear(sf::Color(10, 30, 50));
        window->display();
    }

    return EXIT_SUCCESS;
}

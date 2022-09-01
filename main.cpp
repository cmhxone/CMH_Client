#include <iostream>
#include <SFML/Graphics.hpp>


int main(int argc, char** argv) {

    auto *window = new sf::RenderWindow(
            sf::VideoMode(1200, 900),
            "GameWindow",
            sf::Style::Default
    );
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

    return 0;
}

#include "WindowBuilder/GameWindowBuilder.h"
#include "Window/GameWindow.h"

#include "SocketBuilder/TcpSocketBuilder.h"
#include "Socket/TcpSocket.h"
#include "PropertyReader/PropertyReader.h"

#include <iostream>
#include <random>

int main(int argc, char **argv) {

    PropertyReader pr("application.properties");

    auto socketBuilder = new TcpSocketBuilder();
    socketBuilder->setBlocking(false);

    auto *socket = new TcpSocket(*socketBuilder);
    socket->setRemoteAddr(pr.getProperty("ip"));
    socket->setRemotePort(std::stoi(pr.getProperty("port")));
    socket->setOnConnectHandler([](ISocket *socket) {
       std::cout << "Connected" << std::endl;
       sf::Packet packet;
       packet << "Hello World\r\n";
       socket->send(packet);
    });
    socket->setOnDisonnectHandler([](ISocket *socket) {
        std::cout << "Disconnected" << std::endl;
    });
    socket->connect();

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
//        std::cout << "game loop called" << std::endl;
    });
    window->setDrawLoop([](IWindow *window) {

        if (window->getFrame() % 60'000 == 1) {
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

    socket->disconnect();

    return EXIT_SUCCESS;
}

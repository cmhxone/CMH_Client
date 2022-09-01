//
// Created by MH on 2022-09-01.
//

#ifndef CMH_CLIENT_IWINDOWBUILDER_H
#define CMH_CLIENT_IWINDOWBUILDER_H

#include <SFML/Graphics.hpp>

class IWindowBuilder {
public:
    ~IWindowBuilder() {};

    virtual sf::RenderWindow *build() = 0;

protected:

private:

};

#endif //CMH_CLIENT_IWINDOWBUILDER_H

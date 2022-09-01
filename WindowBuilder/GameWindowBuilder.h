//
// Created by MH on 2022-09-01.
//

#ifndef CMH_CLIENT_GAMEWINDOWBUILDER_H
#define CMH_CLIENT_GAMEWINDOWBUILDER_H

#include "IWindowBuilder.h"

class GameWindowBuilder : public IWindowBuilder {

public:
    sf::RenderWindow *build() override;

    [[nodiscard]] unsigned int getWidth() const;

    [[nodiscard]] unsigned int getHeight() const;

    [[nodiscard]] bool getVSyncEnabled() const;

    [[nodiscard]] const sf::String &getTitle() const;

    [[nodiscard]] int getStyle() const;

    GameWindowBuilder *setWidth(unsigned int width);

    GameWindowBuilder *setHeight(unsigned int height);

    GameWindowBuilder *setVSyncEnabled(bool enabled);

    GameWindowBuilder *setTitle(const sf::String &title);

    GameWindowBuilder *setStyle(int style);

    GameWindowBuilder *addStyle(int style);

    GameWindowBuilder *removeStyle(int style);


protected:
    unsigned int m_width = 800;
    unsigned int m_height = 600;
    bool m_vsync_enabled = false;
    int m_style;
    sf::String m_title = "CMH Client Default Game Window";

private:

};


#endif //CMH_CLIENT_GAMEWINDOWBUILDER_H

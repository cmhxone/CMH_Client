//
// Created by MH on 2022-09-01.
//

#include "GameWindowBuilder.h"

sf::RenderWindow *GameWindowBuilder::build() {
    auto *window = new sf::RenderWindow(
            sf::VideoMode(this->getWidth(), this->getHeight()),
            this->getTitle(),
            this->getStyle()
    );
    window->setVerticalSyncEnabled(this->getVSyncEnabled());

    return window;
}

unsigned int GameWindowBuilder::getWidth() const {
    return m_width;
}

unsigned int GameWindowBuilder::getHeight() const {
    return m_height;
}

bool GameWindowBuilder::getVSyncEnabled() const {
    return m_vsync_enabled;
}

const sf::String &GameWindowBuilder::getTitle() const {
    return m_title;
}

int GameWindowBuilder::getStyle() const {
    return m_style;
}

GameWindowBuilder *GameWindowBuilder::setWidth(unsigned int width) {
    this->m_width = width;
    return this;
};

GameWindowBuilder *GameWindowBuilder::setHeight(unsigned int height) {
    this->m_height = height;
    return this;
}

GameWindowBuilder *GameWindowBuilder::setVSyncEnabled(bool enabled) {
    this->m_vsync_enabled = enabled;
    return this;
}

GameWindowBuilder *GameWindowBuilder::setTitle(const sf::String &title) {
    this->m_title = title;
    return this;
}

GameWindowBuilder *GameWindowBuilder::setStyle(int style) {
    this->m_style = style;
    return this;
}

GameWindowBuilder *GameWindowBuilder::addStyle(int style) {
    this->m_style |= style;
    return this;
}

GameWindowBuilder *GameWindowBuilder::removeStyle(int style) {
    this->m_style &= ~style;
    return this;
}
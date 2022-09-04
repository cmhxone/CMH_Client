//
// Created by mh on 22. 9. 3.
//

#include "TcpSocketBuilder.h"

/**
 * Build a TcpSocket instance
 * @return
 */
sf::Socket *TcpSocketBuilder::build() {

    auto *socket = new sf::TcpSocket();
    socket->setBlocking(this->getBlocking());

    return socket;
}

/**
 * Get socket's blocking option
 * @return
 */
bool TcpSocketBuilder::getBlocking() const {
    return m_blocking;
}

/**
 * Set socket's blocking option
 * @param enable
 * @return
 */
TcpSocketBuilder *TcpSocketBuilder::setBlocking(bool enable) {
    m_blocking = enable;
    return this;
}


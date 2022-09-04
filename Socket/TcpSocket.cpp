//
// Created by mh on 22. 9. 3.
//

#include "TcpSocket.h"

#include <utility>

TcpSocket::TcpSocket(TcpSocketBuilder &builder) {
    m_socket = dynamic_cast<sf::TcpSocket *>(builder.build());
}

sf::Socket *TcpSocket::getSocket() {
    return m_socket;
}

void TcpSocket::connect() {
    sf::Socket::Status status = m_socket->connect(this->getRemoteAddr(), this->getRemotePort(), this->getConnectionTimeout());

    this->onConnect(this);
}

void TcpSocket::disconnect() {
    this->onDisconnect(this);
    m_socket->disconnect();
}

void TcpSocket::send(sf::Packet &packet) {
    onSend(this);
    m_socket->send(packet);
}

void TcpSocket::onConnect(ISocket *socket) {

    if (m_onConnectHandler == nullptr) {
        return;
    }

    m_onConnectHandler(socket);
}

void TcpSocket::onDisconnect(ISocket *socket) {

    if (m_onDisonnectHandler == nullptr) {
        return;
    }

    m_onDisonnectHandler(socket);
}

void TcpSocket::onReceive(ISocket *socket) {

    if (m_onReceiveHandler == nullptr) {
        return;
    }

    m_onReceiveHandler(socket);
}

void TcpSocket::onSend(ISocket *socket) {

    if (m_onSendHandler == nullptr) {
        return;
    }

    m_onSendHandler(socket);
}

const sf::IpAddress &TcpSocket::getRemoteAddr() const {
    return m_remoteAddr;
}

unsigned short TcpSocket::getRemotePort() const {
    return m_remotePort;
}

sf::Time TcpSocket::getConnectionTimeout() const {
    return sf::seconds(m_connection_timeout);
}

sf::Time TcpSocket::getIdleTimeout() const {
    return sf::seconds(m_idle_timeout);
}

void TcpSocket::setOnConnectHandler(std::function<void(ISocket *)> function) {
    m_onConnectHandler = std::move(function);
}

void TcpSocket::setOnDisonnectHandler(std::function<void(ISocket *)> function) {
    m_onDisonnectHandler = std::move(function);
}

void TcpSocket::setOnReceiveHandler(std::function<void(ISocket *)> function) {
    m_onReceiveHandler = std::move(function);
}

void TcpSocket::setOnSendHandler(std::function<void(ISocket *)> function) {
    m_onSendHandler = std::move(function);
}

void TcpSocket::setRemoteAddr(const sf::IpAddress &addr) {
    m_remoteAddr = addr;
}

void TcpSocket::setRemotePort(const unsigned short port) {
    m_remotePort = port;
}

void TcpSocket::setConnectionTimeout(const unsigned int timeout) {
    m_connection_timeout = timeout;
}

void TcpSocket::setIdleTimeout(const unsigned int timeout) {
    m_idle_timeout = timeout;
}

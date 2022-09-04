//
// Created by mh on 22. 9. 3.
//

#ifndef CMH_CLIENT_TCPSOCKET_H
#define CMH_CLIENT_TCPSOCKET_H

#include <functional>

#include "ISocket.h"
#include "../SocketBuilder/TcpSocketBuilder.h"

class TcpSocket : public ISocket {

public:
    explicit TcpSocket(TcpSocketBuilder &);

    sf::Socket *getSocket() override;

    void connect() override;

    void disconnect() override;

    void send(sf::Packet &) override;

    [[nodiscard]] const sf::IpAddress &getRemoteAddr() const;

    [[nodiscard]] unsigned short getRemotePort() const;

    [[nodiscard]] sf::Time getConnectionTimeout() const;

    [[nodiscard]] sf::Time getIdleTimeout() const;

    void setRemoteAddr(const sf::IpAddress &);

    void setRemotePort(const unsigned short);

    void setConnectionTimeout(const unsigned int);

    void setIdleTimeout(const unsigned int);

    void setOnConnectHandler(std::function<void(ISocket *)>);

    void setOnDisonnectHandler(std::function<void(ISocket *)>);

    void setOnReceiveHandler(std::function<void(ISocket *)>);

    void setOnSendHandler(std::function<void(ISocket *)>);

protected:
    void onConnect(ISocket *socket) override;

    void onDisconnect(ISocket *socket) override;

    void onReceive(ISocket *socket) override;

    void onSend(ISocket *socket) override;

private:
    sf::TcpSocket *m_socket;

    sf::IpAddress m_remoteAddr = "127.0.0.1";
    unsigned short m_remotePort = 20000;
    unsigned int m_connection_timeout = 10;
    unsigned int m_idle_timeout = 600;

    std::function<void(ISocket *)> m_onConnectHandler;
    std::function<void(ISocket *)> m_onDisonnectHandler;
    std::function<void(ISocket *)> m_onReceiveHandler;
    std::function<void(ISocket *)> m_onSendHandler;

};


#endif //CMH_CLIENT_TCPSOCKET_H

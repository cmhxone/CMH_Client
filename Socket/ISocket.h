//
// Created by mh on 22. 9. 3.
//

#ifndef CMH_CLIENT_ISOCKET_H
#define CMH_CLIENT_ISOCKET_H

#include <SFML/Network.hpp>

/**
 * Socket abstract class
 */
class ISocket {
public:
    /**
     * Get a Socket instance
     * @return
     */
    virtual sf::Socket *getSocket() = 0;

    /**
     * Connect to server socket
     */
    virtual void connect() = 0;

    /**
     * Disconnect from server socket
     */
    virtual void disconnect() = 0;

    /**
     * Send packet to server
     */
    virtual void send(sf::Packet &) = 0;

protected:
    /**
     * On connect event handler
     */
    virtual void onConnect(ISocket *) = 0;

    /**
     * On disconnect event handler
     */
    virtual void onDisconnect(ISocket *) = 0;

    /**
     * On receive packet event handler
     */
    virtual void onReceive(ISocket *) = 0;

    /**
     * On send packet event handler
     */
    virtual void onSend(ISocket *) = 0;

private:

};

#endif //CMH_CLIENT_ISOCKET_H

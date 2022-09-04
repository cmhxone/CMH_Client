//
// Created by mh on 22. 9. 3.
//

#ifndef CMH_CLIENT_ISOCKETBUILDER_H
#define CMH_CLIENT_ISOCKETBUILDER_H

#include <SFML/Network.hpp>

/**
 * TcpSocket builder abstact class
 */
class ISocketBuilder {

public:
    /**
     * Build a TcpSocket instance
     * @return
     */
    virtual sf::Socket *build() = 0;

protected:

private:

};

#endif //CMH_CLIENT_ISOCKETBUILDER_H

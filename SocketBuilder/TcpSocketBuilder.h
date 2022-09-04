//
// Created by mh on 22. 9. 3.
//

#ifndef CMH_CLIENT_TCPSOCKETBUILDER_H
#define CMH_CLIENT_TCPSOCKETBUILDER_H


#include "ISocketBuilder.h"

/**
 * TCP TcpSocket builder
 */
class TcpSocketBuilder : public ISocketBuilder {

public:
    sf::Socket *build() override;

    [[nodiscard]] bool getBlocking() const;

    TcpSocketBuilder *setBlocking(bool enable);

protected:

private:
    bool m_blocking = false;

};


#endif //CMH_CLIENT_TCPSOCKETBUILDER_H

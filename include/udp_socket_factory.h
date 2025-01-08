#ifndef UDPSOCKETFACTORY_H
#define UDPSOCKETFACTORY_H

#include "udp_socket.h"

class UDPSocketFactory {
public:
    static UDPSocketPtr createUDPSocket();
    
};

#endif

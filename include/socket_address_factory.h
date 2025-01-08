#ifndef SOCKETADDRESS_FACTORY_H
#define SOCKETADDRESS_FACTORY_H

#include "socket_address.h"

class SocketAddressFactory {
    public:
        static SocketAddressPtr CreateIPv4FromString(const std::string& inString);
};
#endif // !DEBUG

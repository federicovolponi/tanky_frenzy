#include "udp_socket_factory.h"

#include <cstring>

UDPSocketPtr UDPSocketFactory::createUDPSocket() {
    SOCKET s = socket(AF_INET, SOCK_DGRAM, 0);
    if (s < 0) {
        LOGGER::error(strerror(errno));
        return nullptr;
    }
    return UDPSocketPtr(new UDPSocket(s));
}

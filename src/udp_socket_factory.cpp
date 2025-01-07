#include "udp_socket_factory.h"

UDPSocketPtr UDPSocketFactory::createUDPSocket() {
    SOCKET s = socket(AF_INET, SOCK_DGRAM, 0);
    if (s < 0) {
        //TODO: Report error
        return nullptr;
    }
    return UDPSocketPtr(new UDPSocket(s));
}

#include "udp_socket_factory.h"

#include <cstring>

using std::runtime_error;

UDPSocketPtr UDPSocketFactory::createUDPSocket() {
    SOCKET s = socket(AF_INET, SOCK_DGRAM, 0);
    if (s < 0) {
        throw runtime_error(strerror(errno));
    }
    return UDPSocketPtr(new UDPSocket(s));
}

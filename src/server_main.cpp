#include <cstring>
#include <stdexcept>

#include "udp_socket_factory.h"
#include "socket_address_factory.h"

using std::runtime_error;

/* NETWORKING:
 * Process incoming packets
 * Accepting clients
 * Store clients
 * 
 * GAME SIDE:
 * Init non-client dependant objects
 * Player spawn position d
 */
#if 0
int main(int argc, const char *argv[]) {
    // Port number
    if (argc < 2) {
        throw runtime_error("You must specify the host and port number as HOSTNAME:PORT");
    }

    // Init Server
    //  * UDP socket
    //  * Game state
    UDPSocketPtr serverSocket = UDPSocketFactory::createUDPSocket();
    serverSocket->SetNonBlockingMode(true);

    SocketAddressPtr serverAddress = SocketAddressFactory::CreateIPv4FromString(argv[0]);
    serverSocket->Bind(*serverAddress);

    // Receive in game loop

}
#endif

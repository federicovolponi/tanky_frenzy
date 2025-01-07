#include "socket_address.h"

#include <cstring>

SocketAddress::SocketAddress(){
		GetAsSockAddrIn()->sin_family = AF_INET;
		GetIP4Ref() = INADDR_ANY;
		GetAsSockAddrIn()->sin_port = 0;
}

SocketAddress::SocketAddress(uint32_t inAddress, uint16_t inPort) {
    GetAsSockAddrIn()->sin_family = AF_INET;
    GetAsSockAddrIn()->sin_addr.s_addr = htonl(inAddress);
    GetAsSockAddrIn()->sin_port = htons(inPort);
}

SocketAddress::SocketAddress(const sockaddr& inSockAddr)
{
    memcpy(&mSockAddr, &inSockAddr, sizeof( sockaddr) );
}

uint32_t SocketAddress::GetSize() const {
    return sizeof(sockaddr);
}

sockaddr_in* SocketAddress::GetAsSockAddrIn(){
    return reinterpret_cast<sockaddr_in*>( &mSockAddr );
}

const sockaddr_in* SocketAddress::GetAsSockAddrIn()	const {
    return reinterpret_cast< const sockaddr_in* >( &mSockAddr ); 
}

uint32_t& SocketAddress::GetIP4Ref() { 
    return GetAsSockAddrIn()->sin_addr.s_addr; 
}

const uint32_t& SocketAddress::GetIP4Ref() const{
    return GetAsSockAddrIn()->sin_addr.s_addr; 
}

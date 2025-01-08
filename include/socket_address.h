#ifndef SOCKETADDRESS_H
#define SOCKETADDRESS_H

#include "globals.h"

#include <netinet/in.h>
#include <memory>

class SocketAddress
{
public:
	SocketAddress( uint32_t inAddress, uint16_t inPort );
	SocketAddress( const sockaddr& inSockAddr );
	SocketAddress();

	uint32_t GetSize() const;

private:
	friend class UDPSocket;
	// friend class TCPSocket;

	sockaddr mSockAddr;

    uint32_t& GetIP4Ref();
    const uint32_t& GetIP4Ref() const;	

	sockaddr_in* GetAsSockAddrIn();
	const sockaddr_in* GetAsSockAddrIn() const;
};

typedef std::shared_ptr< SocketAddress > SocketAddressPtr;

#endif

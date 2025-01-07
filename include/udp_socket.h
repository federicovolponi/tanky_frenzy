#ifndef UDPSOCKET_H
#define UDPSOCKET_H

#include "socket_address.h"

typedef int SOCKET;

class UDPSocket
{
public:

	~UDPSocket();

	int Bind( const SocketAddress& inToAddress );
	int SendTo( const void* inToSend, int inLength, const SocketAddress& inToAddress );
	int ReceiveFrom( void* inToReceive, int inMaxLength, SocketAddress& outFromAddress );

	int SetNonBlockingMode( bool inShouldBeNonBlocking );

private:
	friend class UDPSocketFactory;
	UDPSocket( SOCKET inSocket );
	SOCKET mSocket;

};

typedef std::shared_ptr< UDPSocket >	UDPSocketPtr;

#endif

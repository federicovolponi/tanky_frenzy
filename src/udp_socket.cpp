#include "udp_socket.h"

#include <unistd.h>
#include <fcntl.h>
#include <cstring>

UDPSocket::UDPSocket(SOCKET inSocket) {
    mSocket = inSocket;
}

int UDPSocket::Bind( const SocketAddress& inBindAddress )
{
	int error = bind( mSocket, &inBindAddress.mSockAddr, inBindAddress.GetSize() );
	if( error != 0 )
	{
        LOGGER::error(strerror(errno));
		return -1;
	}
	
	return 0;
}

int UDPSocket::SendTo( const void* inToSend, int inLength, const SocketAddress& inToAddress )
{
	int byteSentCount = sendto( mSocket,
							   static_cast< const char* >( inToSend ),
							   inLength,
							   0, &inToAddress.mSockAddr, inToAddress.GetSize() );
	if( byteSentCount <= 0 )
	{
        LOGGER::error(strerror(errno));
		return -1;
	}
	else
	{
		return byteSentCount;
	}
}

int UDPSocket::ReceiveFrom( void* inToReceive, int inMaxLength, SocketAddress& outFromAddress )
{
	socklen_t fromLength = outFromAddress.GetSize();
	
	int readByteCount = recvfrom( mSocket,
								 static_cast< char* >( inToReceive ),
								 inMaxLength,
								 0, &outFromAddress.mSockAddr, &fromLength );
	if( readByteCount < 0 )
	{
        LOGGER::error(strerror(errno));
        return -1;
	}
	return readByteCount;
}

UDPSocket::~UDPSocket()
{
	close(mSocket);
}


int UDPSocket::SetNonBlockingMode( bool inShouldBeNonBlocking )
{
	int flags = fcntl( mSocket, F_GETFL, 0 );
	flags = inShouldBeNonBlocking ? ( flags | O_NONBLOCK ) : ( flags & ~O_NONBLOCK);
	int result = fcntl( mSocket, F_SETFL, flags );
	
	if( result == -1 )
	{
        LOGGER::error(strerror(errno));
		return -1;
	}
    return 0;
}

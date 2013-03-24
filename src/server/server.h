#ifndef SERVER_H
#define SERVER_H

#include "../sockets/socket.h"
#include "../client/client.h"
#include "../connector/connector.h"

class server
{
	public:
		server();
		void run();
	private:
		socketCpp *sock;
};

#endif // SERVER_H

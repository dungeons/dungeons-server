#ifndef SERVER_H
#define SERVER_H

#include "../sockets/socket.h"

class server
{
	public:
		server();
		void run();
	private:
		socketCpp *sock;
};

#endif // SERVER_H

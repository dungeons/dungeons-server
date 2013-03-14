#ifndef SOCKET_H
#define SOCKET_H

#include <string>
#include <sstream>

#include <iostream>

#include "connection.h"
#include "sockex.h"

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <memory.h>
#include <unistd.h>

class socketCpp
{
	public:
		socketCpp();
		void bind(int addr,int port);
		connection accept();
		~socketCpp();
	private:
		sockaddr_in sock;
		int sockD;
};

#endif // SOCKET_H

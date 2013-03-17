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
#include <netdb.h>

/*
 * Author: Tomáš Černík
 * Desc: simple C++ wrapper for berkley sockets. 
 * 
 */

class socketCpp
{
	public:
		socketCpp();
		void bind(int addr,int port);
		void bind(int addr,int port,int connections);
		void connect(std::string addr, int port);
		connection accept();
		~socketCpp();
	private:
		sockaddr_in sock;
		int sock_d;
		void prepare();
};

#endif // SOCKET_H

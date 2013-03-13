#ifndef SOCKET_H
#define SOCKET_H

#include <string>
#include <sstream>

#include <iostream>

#include "connection.h"

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <memory.h>
#include <unistd.h>
#include <semaphore.h>

class socketCpp
{
	public:
		socketCpp();
		void bind(int addr,int port);
		connection* accept();
		~socketCpp();
	private:
		sockaddr_in sock;
		int sockD;
};

class socketEx
{
	public:
		socketEx(std::string data);
		socketEx(std::string data, const char* file, int line);
		std::string what();
	protected:
		std::string data;
};

class socketWarn: private socketEx
{
	public:
		socketWarn(std::string data);
};



#endif // SOCKET_H

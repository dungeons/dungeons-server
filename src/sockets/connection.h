#ifndef CONNECTION_H
#define CONNECTION_H

#include <string>

#include <sys/socket.h>

class sockEx;

class connection
{
	public:
		connection(int fd);
		std::string read();
		void write(std::string data);
		~connection();
	private:
		int fd;
		
};

#include "./socket.h"
#endif // CONNECTION_H

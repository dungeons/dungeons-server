#ifndef CONNECTION_H
#define CONNECTION_H

#include <string>

#include <sys/socket.h>
#include "./sockex.h"


#include <unistd.h>

class connection
{
	public:
		connection(int fd);
		std::string read(int max);
		std::string read_prec(int max);
		void write(std::string &data);
		~connection();
	private:
		int fd;
		
};

#endif // CONNECTION_H

#ifndef CONNECTION_H
#define CONNECTION_H

#include <string>

class connection
{
	public:
		connection(int fd);
		std::string read();
		void write(std::string data);

	private:
		int fd;
		
};

#endif // CONNECTION_H

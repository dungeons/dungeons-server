#include "./src/sockets/socket.h"

#include "./main.h"
#include <iostream>

#include "./src/sockets/socket.h"

int main()
{
	socketCpp q;
	try
	{
		q.bind(INADDR_ANY,5000);
		connection *p=q.accept();
		delete(p);
	}catch(socketEx &e)
	{
		std::cout <<e.what();
	}
}
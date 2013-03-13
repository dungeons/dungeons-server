#include "./src/sockets/socket.h"

#include "./main.h"
#include <iostream>

int main()
{
	server S;
	try
	{
		S.run();
	}catch(socketEx &e)
	{
		std::cout <<e.what();
	}
}
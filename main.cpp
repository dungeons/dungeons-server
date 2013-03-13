#include "./src/sockets/socket.h"

#include "./main.h"
#include <iostream>

#include "./src/sockets/socket.h"

int main()
{
	try
	{
		throw socketEx("ASD",__FILE__,__LINE__);
	}catch(socketEx e)
	{
		std::cout << e.what();
	}
	std::cout  << "OK";
}
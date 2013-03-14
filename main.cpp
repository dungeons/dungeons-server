#include "./src/sockets/socket.h"

#include "./main.h"
#include <iostream>

#include "./src/filter/filter.h"
int main()
{
	filter Q;
	server S;
	try
	{
		S.run();
	}catch(socketEx &e)
	{
		std::cout <<e.what();
	}
}
#include "server.h"

server::server()
{
	try
	{
		this->sock = new socketCpp();
		this->sock->bind(INADDR_ANY,5000);
		connection p=this->sock->accept();
		while(1)
			std::cout << p.read();
	}catch (socketEx &e)
	{
		std::cout << e.what();
	}
}


void server::run()
{
	delete this->sock;
}


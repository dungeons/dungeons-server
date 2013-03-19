#include "server.h"

server::server()
{
	try
	{
		this->sock = new socketCpp();
		this->sock->bind(INADDR_ANY,5000);
		connection p=this->sock->accept();
		for(int i=0;i<5;i++)
			p.read_prec(14);
	}catch (socketEx &e)
	{
		std::cout << e.what();
	}
}


void server::run()
{
	delete this->sock;
}


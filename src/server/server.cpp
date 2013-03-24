#include "server.h"

server::server()
{
	connector con;
	try
	{
		this->sock = new socketCpp();
		this->sock->bind(INADDR_ANY,5000);
		for(int i=0;i<1;i++)
		{
			connection *q=this->sock->accept();
			client *a = new client(*q,con);
			a->start();
			delete a;
		}
	}catch (socketEx &e)
	{
		std::cout << e.what();
	}
}

void server::run()
{
	delete this->sock;
}

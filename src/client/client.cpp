#include "client.h"
#include "../protocol/protocol.h"

client::client(connection &con,connector &connect) : connect(connect),c(con)
{
}

client::~client()
{
	
	this->c.~connection();
	this->~mutex_thread();
}

void client::do_job()
{
	while(this->running)
	{
		try{
			protocol p;
			std::string tmp;
			tmp=p.propery_data(1,1,1,1);
			this->c.write(tmp);
			std::string c=this->c.read_prec(14);
		}catch (socketEx &e)
		{
			std:: cout <<"e\n";
			this->running=0;
		}
	}
}


#include "connection.h"

connection::connection(int fd)
{
	this->fd=fd;
}

connection::~connection()
{
	::close(this->fd);
}

std::string connection::read(int max)
{
	char tmp[1024];
	int ret=recv(this->fd,tmp,max,0);
	if(ret <=0)
		throw socketEx("Invalid Read");
	std::string q(tmp,ret);
	return q;
}

void connection::write(std::string data)
{
	unsigned ret =::write(this->fd,data.c_str(),data.length());
	if(ret!=data.length())
		throw socketEx("Incomplete read");
}

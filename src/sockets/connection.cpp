#include "connection.h"

connection::connection(int fd)
{
	this->fd=fd;
}

connection::~connection()
{
	::close(this->fd);
}

std::string* connection::read(int max)
{
	char *tmp= new char[256];
	int ret=recv(this->fd,tmp,max,0);
	if(ret <=0)
		throw socketEx("Invalid Read");
	std::string *q = new std::string(tmp,ret);
	delete []tmp;
	return q;
}

void connection::write(std::string &data)
{
	unsigned ret =::write(this->fd,data.c_str(),data.length());
	if(ret!=data.length())
		throw socketEx("Incomplete read");
}

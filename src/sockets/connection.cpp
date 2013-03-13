#include "connection.h"

connection::connection(int fd)
{
	this->fd=fd;
}

std::string connection::read()
{
	char tmp[1024];
	int ret=recv(this->fd,tmp,1024,0);
	if(ret <0)
		throw socketEx("Invalid Read");
	std::string q;
	for(int i=0;i<ret;i++)
		q+=tmp[i];
	q=tmp;
	return q;
}

void connection::write(std::string data)
{
	int ret =write(this->fd,data.c_str(),data.length());
	if(ret!=data.length())
		throw socketEx("Incomplete read");
}

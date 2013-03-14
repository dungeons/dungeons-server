#include "socket.h"


socketCpp::socketCpp()
{
	this->sockD= ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	memset(&this->sock, 0, sizeof(this->sock));
	this->sock.sin_family = AF_INET;
	
}
void socketCpp::bind(int addr,int port)
{
	this->sock.sin_addr.s_addr = htonl(addr);
	this->sock.sin_port = htons(port);
	memset(&(this->sock.sin_zero),0,8);
	if(this->sockD<0)
		throw new socketEx("sockFD");
	int a=1;
	if(setsockopt(this->sockD, SOL_SOCKET, SO_REUSEADDR, &a,sizeof(int))!=0)
		throw new socketEx("Error changing socket option");
	if(::bind(this->sockD,(sockaddr*)&(this->sock),sizeof(sockaddr_in)))
		throw new socketEx("Error binding");
	listen(this->sockD,5);
}


socketCpp::~socketCpp()
{
	close(this->sockD);
}

connection socketCpp::accept()
{
	return connection(::accept(this->sockD,(struct sockaddr*)NULL, NULL));
}

#include "socket.h"



/*
	this->SocketDescriptor= socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	memset(&this->ServerSock, 0, sizeof(this->ServerSock));
	this->ServerSock.sin_family = AF_INET;
	this->ServerSock.sin_addr.s_addr = htonl(INADDR_ANY);
	this->ServerSock.sin_port = htons(COMPORT);
	memset(&(this->ServerSock.sin_zero),0,8);
*/

socketCpp::socketCpp()
{
	this->sockD= ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	memset(&this->sock, 0, sizeof(this->sock));
	this->sock.sin_family = AF_INET;
	
}
void socketCpp::bind(int addr,int port)
{
	this->sock.sin_addr.s_addr = htonl(INADDR_ANY);
	this->sock.sin_port = htons(5000);
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

connection* socketCpp::accept()
{
	int desc=::accept(this->sockD,(struct sockaddr*)NULL, NULL);
	std::cout << desc << std::endl;
	return new connection(desc);
}

socketEx::socketEx(std::string data)
{
	this->data=data;
}

socketEx::socketEx(std::string data, const char * file, int line)
{
	this->data=data+" in file:"+file+" on line:";
	std::stringstream q;
	q<<line;
	this->data+=q.str()+"\n";
}

std::string socketEx::what()
{
	return this->data;
}

socketWarn::socketWarn(std::string data): socketEx(data)
{

}




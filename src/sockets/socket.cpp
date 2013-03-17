#include "socket.h"


socketCpp::socketCpp()
{
}

void socketCpp::prepare()
{
	this->sock_d= ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(this->sock_d<0)
		throw new socketEx("Could not create socket");
	memset(&this->sock, 0, sizeof(this->sock));
	this->sock.sin_family = AF_INET;
}

void socketCpp::bind(int addr,int port, int connections)
{
	try
	{
		this->prepare();
	}catch(socketEx &e)
	{
		throw new socketEx(e.what());
	}
	this->sock.sin_addr.s_addr = htonl(addr);
	this->sock.sin_port = htons(port);
	memset(&(this->sock.sin_zero),0,8);
	if(this->sock_d<0)
		throw new socketEx("sockFD");
	int a=1;
	if(setsockopt(this->sock_d, SOL_SOCKET, SO_REUSEADDR, &a,sizeof(int))!=0)
		throw new socketEx("Error changing socket option");
	if(::bind(this->sock_d,(sockaddr*)&(this->sock),sizeof(sockaddr_in)))
		throw new socketEx("Error binding");
	listen(this->sock_d,connections);
}
void socketCpp::bind(int addr,int port)
{
	try
	{
		this->bind(addr,port,5);
	}catch(socketEx &e)
	{
		throw e;
	}
}

void socketCpp::connect(std::string addr, int port)
{
	this->sock.sin_port = htons(port);
	hostent *hostName;
	if ((hostName = gethostbyname(addr.c_str())) == NULL)
		throw new socketEx("Unknown host");
	std::string ip_address=(std::string)inet_ntoa(*((struct in_addr **)hostName->h_addr_list)[0]);
	if( inet_pton(AF_INET, ip_address.c_str(), &this->sock.sin_addr)<=0)
		throw new socketEx("Error");
}

socketCpp::~socketCpp()
{
	if(this->sock_d>=0)
		close(this->sock_d);
}

connection socketCpp::accept()
{
	return connection(::accept(this->sock_d,(struct sockaddr*)NULL, NULL));
}

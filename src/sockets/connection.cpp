#include "connection.h"

connection::connection(int fd) : fd(fd)
{
}


connection::~connection()
{
	
	::close(this->fd);
}

std::string connection::read(int max)
{
	char *tmp= new char[max];
	int ret=recv(this->fd,tmp,max,0);
	if(ret <=0)
		throw socketEx("Invalid Read");
	std::string q(tmp,ret);
	delete [] tmp;
	return q;
}

std::string connection::read_prec(int max)
{
	char *tmp= new char[max];
	int sum=0;
	std::string r;
	while(sum<max)
	{
		r+=this->read(max-sum);
		sum=r.length();
	}
	std::cout << "\n\t---------------------"<< sum <<"-----------------------\n";
	
	std::cout << "\t" << (int)(r[0]*256+r[1]) << "\n";
	std::cout << "\t" << (int)(r[5]*256+r[6])*256 << "\n";
	std::cout << "\t" << (int)(r[11]*256+r[12])*256 +r[13]<< "\n";
	
	std::cout << "\n\t-----------------------------------------------\n";
	delete [] tmp;
	return r;
}


void connection::write(std::string &data)
{
	unsigned ret =::write(this->fd,data.c_str(),data.length());
	if(ret!=data.length())
		throw socketEx("Incomplete read");
}

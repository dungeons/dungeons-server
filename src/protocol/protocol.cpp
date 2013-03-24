#include "protocol.h"

protocol::protocol()
{

}


std::string protocol::propery_data(int id, int component, int property, int val)
{
	std::string tmp;
	tmp+=this->prepare_4int(id);
	tmp+=this->prepare_2int(component);
 	tmp+=this->prepare_2int(property);
	tmp+=this->prepare_4int(val);
	return tmp;
}

//TODO change it!
std::string protocol::prepare_2int(int data)
{
	std::string tmp;
	for(register int i=0;i<2;i++)
	{
		tmp+=(char) data%256;
		data=(data-(data%256))/256;
	}
	return std::string(tmp.rbegin(),tmp.rend());
}


//TODO change it!
std::string protocol::prepare_4int(int data)
{
	std::string tmp;
	for(register int i=0;i<4;i++)
	{
		tmp+=(char) data%256;
		data=(data-(data%256))/256;
	}
	return std::string(tmp.rbegin(),tmp.rend());
}

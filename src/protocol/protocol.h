#ifndef PROTOCOL_H
#define PROTOCOL_H
#include "../sockets/connection.h"

class protocol
{
	public:
		protocol();
		std::string propery_data(int id, int component,int property, int val);
	private:
		std::string prepare_4int(int data);
		std::string prepare_2int(int data);
};

#endif // PROTOCOL_H

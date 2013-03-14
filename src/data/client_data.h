#ifndef CLIENT_DATA_H
#define CLIENT_DATA_H

#include "../sockets/connection.h"

class client_data
{
	public:
		client_data(connection con,int id);
	private:
		connection con;
		int id;
};

#endif // CLIENT_DATA_H

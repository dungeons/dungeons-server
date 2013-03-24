#include "connector.h"


int hash_for_client_id(int id)
{
	return id%1000;
}


connector::connector()
{
	
}


/*
 * Client part
 * 
 */
component* connector::get_client_component(int id, int component)
{

}

void connector::add_client(int id, client_data data)
{
	this->clients[id]=data;
}

void connector::remove_client(int id)
{
	this->clients.erase(id);
}
client_data connector::get_client(int id)
{
	return this->clients[id];
}

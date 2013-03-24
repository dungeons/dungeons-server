#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "../component/component.h"

#include "./client.h"
#include <functional>
#include <map>

#include <iostream>
class connector
{
	public:
		connector();

		component* get_client_component(int id, int component);
		void add_client(int id, client_data data);
		client_data get_client(int id);
		void remove_client(int id); 
		void save_state();
	private:
		std::map <int,client_data> clients;
		std::map <int,client_data> npc;

	
};

#endif // CONNECTOR_H

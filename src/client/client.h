#ifndef CLIENT_H
#define CLIENT_H


#include "../connector/connector.h"
#include "../mutex_thread/mutex_thread.h"
#include "../sockets/connection.h"
#include <iostream>

class client : public mutex_thread::mutex_thread
{
	public:
		client(connection &con,connector &connsect);
		virtual ~client();
	private:
		connector &connect;
		void do_job();
		connection &c;
};

#endif // CLIENT_H

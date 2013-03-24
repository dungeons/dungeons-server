#include "../../src/connector/connector.h"

#include <thread>

void insert(connector *a,int n)
{
	int max=1000;
	for(int i=0;i<max;i++)
		a->add_client(max*n+i,'a');
}

int main()
{
	connector a;
	a.add_client(1,'a');
	std::cout << a.get_client(1);
	a.remove_client(1);
	if(a.get_client(2))
		std::cout <<"ASDAD\n";
	if(a.get_client(1))
		std::cout <<"qASDAD\n";
	std::thread thread0= std::thread(insert,&a,0);
	std::thread threada= std::thread(insert,&a,1);
	std::thread threadb= std::thread(insert,&a,2);
	std::thread threadc= std::thread(insert,&a,3);
	thread0.join();
	threada.join();
	threadb.join();
	threadc.join();
	std::cout << a.get_client(2);
}


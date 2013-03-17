#include <iostream>

#include "../../src/mutex_thread/mutex_thread.h"


class Q: public mutex_thread::mutex_thread
{
	public:
		Q() : mutex_thread::mutex_thread()
		{};
		virtual ~Q()
		{
		}
	private:
		void do_job();
};
void Q::do_job()
{
	std::cout << "ASD";
}

int main()
{
	Q a;
	a.start();
	a.stop();
}
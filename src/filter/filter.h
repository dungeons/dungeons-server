#ifndef FILTER_H
#define FILTER_H

#include <time.h>

#include <unistd.h>

class filter
{
	public:
		filter();
		unsigned long count_sleep_time();
		void run();
		void stop_wait();
	private:
		clock_t last_run;
		const long frequency=50;
};

#endif // FILTER_H

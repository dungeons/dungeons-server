#ifndef FILTER_H
#define FILTER_H

#include <time.h>

#include <unistd.h>

class filter
{
	public:
		filter();
		unsigned long count_sleep_time();
	private:
		clock_t last_run;
		const long frequency=50;
};

#endif // FILTER_H

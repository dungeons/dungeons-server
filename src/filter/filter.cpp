#include "filter.h"

filter::filter()
{
	this->last_run=::clock();
}


//	usage:usleep(this->count_sleep_time());
/*
 * BUG: http://gafferongames.com/game-physics/fix-your-timestep/
 * 
 */
unsigned long filter::count_sleep_time()
{
	clock_t now=::clock();
	unsigned long passed=now-this->last_run;
	unsigned int clocks_round=CLOCKS_PER_SEC/this->frequency;
	this->last_run=now;
	if(passed <clocks_round)
		return (clocks_round-passed)*1000000/CLOCKS_PER_SEC;//returning in microseccons
	return 0;
}
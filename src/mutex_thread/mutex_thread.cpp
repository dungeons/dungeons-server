#include "mutex_thread.h"

mutex_thread::mutex_thread::mutex_thread(unsigned int usec)
{
	this->sleep_time=usec;	
}
mutex_thread::mutex_thread::mutex_thread()
{
	this->sleep_time=400000;
	this->state=STOPPED;
	this->running=1;
}

void mutex_thread::mutex_thread::pause()
{
	this->mux.lock();
}
void mutex_thread::mutex_thread::start()
{
	this->running=1;
	this->thread=new std::thread(mutex_thread::mutex_thread::run,this);
	this->mux.unlock();
}

//toto asi nepujde tak lehce poté obnovit akorát vytvořit nový vlákno?
void mutex_thread::mutex_thread::stop()
{
	this->running=0;
	this->mux.unlock();
}

void mutex_thread::mutex_thread::change_sleep_time(unsigned int usec)
{
	this->sleep_time=usec;
}

void mutex_thread::mutex_thread::run(mutex_thread* mx)
{
	mx->do_job();
}


#ifndef MUTEXTHREAD_H
#define MUTEXTHREAD_H

#include <mutex>
#include <thread>

/*
 * Author: Tomáš Černík
 * Mail: Tom.Cernik@gmail.com
 * 
 * Desc: simple class for simplyfing working with mutex threads
 */

namespace mutex_thread
{
	enum state_s
	{
		STARTING,
		SLEEPING,
		WORKING,
		STOPPED,
		ENDED
	};

	class mutex_thread
	{
		public:
			mutex_thread();
			mutex_thread(unsigned int usec);
			void start();
			void stop();
			void pause();
			void change_sleep_time(unsigned int usec);
			static void run(mutex_thread *mx);
		protected:
			void do_job();
			std::thread *thread;
			unsigned int sleep_time;
			bool running;
			std::mutex mux;
			state_s state;
	};

}



#endif // MUTEXTHREAD_H
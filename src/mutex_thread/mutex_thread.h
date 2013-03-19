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
			inline void operator()()
			{
				this->start();
			};
		public:
			mutex_thread();
			mutex_thread(unsigned int usec);
			mutex_thread(mutex_thread &m) =delete;
			virtual void start() final;
			virtual void stop() final;
			virtual void pause() final;
			void change_sleep_time(unsigned int usec);
			static void run(mutex_thread *mx);
		protected:
			virtual void do_job()=0;
			std::thread *thread;
			unsigned int sleep_time;
			bool running;
			std::mutex mux;
			state_s state;
	};

}



#endif // MUTEXTHREAD_H
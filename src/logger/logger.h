#ifndef LOGGER_H
#define LOGGER_H

#include <unistd.h>

#include <iostream>
#include <fstream>

#include <ctime>
#include <cstring>
#include <semaphore.h>

class logger
{
	public:
		logger(int LogLVL);
		~logger();
		void write(std::string data);
		void error(std::string data);
		void log(int loglevel,std::string data);
		void success(std::string data);
		//functions with 2 params
		void write(std::string moduleName,std::string data2);
		void error(std::string moduleName,std::string data2);
		void log(int loglevel,std::string moduleName,std::string data2);
		void success(std::string moduleName,std::string data2);
	private:
		sem_t *lock;
		int LogLevel;
		char * getTime();
		char NowTime[80];
		std::ostream *LogStream;
};
#endif // LOGGER_H

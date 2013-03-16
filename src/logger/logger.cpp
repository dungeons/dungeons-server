#include "logger.h"

logger::logger(int LogLVL)
{
	this->lock=new sem_t;//(sem_t*)malloc(sizeof(sem_t));
	sem_init(this->lock,1,1);

	char timeA[20];
	time_t rawtime=time ( NULL );
	tm *timeinfo = localtime ( &rawtime );
	strftime(timeA, sizeof(timeA), "%Y-%m-%d",timeinfo);
	std::string file="/var/log/Pepici/";
	
	file+=timeA;
	file+=".log";

#ifdef LOG_STDOUT
	this->LogStream=&std::cout;
#else
	this->LogStream= new std::ofstream(file.c_str(),std::ifstream::in|std::ifstream::app);
#endif

	this->LogLevel=LogLVL;

	this->success("LOG","initiated");
	std::string text="Logging on level ";
	text+=LogLVL+'0';
}
logger::~logger()
{
	if(this->LogStream!=&std::cout)
		delete this->LogStream;
	delete this->lock;
}

void logger::write(std::string data)
{
	sem_wait(this->lock);
	(*this->LogStream) << this->getTime() << ": " <<data <<std::endl;
	this->LogStream->flush();
	sem_post(this->lock);
}
void logger::write(std::string moduleName, std::string data)
{
	sem_wait(this->lock);
	(*this->LogStream) << this->getTime() <<": " << moduleName<< ": " <<data <<std::endl;
	this->LogStream->flush();
	sem_post(this->lock);
}
void logger::success(std::string data)
{
	sem_wait(this->lock);
	(*this->LogStream) << "\033[1;32m" << this->getTime()<< ": OK:" <<data << "\033[0m" <<std::endl;
	this->LogStream->flush();
	sem_post(this->lock);
}
void logger::success(std::string moduleName, std::string data)
{
	sem_wait(this->lock);
	(*this->LogStream) << "\033[1;32m" << this->getTime()<< ": " << moduleName << ": OK:" <<data << "\033[0m" <<std::endl;
	this->LogStream->flush();
	sem_post(this->lock);
}

char* logger::getTime()
{
	time_t rawtime=time ( NULL );
	tm *timeinfo = localtime ( &rawtime );
	strftime(this->NowTime, sizeof(this->NowTime), "%Y/%m/%d %H-%M-%S",timeinfo);
	return this->NowTime;
}
void logger::log(int loglevel, std::string data)
{
	if(this->LogLevel>=loglevel)
	{
		sem_wait(this->lock);
		(*this->LogStream) << "\033[1;33m" << this->getTime() << ": " <<data << "\033[0m" <<std::endl;
		this->LogStream->flush();	
		sem_post(this->lock);
	}
}

void logger::error(std::string data) //write+coloring
{
	sem_wait(this->lock);
	(*this->LogStream) << "\033[1;31m" << this->getTime() << ": ERR:" <<data << "\033[0m" <<std::endl;
	this->LogStream->flush();
	sem_post(this->lock);
}
void logger::error(std::string moduleName, std::string data)
{
	sem_wait(this->lock);
	(*this->LogStream) << "\033[1;31m" << this->getTime() << ": " << moduleName<< ": ERR:" <<data << "\033[0m" <<std::endl;
	this->LogStream->flush();
	sem_post(this->lock);
}

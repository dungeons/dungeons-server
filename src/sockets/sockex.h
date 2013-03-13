#ifndef SOCKEX_H
#define SOCKEX_H

class socketEx
{
	public:
		socketEx(std::string data);
		socketEx(std::string data, const char* file, int line);
		std::string what();
	protected:
		std::string data;
};

class socketWarn: private socketEx
{
	public:
		socketWarn(std::string data);
};

#endif // SOCKEX_H

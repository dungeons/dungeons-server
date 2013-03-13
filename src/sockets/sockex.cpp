#include "sockex.h"


socketEx::socketEx(std::string data)
{
	this->data=data;
}

socketEx::socketEx(std::string data, const char * file, int line)
{
	this->data=data+" in file:"+file+" on line:";
	std::stringstream q;
	q<<line;
	this->data+=q.str()+"\n";
}

std::string socketEx::what()
{
	return this->data;
}

socketWarn::socketWarn(std::string data): socketEx(data)
{

}




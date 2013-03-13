#include "map.h"


map::map(int width, int height)
{
	this->width=width;
	this->height=height;
	try
	{
		this->map= new point[width*height];
	}catch(std::bad_exception &e)
	{
		throw new std::exception("Error allocationg memory fo map.");
	}
}


int map::getHeight()
{
	return this->height;
}

int map::getWidth()
{
	return this->width;
}

point map::getPoint(int x, int y)
{
	if(x>=0 && y>=0 && x<this->width && y<this->height)
		return this->Map[x*this->width+y];
	else
		throw new std::exception("Map point out of bounds.");
}

map::~map()
{
	delete [] this->map;
}


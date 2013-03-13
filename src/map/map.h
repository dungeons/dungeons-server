#ifndef MAP_H
#define MAP_H


#include "./point.h"
#include <exception>


class map
{
	public:
		map(int width, int height);
		virtual ~map();
		int getHeight();
		int getWidth();
		void getPoint(int x, int y);
	private:
		int width;
		int height;
		point *map;
};

#endif // MAP_H

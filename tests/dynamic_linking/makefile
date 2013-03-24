all: main lib


lib: ./lib.h ./lib.cpp
	g++ -Wall -fPIC -c lib.cpp -g
	g++ -shared -Wl,-soname,libl.so -o libl.so lib.o
	


main: ./lib.h ./lib.cpp ./main.cpp
	g++ -Wall -o main main.cpp -ldl -g
	

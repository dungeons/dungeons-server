
all: modules test

.PHONY: modules

modules:
	cd ../../;make modules;

test: ./main.cpp ../../build/connector
	g++ -std=c++11 -o $@ $^ -lpthread
COMPILER=g++
PARAMS=-std=c++11 -pedantic -Wall -WExtrama
OUTPUTF=./build
SRC=./src

all: $(OUTPUTF)/socket $(OUTPUTF)/connection

$(OUTPUTF)/socket: $(SRC)/sockets/socket.cpp $(SRC)/sockets/socket.h
	$(COMPILER) -o $@ -c $(SRC)/sockets/socket.cpp

$(OUTPUTF)/connection: $(SRC)/sockets/connection.cpp $(SRC)/sockets/connection.h
	$(COMPILER) -o $@ -c $(SRC)/sockets/connection.cpp

server: main.cpp  $(SRC)/sockets/socket.cpp $(SRC)/sockets/socket.h
	$(COMPILER) -o $@ main.cpp $(OUTPUTF)/socket $(OUTPUTF)/connection
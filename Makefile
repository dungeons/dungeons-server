COMPILER=g++
PARAMS=-std=c++11 -pedantic -Wall -Wextra -O0
OUTPUTF=./build
WIN=./buildWin
SRC=./src

all: modules server

modules: $(OUTPUTF)/socket $(OUTPUTF)/connection $(OUTPUTF)/server $(OUTPUTF)/socketEX $(OUTPUTF)/filter

#socket exception
$(OUTPUTF)/socketEX: $(SRC)/sockets/sockex.cpp $(SRC)/sockets/sockex.h
	$(COMPILER) $(PARAMS) -o $@ -c $(SRC)/sockets/sockex.cpp

$(OUTPUTF)/socket: $(SRC)/sockets/socket.cpp $(SRC)/sockets/socket.h
	$(COMPILER) $(PARAMS) -o $@ -c $(SRC)/sockets/socket.cpp

$(OUTPUTF)/connection: $(SRC)/sockets/connection.cpp $(SRC)/sockets/connection.h
	$(COMPILER) $(PARAMS) -o $@ -c $(SRC)/sockets/connection.cpp

$(OUTPUTF)/server: $(SRC)/server/server.cpp $(SRC)/server/server.h
	$(COMPILER) $(PARAMS) -o $@ -c $(SRC)/server/server.cpp

$(OUTPUTF)/filter: $(SRC)/filter/filter.cpp $(SRC)/filter/filter.h
	$(COMPILER) $(PARAMS) -o $@ -c $(SRC)/filter/filter.cpp

server: main.cpp  $(OUTPUTF)/socket $(OUTPUTF)/connection $(OUTPUTF)/server $(OUTPUTF)/socketEX $(OUTPUTF)/filter
	$(COMPILER) $(PARAMS) -o $@ $^

.PHONY: clean


#win: modules $(WIN)/server.exe
#
#$(WIN)/server.exe: main.cpp  $(SRC)/sockets/socket.cpp $(SRC)/sockets/socket.h
#	$(COMPILER) $(PARAMS) -o $@ main.cpp $(OUTPUTF)/socket $(OUTPUTF)/connection


clean:
	@rm -f ./server
	@rm -f ./build/*
	@rm -f ./buildWin/*
	@find -type f -regex ".*~$$" -delete
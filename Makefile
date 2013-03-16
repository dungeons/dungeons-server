COMPILER=g++
PARAMS=-std=c++11 -pedantic -Wall -Wextra -O0
OUTPUTF=./build
WIN=./buildWin
SRC=./src

all: modules server

modules: $(OUTPUTF)/socket $(OUTPUTF)/connection $(OUTPUTF)/server $(OUTPUTF)/socketEX $(OUTPUTF)/filter $(OUTPUTF)/mutex_thread $(OUTPUTF)/logger

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

$(OUTPUTF)/mutex_thread: $(SRC)/mutex_thread/mutex_thread.cpp $(SRC)/mutex_thread/mutex_thread.h
	$(COMPILER) $(PARAMS) -o $@ -c $(SRC)/mutex_thread/mutex_thread.cpp

$(OUTPUTF)/logger: $(SRC)/logger/logger.cpp $(SRC)/logger/logger.h
	$(COMPILER) $(PARAMS) -o $@ -c $(SRC)/logger/logger.cpp

server: main.cpp  $(OUTPUTF)/socket $(OUTPUTF)/connection $(OUTPUTF)/server $(OUTPUTF)/socketEX $(OUTPUTF)/filter
	$(COMPILER) $(PARAMS) -o $@ $^

.PHONY: clean

clean:
	@rm -f ./server
	@rm -f ./build/*
	@rm -f ./buildWin/*
	@find -type f -regex ".*~$$" -delete
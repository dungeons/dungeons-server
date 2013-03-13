COMPILER=g++
PARAMS=-std=c++11 -pedantic -Wall -Wextra
OUTPUTF=./


map/map: ./map/map.cpp ../src/map/map.cpp  ../src/map/map.h ../src/map/point.h  ../src/map/point.cpp
	$(COMPILER) $(PARAMS) -o $@  $^
	
	
.PHONY:clean


clean:
	@rm ./map/map
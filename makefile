CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Iinclude

COMMON_OBJ = main.o utils.o timeMeasurement.o 

all: main

main: $(COMMON_OBJ) functions.o
	$(CXX) $(COMMON_OBJ) functions.o -o main

main.o: src/main.cpp include/mylib.h include/utils.h include/functions.h include/timeMeasurement.h
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o main.o

functions.o: src/functions.cpp include/mylib.h include/functions.h include/utils.h include/timeMeasurement.h
	$(CXX) $(CXXFLAGS) -c src/functions.cpp -o functions.o

utils.o: src/utils.cpp include/mylib.h include/utils.h include/constants.h
	$(CXX) $(CXXFLAGS) -c src/utils.cpp -o utils.o

timeMeasurement.o: src/timeMeasurement.cpp include/mylib.h include/timeMeasurement.h
	$(CXX) $(CXXFLAGS) -c src/timeMeasurement.cpp -o timeMeasurement.o

clean:
	rm -f $(COMMON_OBJ) functions.o main 

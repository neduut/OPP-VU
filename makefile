CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Iinclude

COMMON_OBJ = main.o utils.o timeMeasurement.o

all: main

main: $(COMMON_OBJ) vector.o
	$(CXX) $(COMMON_OBJ) vector.o -o main

main.o: src/main.cpp include/main.h
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o main.o

vector.o: src/vector.cpp include/vector.h
	$(CXX) $(CXXFLAGS) -c src/vector.cpp -o vector.o

utils.o: src/utils.cpp include/utils.h
	$(CXX) $(CXXFLAGS) -c src/utils.cpp -o utils.o

timeMeasurement.o: src/timeMeasurement.cpp include/timeMeasurement.h
	$(CXX) $(CXXFLAGS) -c src/timeMeasurement.cpp -o timeMeasurement.o

clean:
	rm -f $(COMMON_OBJ) vector.o main

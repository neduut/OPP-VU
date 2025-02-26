CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

COMMON_OBJ = main.o utils.o

all: main

main: $(COMMON_OBJ) vector.o
	$(CXX) $(COMMON_OBJ) vector.o -o main

main.o: main.cpp main.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

vector.o: vector.cpp vector.h
	$(CXX) $(CXXFLAGS) -c vector.cpp -o vector.o

utils.o: utils.cpp utils.h
	$(CXX) $(CXXFLAGS) -c utils.cpp -o utils.o

clean:
	rm -f $(COMMON_OBJ) vector.o main

CXX = g++

COMMON_OBJ = main.o utils.o

# default 
main: vector

vector: $(COMMON_OBJ) vector.o
	$(CXX) $(COMMON_OBJ) vector.o -o main
    
mixed: $(COMMON_OBJ) mixed.o
	$(CXX) $(COMMON_OBJ) mixed.o -o main

main.o: main.cpp main.h
	$(CXX) -c main.cpp -o main.o

mixed.o: mixed.cpp mixed.h
	$(CXX) -c mixed.cpp -o mixed.o

vector.o: vector.cpp vector.h
	$(CXX) -c vector.cpp -o vector.o

utils.o: utils.cpp utils.h
	$(CXX) -c utils.cpp -o utils.o

clean:
	rm -f $(COMMON_OBJ) mixed.o vector.o main

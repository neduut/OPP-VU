CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Iinclude -Ivector
COMMON_OBJ = main.o functions1.o utils1.o timeMeasurement1.o 

all: main

main: $(COMMON_OBJ)
	$(CXX) $(COMMON_OBJ) -o main

main.o: src/main.cpp include/mylib1.h include/functions1.h include/utils1.h include/timeMeasurement1.h
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o main.o

functions1.o: src/functions1.cpp include/mylib1.h include/functions1.h include/timeMeasurement1.h
	$(CXX) $(CXXFLAGS) -c src/functions1.cpp -o functions1.o

utils1.o: src/utils1.cpp include/mylib1.h include/utils1.h include/constants1.h
	$(CXX) $(CXXFLAGS) -c src/utils1.cpp -o utils1.o

timeMeasurement1.o: src/timeMeasurement1.cpp include/mylib1.h include/timeMeasurement1.h
	$(CXX) $(CXXFLAGS) -c src/timeMeasurement1.cpp -o timeMeasurement1.o

assets: 
	cp -r ../assets/* ./output/

clean:
	rm -f $(COMMON_OBJ) main

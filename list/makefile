CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Iinclude -Ivector
COMMON_OBJ = main.o functions.o utils.o timeMeasurement.o 

all: main

main: $(COMMON_OBJ)
	$(CXX) $(COMMON_OBJ) -o main

main.o: src/main.cpp include/mylib.h include/functions.h include/utils.h include/timeMeasurement.h
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o main.o

functions.o: src/functions.cpp include/mylib.h include/functions.h include/timeMeasurement.h
	$(CXX) $(CXXFLAGS) -c src/functions.cpp -o functions.o

utils.o: src/utils.cpp include/mylib.h include/utils.h include/constants.h
	$(CXX) $(CXXFLAGS) -c src/utils.cpp -o utils.o

timeMeasurement.o: src/timeMeasurement.cpp include/mylib.h include/timeMeasurement.h
	$(CXX) $(CXXFLAGS) -c src/timeMeasurement.cpp -o timeMeasurement.o

assets: 
	cp -r ../assets/* ./output/

clean:
	rm -f $(COMMON_OBJ) main

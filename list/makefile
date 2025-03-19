CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Iinclude -Ivector
COMMON_OBJ = main.o functions2.o utils2.o timeMeasurement2.o 

all: main

main: $(COMMON_OBJ)
	$(CXX) $(COMMON_OBJ) -o main

main.o: src/main.cpp include/mylib2.h include/functions2.h include/utils2.h include/timeMeasurement2.h
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o main.o

functions2.o: src/functions2.cpp include/mylib2.h include/functions2.h include/timeMeasurement2.h
	$(CXX) $(CXXFLAGS) -c src/functions2.cpp -o functions2.o

utils2.o: src/utils2.cpp include/mylib2.h include/utils2.h include/constants2.h
	$(CXX) $(CXXFLAGS) -c src/utils2.cpp -o utils2.o

timeMeasurement2.o: src/timeMeasurement2.cpp include/mylib2.h include/timeMeasurement2.h
	$(CXX) $(CXXFLAGS) -c src/timeMeasurement2.cpp -o timeMeasurement2.o

assets: 
	cp -r ../assets/* ./output/

clean:
	rm -f $(COMMON_OBJ) main

main: main.o mixed.o vector.o validations.o
	g++ main.o mixed.o vector.o validations.o -o main

main.o: main.cpp main.h
	g++ -c main.cpp -o main.o

mixed.o: mixed.cpp mixed.h
	g++ -c mixed.cpp -o mixed.o

vector.o: vector.cpp vector.h
	g++ -c vector.cpp -o vector.o

validations.o: validations.cpp validations.h
	g++ -c validations.cpp -o validations.o

clean:
	rm -f *.o main

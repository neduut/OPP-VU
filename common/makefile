main: main.o c_array.o vector.o validations.o
	main.o c_array.o vector.o validations.o -o main

main.o: main.cpp main.h
	main.cpp -o main.o

c_array.o: c_array.cpp c_array.h
	c_array.cpp -o c_array.o

vector.o: vector.cpp vector.h
	vector.cpp -o vector.o

# common files
validations.o: validations.cpp validations.h
	validations.cpp -o validations.o

clean:
	rm -f *.o main
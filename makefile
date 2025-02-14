main: functions.o 
	g++ -o main main.cpp  functions.cpp

functions:
	g++ -c functions.cpp

clean:
	cmd /C del *.o main

boolean_exe: main.o boolean.o
	g++ -Wall -g main.o boolean.o -o boolean_exe

main.o: main.cpp boolean.h
	g++ -Wall -g  -c main.cpp

boolean.o: boolean.cpp boolean.h
	g++ -Wall -g -c boolean.cpp

execute: statistics.o main.o
	g++ -Wall -g statistics.o main.o  -o execute

statistics.o: statistics.cpp statistics.h
	g++ -Wall -c statistics.cpp

main.o: main.cpp statistics.h
	g++ -Wall -c main.cpp

main_exe: main.cpp statistics.h statistics.cpp
	g++ -Wall -g main.cpp statistics.cpp -o main_exe

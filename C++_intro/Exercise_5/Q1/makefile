prime_exe: prime.o main.o
	g++ -Wall -g prime.o main.o -o prime_exe

prime.o: prime.cpp prime.h
	g++ -Wall -c prime.cpp

main.o: main.cpp prime.h
	g++ -Wall -c main.cpp

Matrices_exe: Matrix.o main.o
	g++ -Wall -g Matrix.o main.o -o Matrices_exe

Matrix.o: Matrix.cpp Matrix.h
	g++ -Wall -c Matrix.cpp

main.o: main.cpp Matrix.h
	g++ -Wall -c main.cpp

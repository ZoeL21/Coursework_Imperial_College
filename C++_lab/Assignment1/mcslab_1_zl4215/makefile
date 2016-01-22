sudoku: sudoku.o main.o
	g++ -Wall -g -std=c++11 sudoku.o main.o -o sudoku
sudoku.o: sudoku.cpp sudoku.h
	g++ -Wall -c sudoku.cpp
main.o: main.cpp sudoku.h
	g++ -Wall -std=c++11 -c main.cpp

EXE = correct
FLAGS = g++ -Wall -g

$(EXE) : correct.o main.o
	$(FLAGS) correct.o main.o -o $(EXE)

correct.o: correct.cpp correct.h
	$(FLAGS) -c correct.cpp

main.o: main.cpp correct.h
	$(FLAGS) -c main.cpp

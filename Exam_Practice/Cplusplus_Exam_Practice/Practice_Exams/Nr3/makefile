EXE = words
FLAGS = g++ -Wall -g

$(EXE) : words.o main.o
	$(FLAGS) main.o words.o -o $(EXE)

main.o: main.cpp words.h
	$(FLAGS) -c main.cpp

words.o: words.cpp words.h
	$(FLAGS) -c words.cpp

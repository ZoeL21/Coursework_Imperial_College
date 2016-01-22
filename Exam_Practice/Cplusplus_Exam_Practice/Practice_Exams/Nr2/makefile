EXE = soundex
FLAGS = g++ -Wall -g

$(EXE): soundex.o main.o
	$(FLAGS) soundex.o main.o -o $(EXE)

soundex.o: soundex.cpp soundex.h
	$(FLAGS) -c soundex.cpp

main.o: main.cpp soundex.h
	$(FLAGS) -c main.cpp

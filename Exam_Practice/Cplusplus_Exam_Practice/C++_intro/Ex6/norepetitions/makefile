EXE = no_rep
FLAGS = g++ -Wall -g

$(EXE): main.o no_repetitions.o
	$(FLAGS) main.o no_repetitions.o -o $(EXE)

main.o: main.cpp
	$(FLAGS) -c main.cpp

no_repetitions.o: no_repetitions.cpp
	$(FLAGS) -c no_repetitions.cpp

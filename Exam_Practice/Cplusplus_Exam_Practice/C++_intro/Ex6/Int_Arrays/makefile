FLAGS= g++ -Wall 
EXE = arrays

$(EXE):arrays.o main.o
	$(FLAGS) arrays.o main.o -o $(EXE)

arrays.o: arrays.cpp arrays.h
	$(FLAGS) -c arrays.cpp

main.o: main.cpp arrays.h
	$(FLAGS) -c main.cpp

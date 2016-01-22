EXE = matrix_mult
FLAGS = g++ -Wall -g

$(EXE): matrix.o main.o
	$(FLAGS) matrix.o main.o -o $(EXE)

%.o: %.cpp
	$(FLAGS) -c $<

clean:
	\rm -f *.o $(EXE)

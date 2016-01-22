EXE = braille
FLAGS = g++ -Wall -g 
OBJ = braille.o main.o

$(EXE):$(OBJ)
	$(FLAGS)$(OBJ) -o $(EXE)

%.o:%.cpp
	$(FLAGS) -c $<

clean:
	\rm-f *.o *.d$(EXE)

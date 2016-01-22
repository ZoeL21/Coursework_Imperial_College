EXE = tube
FLAGS = g++ -Wall -g
OBJ = tube.cpp main.cpp

$(EXE):$(OBJ)
	$(FLAGS) $(OBJ) -o $(EXE)

%.o: %.cpp
	$(FLAGS) -o $<


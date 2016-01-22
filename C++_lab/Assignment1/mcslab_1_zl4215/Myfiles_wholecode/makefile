OBJ = main.o sudoku.o
EXE = sudoku
CPPFLAGS = -Wall -std=c++11

$(EXE): $(OBJ)
	g++ -g $(CPPFLAGS) $(OBJ) -o $(EXE)

%.o: %.cpp %.h
	g++ -Wall $(CPPFLAGS) -c $<


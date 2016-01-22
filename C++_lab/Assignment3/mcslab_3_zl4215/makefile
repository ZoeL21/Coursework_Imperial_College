HEADER = ChessBoard.h ChessPieces.h Header.h
CPPFLAGS = g++ -Wall -std=c++11 -g
OBJ = Piece.o King.o Queen.o Pawn.o Knight.o Rook.o ChessBoard.o Bishop.o ChessMain.o Colour.cpp
EXE = chess

$(EXE): $(OBJ) 
	$(CPPFLAGS) $(OBJ) -o $(EXE)

%.o: %.cpp 
	$(CPPFLAGS) -c $<


clean:
	\rm -f *.o *.d $(EXE)




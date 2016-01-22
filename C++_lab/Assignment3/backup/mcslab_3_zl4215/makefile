HEADER = ChessBoard.h ChessPieces.h
CPPFLAGS = g++ -Wall -std=c++11 -g
OBJ = Piece.o King.o Queen.o Pawn.o Knight.o Rook.o ChessBoard.o Bishop.o ChessMain.o
EXE = chess

$(EXE): $(OBJ)
	$(CPPFLAGS) $(OBJ) -o $(EXE)

Piece.o: Piece.cpp $(HEADER)
	$(CPPFLAGS) -c Piece.cpp

ChessBoard.o: ChessBoard.cpp $(HEADER)
	$(CPPFLAGS) -c ChessBoard.cpp

King.o: King.cpp $(HEADER)
	$(CPPFLAGS) -c King.cpp

Queen.o: Queen.cpp $(HEADER)
	$(CPPFLAGS) -c Queen.cpp

Pawn.o: Pawn.cpp $(HEADER)
	$(CPPFLAGS) -c Pawn.cpp

Knight.o: Knight.cpp $(HEADER)
	$(CPPFLAGS) -c Knight.cpp

Rook.o: Rook.cpp $(HEADER)
	$(CPPFLAGS) -c Rook.cpp

Bishop.o: Bishop.cpp $(HEADER)
	$(CPPFLAGS) -c Bishop.cpp

ChessMain.o: ChessMain.cpp $(HEADER)
	$(CPPFLAGS) -c ChessMain.cpp



clean:
	\rm *.o *~ $(EXE)

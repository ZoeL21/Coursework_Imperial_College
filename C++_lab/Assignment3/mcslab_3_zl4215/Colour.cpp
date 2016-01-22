#include "ChessBoard.h"
#include "ChessPieces.h"
#include "Header.h"

using namespace std;



/*FUNCTION DEFINITION of output_colour*/
string output_colour(piece_colour colour){
  string output;  
  switch (colour){
  case Black:output = "Black";
    break;
  case White: output = "White";
    break;
  }
  return output;
}
/*****END OF FUNCTION DEFINITION*****/

/*FUNCTION DEFINITION of opp_colour*/
piece_colour opp_colour(piece_colour colour){
  if(colour == White)
    return Black;
  else
    return White;
}
/*****END OF FUNCTION DEFINITION*****/

#include "ChessBoard.h"
#include "ChessPieces.h"
#include "Header.h"


//constructor
Rook::Rook(piece_colour _colour, string _name):Piece(){
  colour = _colour;  
  name = _name;
}
//destructor
Rook::~Rook(){}

/*FUNCTION DEFINITION of overridden function is_valid_move*/
bool Rook::is_valid_move(string org,string dest){

  //if movement is diagonal
  if(dest[0] - org[0]  != 0 && dest[1] - org[1] != 0){
    return false;
  }

  //otherwise movement is allowed
  return true;
}
/****END OF FUNCTION DEFINTITION*****/


/*FUNCTION DEFINITION of overridden function advance*/
string Rook::advance(string org,string dest){

  int distance = 0;

  //move along row
  if(dest[0] - org[0] != 0){
    distance = dest[0] - org[0];
    (distance > 0) ? org[0]++:org[0]--;
    //return new string position
    string new_position = string() + org[0] + org[1];    
    return new_position;
  }
  else{
  //move along column
    distance = dest[1] - org[1];
    (distance > 0) ? org[1]++:org[1]--;
    //return new string position
    string new_position = string() + org[0] + org[1];
    return new_position;
  }
} 
/****END OF FUNCTION DEFINTITION*****/

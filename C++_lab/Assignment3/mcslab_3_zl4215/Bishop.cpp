#include "ChessBoard.h"
#include "ChessPieces.h"
#include "Header.h"


//constructor
Bishop::Bishop(piece_colour _colour, string _name):Piece(){
  colour = _colour;  
  name = _name;
}
//destructor
Bishop::~Bishop(){}

/*FUNCTION DEFINITION of overridden function is_valid_move*/
bool Bishop::is_valid_move(string org,string dest){

  //if movement not diagonal
  if(!(dest[0] - org[0] != 0 && dest[1] - org[1] != 0)){
    return false;
  }

  //if not a straight diagonal
  if(abs(dest[0] - org[0]) != abs(dest[1] - org[1])){
    return false;
  }

  //otherwise move is allowed
  return true;
};
/****END OF FUNCTION DEFINTITION*****/


/*FUNCTION DEFINITION of overridden function advance*/
string Bishop::advance(string org,string dest){

  int direction = 0;

  //change column
  direction = (dest[0] - org[0]);
  (direction > 0) ? org[0]++ : org[0]--;

  //change row
  direction = (dest[1] - org[1]);
  (direction > 0) ? org[1]++ : org[1]--;

  //concatenate to string;
  string new_position = string() + org[0] + org[1];
  return new_position;

}
/****END OF FUNCTION DEFINTITION*****/

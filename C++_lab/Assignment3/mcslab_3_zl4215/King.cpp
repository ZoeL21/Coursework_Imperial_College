#include "ChessBoard.h"
#include "ChessPieces.h"
#include "Header.h"


//constructor
King::King(piece_colour _colour,string _name):Piece(){
  colour = _colour;  
  name = _name; 
}
//destructor
King::~King(){}

/*FUNCTION DEFINITION of overridden function is_valid_move*/
bool King::is_valid_move(string org,string dest){

  //check if the piece is allowed to move to dest
  if(abs(org[0] - dest[0]) > 1 || (abs(org[1] - dest[1])) > 1){
    return false;
  }

  //otherwise, just allow move
  return true;

};
/****END OF DEFINITIONS*****/

/*FUNCTION DEFINITION of overridden function advance*/
string King::advance(const string org,const string dest){
  //as King can only advance one step, return dest
  return dest;
}
/****END OF DEFINITIONS*****/



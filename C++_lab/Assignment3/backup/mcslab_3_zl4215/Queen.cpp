#include "ChessBoard.h"
#include "ChessPieces.h"


//constructor
Queen::Queen(piece_colour _colour, string _name):Piece(){
  colour = _colour;  
  name = _name;
}
//destructor
Queen::~Queen(){} 


/*FUNCTION DEFINITION of overridden function is_valid_move*/
bool Queen::is_valid_move(string org,string dest){

  //if movement is not a straight diagonal
  if(dest[0] - org[0] != 0 && dest[1] - org[1] != 0){
    if(abs(dest[0] - org[0]) != abs(dest[1] - org[1])){
	return false;
      }
  }

  //otherwise allow      
  return true;

};
/****END OF FUNCTION DEFINTITION*****/



/*FUNCTION DEFINITION of overridden function advance*/
string Queen::advance(string org,string dest){

  int direction = 0;

  //moving along diagonal
  if(dest[0] - org[0] != 0 && dest[1] - org[1] != 0){

    //change column
    direction = (dest[0] - org[0]);
    (direction > 0) ? org[0]++ : org[0]--;
    
    //change row
    direction = (dest[1] - org[1]);
    (direction > 0) ? org[1]++ : org[1]--;

    //conatenate to string;
    string new_position = string() + org[0] + org[1];
    return new_position;
  }

  //moving along rows
  else if(dest[0] - org[0] == 0){
    direction = (dest[1] - org[1]);
    (direction > 0) ? org[1]++: org[1]--;
    string new_position = string() + org[0] + org[1];
    return new_position;
  }

  //moving along columns
  else{
    direction = (dest[0] - org[0]);
    (direction > 0) ? org[0]++: org[0]--;
    string new_position = string() + org[0] + org[1];
    return new_position;
  }


}
/****END OF FUNCTION DEFINTITION*****/



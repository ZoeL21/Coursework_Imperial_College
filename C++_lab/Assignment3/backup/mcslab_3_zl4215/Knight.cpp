#include "ChessBoard.h"
#include "ChessPieces.h"
#include <string>

using namespace std;

//constructor
Knight::Knight(piece_colour _colour, string _name):Piece(){
  colour = _colour;  
  name = _name;
}

//destructor
Knight::~Knight(){}
  


/*FUNCTION DEFINITION of overridden function is_valid_move*/
bool Knight::is_valid_move(string org,string dest){
  
  int dist_row = abs(dest[0] - org[0]);
  int dist_col = abs(dest[1] - org[1]);
  /*either advance two fields in row,
    or two fields in column or vice versa*/
  if((dist_row == 2 && dist_col == 1) || (dist_row == 1 && dist_col == 2)){
    return true;
  }
 
  return false;
}
/****END OF FUNCTION DEFINTITION*****/

/*FUNCTION DEFINITION of overridden function advance*/
string Knight::advance(string org,string dest){
  //as Knight jumps directly to dest
  return dest;
}
/****END OF FUNCTION DEFINTITION*****/

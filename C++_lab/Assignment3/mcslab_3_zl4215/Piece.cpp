#include "ChessBoard.h"
#include "ChessPieces.h"
#include "Header.h"

//constrcutor
Piece::Piece(){
  };

//virtual destructor
Piece::~Piece(){
  //cout<<"destroying Piece interface"<<endl;
  }

/*FUNCTION DEFINITION of get_colour*/
piece_colour Piece::get_colour(){
  return colour;
}
/****END OF FUNCTION DEFINTITION*****/

/*FUNCTION DEFINITION of get_name*/
string Piece::get_name(){
  return name;
}
/****END OF FUNCTION DEFINTITION*****/





#include "ChessBoard.h"
#include "ChessPieces.h"


//constructor
Pawn::Pawn(piece_colour _colour, map<string,Piece*>* _map_cb_ptr, string _name):Piece(){
  colour = _colour;  
  map_cb_ptr = _map_cb_ptr;
  name = _name;
}
//destructor
Pawn::~Pawn(){
  //cout<<"destroying Pawn"<<endl;
}


/*FUNCTION DEFINITION of overridden function is_valid_move*/
bool Pawn::is_valid_move(string org,string dest){

  switch(colour){
  
  case White: {
    //iterator of type map
    map <string,Piece*>::iterator it;
    it = map_cb_ptr->find(dest);
    //if piece is found at location and it has opposite colour ro player
    if(it != map_cb_ptr->end() && (it->second->get_colour() == opp_colour(colour))){
      //only diagonal moves are allowed
      if(!((abs(dest[0] - org[0]) == 1 && dest[1] - org[1] == 1))){
	return false;
      }
    }
    else{
      /*only straight moves forward are allowed*/
      if(dest[0] - org[0] != 0){
	return false;
      }

      /*can only move one step forward unless at start*/
      if(org[1] == '2'){
        if(dest[1] - org[1] != 1 && dest[1] - org[1] != 2){
          return false;
	}
      }
      else{
	if(dest[1] - org[1] != 1){
	  return false;
	}
      }
    }
  };
    break;
    
  case Black: {
    //iterator of type map
    map <string,Piece*>::iterator it;
    it = map_cb_ptr->find(dest);
    //if piece is found at location and it has opposite colour ro player
    if(it != map_cb_ptr->end() && (it->second->get_colour() == opp_colour(colour))){
      //only diagonal moves are allowed
      if(!(abs(dest[0] - org[0]) == 1 && dest[1] - org[1] == -1)){
        return false;
      }
    }
    else{
      //otherwise, only straight moves are allowed
      if(dest[0] - org[0] != 0){
	return false;
      }

      /*can only move one step forward unless at start*/
      if(org[1] == '7'){
	if(dest[1] - org[1] != -1 && dest[1] - org[1] != -2){
	  return false;
	}
      }
      else{
	if(dest[1] - org[1] != -1){
	  return false;
	}
      }
    }
  };
    break;
  default:
    return true;
  }
  
  //move must be valid
  return true;
};
/****END OF FUNCTION DEFINTITION*****/


/*FUNCTION DEFINITION of overridden function advance*/
string Pawn::advance(string org,string dest){

  //if movement is diagonal, just return dest
  if(dest[0] - org[0] != 0 && dest[1] - org[1] != 0){
    return dest;
  }  

  char column = org[1];
  
  switch(colour){
  case Black: {      
    column--;
    //cout<<(string() + org[0] + column)<<endl;
    return (string() + org[0] + column);
  };
    break;
  case White: {
    column++;
    //cout<<(string() + org[0] + column)<<endl;
    return (string() + org[0] + column);
  };
    break;
  default:
    return dest;
  }
}
/****END OF FUNCTION DEFINTITION*****/

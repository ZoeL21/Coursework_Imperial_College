#include "ChessBoard.h"
#include "ChessPieces.h"
#include "Header.h"

using namespace std;

//constructor
ChessBoard::ChessBoard(){  
  /*assign pointer to map*/
  map_cb_ptr = &map_cb;
  /*call resetBoard function*/
  resetBoard();  
}

//destructor
ChessBoard::~ChessBoard(){  
  map<string,Piece*>::iterator it;
  for(it = map_cb.begin();it != map_cb.end(); it++){
    //free memory of remaining piece
    delete it->second;
  }
  map_cb.clear();

}

/*DEFINITIONS of access functions*/
piece_colour ChessBoard::get_turn(){
  return turn;
}

bool ChessBoard::get_check_state(){
  return check_state;
}

void ChessBoard::set_check_state(bool _check_state){
  check_state = _check_state;
}
/****END OF DEFINITIONS*****/


/*FUNCTION DEFINITION of update_Board*/
void ChessBoard::update_Board(const string org, const string dest){
  
  map<string,Piece*>::iterator it;  
  it = map_cb.find(dest);

  //remove piece of opponent if present at dest
  if(it != map_cb.end() && it->second->get_colour() == opp_colour(turn)){

    //save colour and name of Piece being hit
    piece_colour colour_Piece_hit = it->second->get_colour();
    string name_Piece_hit = it->second->get_name();

    it = map_cb.find(org);
    print_move(org, dest, it);
    
    cout<<" taking "<<output_colour(colour_Piece_hit)<<"'s "<<name_Piece_hit<<endl;

    it = map_cb.find(dest);
    map_cb.erase(it);
  }
  else{
    it = map_cb.find(org);
    print_move(org, dest, it);
    cout<<endl;
  }
  //update position of piece in action  
  change_position(org,dest);
}
/****END OF DEFINITIONS*****/


/*FUNCTION DEFINITION of update_Board_state*/
bool ChessBoard::is_in_check(const piece_colour attacker,const piece_colour attacked){
  /*for 'turn' colour, for every piece, make its destination
    the poition of the King of the opposite colour and see if
    any of the moves are valid, i.e the King can be hit*/
  
  string King_attacked;

  //find the potentially attacked King's position
  map <string,Piece*>::iterator it;

  for(it = map_cb.begin(); it != map_cb.end(); it++){
    if(it->second->get_name() == "King" && it->second->get_colour() == attacked){
      King_attacked = it->first;
      break;
    }
  }
  
  //iterate through each piece of attacker
  for(it = map_cb.begin(); it != map_cb.end(); it++){
    if(it->second->get_colour() == attacker){
      //check if Kings destination would be a valid move
      if(it->second->is_valid_move(it->first,King_attacked)){
	  //check if no pieces would be in the way
	if(!piece_in_the_way(it->first,King_attacked)){
	  //if so then set check_state of board to true;	  
	    check_state = true;
	    return true;
	  }
      }
    }   

  }

  //otherwise, after move, King of own colour won't be in check
  check_state = false;
  return false;
  
}

bool ChessBoard::can_move(const piece_colour opponent){
  /*iterate through every position of the board and
    check if any of them are a valid move for 'turn'.
    Valid move includes the move is allowed for the piece,
    there is no piece in the way, and that move does not
    result in check*/
  
  map <string,Piece*>::iterator it;
  for(it = map_cb.begin(); it != map_cb.end(); it++){
    if(it->second->get_colour() == opponent){
      
      for(char c = 'A'; c < 'I'; c++){
	for(char c2 = '1'; c2 < '9'; c2++){
	  //concatenate to string
	  string position = string() + c + c2;
	  
	  if(position == it->first){
	    continue;
	  }
	  //check if piece can move
	  if(it->second->is_valid_move(it->first,position)){
	    if(!(is_dest_occ_byOwn(position,opponent))){
	     
		if(!(piece_in_the_way(it->first,position))){
		 
		  if(!move_results_in_check(it->first,position,opponent)){		    
		    return true;
		  }
		}
	    }
	  }
	}
      }
    }
  }

  /*if after checking if every position on the board is a valid 
    move for each piece of 'turn' and none has returned true,
    no move can be made*/
  return false;
}
/*****END OF FUNCTION DECLARATION*****/


/*FUNCTION DECLARATION of is_dest_occ_byOwn*/
bool ChessBoard::is_dest_occ_byOwn(const string dest, const piece_colour Own){
  map <string,Piece*>::iterator it;
  it = map_cb.find(dest);
  if(it != map_cb.end() && it->second->get_colour() == Own){
    
    return true;
  }
  //otherwise
  return false;
}
/****END OF FUNCTION DEFINTITION*****/

/*FUNCTION DEFINITION of move_results_in_check*/
bool ChessBoard::move_results_in_check(const string org,const string dest,const piece_colour attacked){
 
 //temporarily remove any piece that is at dest 
  Piece* Piece_at_dest = NULL;
  map <string,Piece*>::iterator it;
  it = map_cb.find(dest);
  if(it != map_cb.end()){
    Piece_at_dest = it->second;  
    map_cb.erase(it);   
  } 
  
  //temporarily replace position of piece
  change_position(org,dest);  


  if(is_in_check(opp_colour(attacked),attacked)){
    
    //reset the position of piece in action
    change_position(dest,org);
    //place previous piece back
    if(Piece_at_dest != NULL){
      map_cb[dest] = Piece_at_dest;
    }   
    //reset the check state
    check_state = false;
    return true;
  }

  //undo changes made

  //reset position of piece in action
  change_position(dest,org);
  //place previous piece back
  if(Piece_at_dest != NULL){
    map_cb[dest] = Piece_at_dest;
  }
  
  //undo changes made
  
  //reset check_state of board
  check_state = false;  
  return false;
}
/****END OF FUNCTION DEFINTITION*****/


/*FUNCTION DEFINITION of submitMove*/
bool ChessBoard::submitMove(const string org,const string dest){
 

  //check length of input
  if(org.length() != 2 || dest.length() != 2){
    cerr<<"invalid input of chessboard positions"<<endl;
    return false;
  }

  
  /*check if destination is out of bounds of
    the chessboard*/
  if(is_outof_bounds(dest)){
    cerr<<"Input: "<<dest<<"Is out of bounds!"<<endl;
    return false;
  }


  //check if org and dest are the same
  if(dest == org){
    return false;
    
  }  

  //check if there is a piece at the org position
  map <string,Piece*>::iterator it;  
  it = map_cb.find(org);

  if(it == map_cb.end()){
    cerr<<"There is no piece at position "<<org<<"!"<<endl;
      return false;
    }
 
  //check if piece doesn't correspond to turn
  if(it->second->get_colour() != turn){
    cout<<"It is not "<<output_colour(it->second->get_colour());
    cout<<"'s turn to move"<<endl;
      return false;
  }
  
 
 
  if(!(it->second->is_valid_move(org,dest))){    
    print_invalid_move(dest,it);
    return false;
  }

  it = map_cb.find(org);

  
  //checks for pieces in the way of the move
  if(piece_in_the_way(org,dest)){
    cerr<<"There is a piece in the way of this move"<<endl;
    print_invalid_move(dest,it);
    return false;
  }      

  it = map_cb.find(org);

  
  /*checks if there is a piece of own colour at the
    destination*/
  if(is_dest_occ_byOwn(dest,turn)){
    cerr<<"Position: "<<dest<<" is occupied by a piece of own colour"<<endl;
    print_invalid_move(dest,it);
    return false;
  }
  

  /*checks if the movement of the Piece would result in
    player of colour 'turn' being in check*/
  if(move_results_in_check(org,dest,turn)){
    print_invalid_move(dest,it);
    return false;
    }
  
  it = map_cb.find(org);

  /*if piece of other colour is in the way, remove it 
    from the map and change the position of piece in action*/
  update_Board(org,dest);  

  it = map_cb.find(org);
  
  //check if opponent is in Check
  if(is_in_check(turn,opp_colour(turn))){
    //check if opponent is in check_mate
    if(!can_move(opp_colour(turn))){
	cout<<output_colour(opp_colour(turn))<<" is in checkmate"<<endl;
      }
    else{
      cout<<output_colour(opp_colour(turn))<<" is in check"<<endl;
    }
  }
  else{
  //check if opponent is in stale-mate 
  if(!can_move(opp_colour(turn))){
	cout<<output_colour(opp_colour(turn))<<" is in stalemate"<<endl;
      }
  }
  

  //change turn  
  if(turn){    
    turn = Black;    
  }
  else{
    turn = White;    
  }

  return true;
}

//function which resets the board
void ChessBoard::resetBoard(){
 
  //clear existing map
  map_cb.clear();

  /*initialize the map with pieces at
    starting positions. The necessary
    pieces are created on the heap*/
 
  //The White pieces
  map_cb["A1"] = new Rook(White,"Rook");
  map_cb["B1"] = new Knight(White, "Knight");
  map_cb["C1"] = new Bishop(White, "Bishop");
  map_cb["D1"] = new Queen(White, "Queen");
  map_cb["E1"] = new King(White, "King");
  map_cb["F1"] = new Bishop(White,"Bishop");
  map_cb["G1"] = new Knight(White, "Knight");
  map_cb["H1"] = new Rook(White,"Rook");
  for(char c = 'A';c < 'I'; c++){
    
    string pos = string() + c + '2';
    map_cb[pos] = new Pawn(White,this->map_cb_ptr, "Pawn");
  }
  //The Black pieces
  map_cb["A8"] = new Rook(Black,"Rook");
  map_cb["B8"] = new Knight(Black,"Knight");
  map_cb["C8"] = new Bishop(Black, "Bishop");
  map_cb["D8"] = new Queen(Black,"Queen");
  map_cb["E8"] = new King(Black,"King");
  map_cb["F8"] = new Bishop(Black,"Bishop");
  map_cb["G8"] = new Knight(Black,"Knight");
  map_cb["H8"] = new Rook(Black,"Rook");
  for(char c = 'A';c < 'I'; c++){
    string pos = string() + c + '7';
    map_cb[pos] = new Pawn(Black,this->map_cb_ptr, "Pawn");
  }

  //set turn to White
  turn = White;
  //no one is in check
  check_state = false;

  cout<<"A new chess game is started!"<<endl;  
}
/*****END OF FUNCTION DEFINITION*****/


/*FUNCTION DEFINITION of is_outof_bounds*/
bool ChessBoard::is_outof_bounds(string dest){
  if(dest[0] < 'A' || dest[0] > 'H'){
    return true;
  }
  if(dest[1] < '1' || dest[1] > '8'){
    return true;
  }
  //if position is not out of bounds
  return false;
}
/*****END OF FUNCTION DEFINITION*****/

/*FUNCTION DEFINITION of piece_in_the_way*/
bool ChessBoard::piece_in_the_way(const string org,const string dest){
  
map <string,Piece*>::iterator it;
  it = map_cb.find(org);
  
  string adv_position = it->first;
  
  //advance while not reaching dest
  while(true){
    
    adv_position = it->second->advance(adv_position,dest);
    if(adv_position == dest){
      break;
    }
    
    if(map_cb.find(adv_position) != map_cb.end()){
      
      return true;
    }
  }
 
  return false;
}

void ChessBoard::print_move(const string org,const string dest,map <string,Piece*>::iterator it){
  cout<<output_colour(turn)<<"'s "<<it->second->get_name();
  cout<<" moves from "<<org<<" to "<<dest;
}

void ChessBoard::print_invalid_move(const string dest,map <string,Piece*>::iterator it){
  cerr<<output_colour(it->second->get_colour());
  cerr<<"'s "<<it->second->get_name();
  cerr<<" cannot move to "<<dest<<endl;
}


void ChessBoard::change_position(const string org,const string dest){
  map<string,Piece*>::iterator it;
  it = map_cb.find(org);
  if(it == map_cb.end()){
    cout<<"COULD NOT FIND ORG"<<endl;
  }
  Piece* temp = it->second;
  map_cb.erase(it);
  map_cb[dest] = temp;
}


void ChessBoard::output_map(){

  map <string,Piece*>::iterator it;
  for(it = map_cb.begin(); it != map_cb.end(); it++){
    cout<<it->first<<":  "<<it->second->get_name()<<" "<<output_colour(it->second->get_colour())<<endl;
  }

}

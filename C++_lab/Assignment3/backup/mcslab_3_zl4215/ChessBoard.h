#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <iostream>
#include <map>
#include <cstring>
#include <cmath>
#include <string>

//forward declaration
class Piece;

using namespace std;

//enum for the colour of the Chesspieces
enum piece_colour{Black, White};

/*declaring a class Chessboard*/ 

class ChessBoard{
  
  piece_colour turn;
  bool check_state;  
  /*map whose key is the position 
    on the chessboard (a string) and whose value is 
    a Piece*/
  map <string,Piece*> map_cb;
  /*pointer to that map*/
  map <string,Piece*>* map_cb_ptr;
  
  /*helper functions*/

  /*function which changes the position of a piece at
    position org, to position dest*/
  void change_position(string org,string dest);
  /*function which checks if moving from org to dest
    results in player 'attacked' to be in chess*/  
  bool move_results_in_check(string org,string dest, piece_colour attacked);
  /*function which checks if player 'attacked' is in check, i.e
    threatened by player 'attacker'*/
  bool is_in_check(piece_colour attacker,piece_colour attacked);
  /*function that checks if any move can be made by whoever's turn
    it is*/
  bool can_move(piece_colour opponent);
  /*function which checks if the field a piece wants to
    move to is occupied by a piece of the own colour*/
  bool is_dest_occ_byOwn(string dest, piece_colour Own);
  /*function which checks is a piece is in the way of
    the movement of piece in action*/
  bool piece_in_the_way(string org,string dest);
  /*function to check if a position is out of bounds*/
  bool is_outof_bounds(string dest);
  /*function to update the board with new position of a piece
    as well as removing any piece of opponent if it is hit*/
  void update_Board(string org, string dest); 
  /*function which prints informative output about a move made*/
  void print_move(string org,string dest, map <string,Piece*>::iterator it);
  /*function which prints informative output after invalid move*/
  void print_invalid_move(string dest,map <string,Piece*>::iterator it);

  public:
 
  //constructor
  ChessBoard(); 
 
  //access functions
  piece_colour get_turn();
  bool get_check_state();
  void set_check_state(bool _check_state); 

  //other functions

  /*function that accepts input to move
    a piece from org (origin) to dest (destination*/
  bool submitMove(string org,string dest);  

  /*function which resets the Board, so that 
    another game can start*/
  void resetBoard();
  
  /*function which outputs the contents of the map*/
  void output_map();

  //destructor
  ~ChessBoard();
};



#endif

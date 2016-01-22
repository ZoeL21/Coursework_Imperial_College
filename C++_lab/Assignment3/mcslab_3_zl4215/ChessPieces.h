#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <iostream>
#include <map>
#include <cstring>
#include <cmath>
#include <string>

#include "ChessBoard.h"
#include "Header.h"
/*declaring an abstract superclass for chess pieces*/

class Piece{
 protected:
  string name;
  piece_colour colour;
    
 public:
  //constructor
  Piece(); 
  //access functions
  piece_colour get_colour();
  string get_name();

  //pure virtual function
  virtual bool is_valid_move(string org,string dest) = 0;
  //pure virtual function
  virtual string advance(string org,string dest) = 0;  
  //destructor
  virtual ~Piece();
};

/*declaring the derived classes of the different chess pieces*/

class King:public Piece{  
 public:
  //constructor
  King(piece_colour _colour, string _name);
  
  //other functions
  virtual bool is_valid_move(string org,string dest);

  /*overridden function which advances piece at org
    one step towards dest*/  
  virtual string advance(const string org,const string dest);
  
  //destructor
  ~King();
};

class Queen:public Piece{ 
  
 public:
  //constructor
  Queen(piece_colour _colour, string _name);
  
  //other functions
  virtual bool is_valid_move(string org,string dest);  

  /*overridden function which advances piece at org
    one step towards dest*/  
  virtual string advance(string org,string dest);

  //destructor  
  ~Queen();
};

class Rook:public Piece{ 

public:  
  //constructor
  Rook(piece_colour _colour, string _name);
  
  //other functions
  virtual bool is_valid_move(string org,string dest);

  /*overridden function which advances piece at org
    one step towards dest*/  
  virtual string advance(string org,string dest);
 
  
  ~Rook();
};

class Bishop:public Piece{ 
 
 public:
  //constructor
  Bishop(piece_colour _colour, string _name);
  
  //other functions
  virtual bool is_valid_move(string org,string dest);

 /*overridden function which advances piece at org
    one step towards dest*/  
  virtual string advance(string org,string dest);

  //destructor
  ~Bishop();
};

class Knight:public Piece{  
  
 public:
  //constructor
  Knight(piece_colour _colour, string _name);
  
  //other functions
  virtual bool is_valid_move(string org,string dest);

  /*overridden function which advances piece at org
    one step towards dest*/  
  virtual string advance(const string org,const string dest);  
  
  //destructor
  ~Knight();
};

class Pawn:public Piece{ 
  /*pointer to the map holding all the Chesspieces*/
  map <string,Piece*>* map_cb_ptr;
  
 public:
  //constructor
  Pawn(piece_colour _colour, map<string,Piece*>* _map_cb_ptr, string _name);
  
  //other functions
  virtual bool is_valid_move(string org,string dest);

  /*overridden function which advances piece at org
    one step towards dest*/  
  virtual string advance(string org,string dest);
  
  //destructor
  ~Pawn();
};



#endif

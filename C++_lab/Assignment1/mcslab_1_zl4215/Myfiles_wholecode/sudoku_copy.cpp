#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include "sudoku.h"

using namespace std;

//global variables to count the 
int solve_count = 0;
int make_move_count = 0;

/* You are pre-supplied with the functions below. Add your own 
   function definitions to the end of this file. */

/* pre-supplied function to load a Sudoku board from a file */
void load_board(const char *filename, char board[9][9]) {

  cout << "Loading Sudoku board from file '" << filename << "'... ";

  ifstream in(filename);
  if (!in)
    cout << "Failed!" << endl;
  assert(in);

  char buffer[512];

  cout<<endl;

  int row = 0;
  in.getline(buffer,512);
  while (in && row < 9) {
    for (int n=0; n<9; n++) {
      assert(buffer[n] == '.' || isdigit(buffer[n]));
      board[row][n] = buffer[n];
    }
    row++;
    in.getline(buffer,512);
  }

  cout << ((row == 9) ? "Success!" : "Failed!") << endl;
  assert(row == 9);
}

/* internal helper function */
void print_frame(int row) {
  if (!(row % 3))
    cout << "  +===========+===========+===========+" << endl;
  else
    cout << "  +---+---+---+---+---+---+---+---+---+" << endl;
}

/* internal helper function */
void print_row(const char *data, int row) {
  cout << (char) ('A' + row) << " ";
  for (int i=0; i<9; i++) {
    cout << ( (i % 3) ? ':' : '|' ) << " ";
    cout << ( (data[i]=='.') ? ' ' : data[i]) << " ";
  }
  cout << "|" << endl;
}

/* pre-supplied function to display a Sudoku board */
void display_board(const char board[9][9]) {
  cout << "    ";
  for (int r=0; r<9; r++) 
    cout << (char) ('1'+r) << "   ";
  cout << endl;
  for (int r=0; r<9; r++) {
    print_frame(r);
    print_row(board[r],r);
  }
  print_frame(9);
}

/* add your functions here */


/*FUNCTION DEFINITION OF 'is_complete'*/
bool is_complete(const char board[][9])
{
  for(int i = 0; i < 9; i++)
    for(int j = 0; j < 9; j++)
      {
	if(!isdigit(board[i][j]))
	  {
	    return false;
	  }
      }
  return true;
}
/*END OF FUNCTION DEFINITION*/


/*FUNCTION DEFINITION OF 'subpart'*/
bool subpart(int row, int col, char digit, char board[][9])
{
  int rowsub = row - (row % 3);
  int colsub = col - (col % 3);
  
  for(int i = rowsub; i < (rowsub + 3); i++)
    for(int j = colsub; j < (colsub + 3); j++)
      {
	if(board[i][j] == digit)
	  {
	    return false;
	  }
      }
  return true;
}
/*END OF FUNCTION DEFINITION*/


/*FUNCTION DEFINITION OF 'make_move_count_increase'*/
void make_move_count_increase()
{
  make_move_count++;
}
/*END OF FUNCTION DEFINITION*/


/*FUNCTION DEFINITION OF 'solve_board_count_increase'*/
void solve_board_count_increase()
{
  solve_count++;
}
/*END OF FUNCTION DEFINITION*/


/*FUNCTION DEFINITION OF 'make_move*/
bool make_move(const char* position, char digit, char board[][9])
{
  //make_move_count_increase();
  make_move_count_increase();

  //save number of row;
  int row = *position - 65;
  int col = *(++position) - 49;

  //resetting pointer to array passed to original position in memory
  position--;

  //making sure that the string passed in is not longer than 2 characters
   if(strlen(position) != 2)
    {
      cout<<"your position does not have the correct format"<<endl;
      return false;
    }

  //check if position is out of range
  if(*position > 'I' || *position < 'A')
    {
      return false;
    } 
  if(*(++position) > '9' || *(position) < '1')
    {
      return false;
    }
  if(digit < 49 || digit > 57)
    {
      return false;
    }

  //check if cell is already occupied
  if(isdigit(board[row][col]))
    {
      return false;
    }

  //check if number placed already exists in row
  for(int j = 0; j < 9; j++)
    {      
      if((board[row][j]) == digit)
	{
	  return false;
	}  
    }  
  //check if number placed already exists in column
  for(int i = 0; i < 9; i++)
    {
      if(board[i][col] == digit)
	{
	  return false;
	}
    }

  //check if number placed already exists in subpart
  if(!(subpart(row,col,digit,board)))
    {
      return false;
    }

   //move must be correct, update matrix and return true
   board[row][col] = digit;
   return true;
 }
/*END OF FUNCTION DEFINITION*/


/*FUNCTION DEFINITION OF 'save_board'*/
bool save_board(const char* filename,char board[][9])
{
  ofstream out_stream;

  //open output file
   out_stream.open(filename);
   if(out_stream.fail())
    {
      cout<<"fail"<<endl;
      return false;
    }
    
    //read into file
    for(int i = 0; i < 9; i++)
      {
      for(int j = 0; j < 9; j++)
	{
	  //check if reading into outstream is working. Makes sure that calling either out_stream.fail()
	  //or out_stream.bad() would not return true in this case. It checks for good writing operation
	  //and for format errors.
          if(!out_stream.good())
           {
             cout<<"fail"<<endl;
             return false;
           }
	  //CHECK WITH fIDELIS
	  if(board[i][j] == '.' || isdigit(board[i][j]))
	  out_stream.put(board[i][j]);
	  else
	    {
	      cout<<"data not as expected (digit or dot)"<<endl;
	      return false;
	    }	     
	}
        //add newline to keep format of file
	out_stream.put('\n');
      }

    //if tests are passed, board must have been saved correctly, so return true
    return true;    
}
/*END OF FUNCTION DEFINITION*/



/*FUNCTION DEFINITION OF 'solve_board'*/
bool solve_board(char board[][9])
{
  //call function which increases the global variable solve_count
  solve_board_count_increase();
 
  //iterate through every cell in the sudoku board
  for(int i = 0; i < 9; i++)
    {
    for(int j = 0; j < 9; j++)
      {
	//BASE CASE: if the board is complete and we have reached the last row and column, return true
	if(is_complete(board) && i == 8 && j == 8)
	  {
	    cout<<"reached end"<<endl;
	    return true;
	  }

	//check if is empty
	if(!isdigit(board[i][j]))
	  {

	    //change row and int into a string	   
	    char letter = i + 65;
	    char number = j + 49;	    
	    char position[3]; position[0] = letter; position[1] = number;
	    position[2] = '\0';
              
	    //for 1 through to 9 try all numbers in this index
	    for(char k = 49; k < 59; k++)
	      {
		//for the first move allowed, 
		if(make_move(position, k, board))
		  {
		    //BASE CASE:            
                    /*if last element has been reached and a move can be made, then return true
		      without calling function 'solve_board'*/
		    if(i == 8 && j == 8)
		      {
			cout<<"reached end"<<endl;
			return true;
		      }
		    //play the move and check the rest of the board
		    if(solve_board(board))
		      {
			//if solve_board returns true, then break out of loop by returning
			return true;
		      }
		    else
		      {
			//reset cell to dot to try next number
			board[i][j] = '.';
		      }
		    }
	      }
	    //if none of these number worked, we want to return to previous instance of function 
	    //to try next number

	    //reset number set by make_move to dot.
	    board[i][j] = '.';
	    //display_board(board);	   
	    return false; 
	  }
      }
    }
  //if traversed whole board and checked all possible solutions and no true was returned,  
  return false;
}
/*END OF FUNCTION DEFINITION*/
            

/* function to display information about the solving process*/
void display_info(struct info info_board)
{
  cout<<" |========================================================================================| "<<endl; 
  cout<<" |";
  cout.width(22); 
  cout<<left<<"board name:";   
  cout<<" | easy       |  medium    | mystery1   | mystery2   | mystery3   |"<<endl;
  cout<<" |";
  cout.width(22);
  cout<<left<<"initial digits:";
  cout<<" | ";
  for(int i = 0; i < 5; i++)
    {  cout.width(10);
       cout<<left<<info_board.count_numbers[i]<<" | ";
    }
  cout<<endl;
  cout<<" |";
  cout.width(22);
  cout<<left<<"solving time:";
  cout<<" | ";
  for(int i = 0; i < 5; i++)
    {  cout.width(10);
      cout<<left<<info_board.time[i]<<" | ";
    }
  cout<<endl;
  cout<<" | ";
  cout.width(22);
  cout<<left<<"solve_count:";
  for(int i = 0; i < 5; i++)
    {
      cout<<" | ";
      cout.width(10);
      cout<<info_board.solve_count[i];
    }
  cout<<" |"<<endl;
  cout<<" |";
  cout.width(22);
  cout<<"make_move_count:";
  for(int i = 0; i < 5; i++)
    {
      cout<<" | ";
      cout.width(10);
      cout<<info_board.make_move_count[i];
    }
  cout<<" | "<<endl;
  cout<<" |========================================================================================| "<<endl;
  
}

/*FUNCTION DEFINITION OF 'reset_counts'*/
void reset_counts()
{
  make_move_count = 0;
  solve_count = 0;
}
/*END OF FUNCTION DEFINITION*/


/*FUNCTION DEFINITIONS OF 'get_solve_count' and 'get_make_move_count'*/
int get_solve_count()
{
  return solve_count;
}

int get_make_move_count()
{
  return make_move_count;
}
/*END OF FUNCTION DEFINITIONS*/



/*FUNCTION DEFINITION OF 'count_numbers'*/
int count_numbers(char board[][9])
{
  int numbers_count = 0;
  for(int i = 0; i < 9; i++)
    for(int j = 0; j < 9; j++)
      {
	if(isdigit(board[i][j]))
	  {
	    numbers_count++;
	  }
      }
  cout<<endl;
  return numbers_count;
}
/*END OF FUNCTION DEFINITION*/



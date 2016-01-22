#ifndef SUDOKU_H
#define SUDOKU_H

/*declaring a struct to store the initial digit number and the amount of function 
  calls to make_move and solve_board needed to solve the board*/
  struct info{  
  int count_numbers;
  int make_move_count;
  int solve_count;
  };

/*presupplied functions to load the sudoku board from memory and display it on 
 the screen*/
void load_board(const char *filename, char board[9][9]);
void display_board(const char board[9][9]);

/*function to check if board is complete or not. Returns true only if
  board is complete, false otherwise*/
bool is_complete(const char board[][9]);

/*function to check if a number is already present inside the
 corresponding subpart of the sudoku board*/
bool subpart(const int row,const int col,const char digit,const char board[][9]);

/*function to check if a given move is allowed, make a move if allowed
 and update the sudoku board to hold that move*/
bool make_move(const char* position, const char digit, char board[][9]);

/*function to save the board. Returns true only if board was
  successfully saved, otherwise false*/
bool save_board(const char* filename, const char board[][9]);

/*function which calls helper_solve_board and outputs information 
  about the initial digits and the solving processes of board*/
bool solve_board(char board[][9]);

/*helper function inside solve_board to solve the board. This function
  uses recursive backtracking to solve a 9 by 9 sudoku board. It
  takes two additional references to integer variables used to count
  the times the functions helper_solve_board and make_move are called*/
bool helper_solve_board(char board[][9], int& solve_count, int& make_move_count);

/*function to count the numbers inside a board*/
int count_numbers(const char board[][9]);

/*function to display the info about various features of the given
sudoku boards, including their initial digits*/
void display_info(const struct info info_board);


#endif

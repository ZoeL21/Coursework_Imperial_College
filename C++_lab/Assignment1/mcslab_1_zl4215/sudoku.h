#ifndef SUDOKU_H
#define SUDOKU_H

/*declaring a struct to store the time information of the mystery-boards*/
struct info{
  int time_easy;
  int time_medium;
  int time_mystery1;
  int time_mystery2;
  int time_mystery3;
  int count_numbers[5];
  int make_move_count[5];
  int solve_count[5];
};



void load_board(const char *filename, char board[9][9]);
void display_board(const char board[9][9]);


/*function to check if board is full or not*/
bool is_complete(const char board[][9]);

/*function to check subpart of sudoku board*/
bool subpart(int row, int col, char digit, char board[][9]);

/*function to increase the count of the call of the function make_move*/
void make_move_count_increase();

/*function to increase the count of the recursive calls of the function solve_board*/
void solve_board_count_increase();

/*function to make a move and alter sudoku board*/
bool make_move(const char* position, char digit, char board[][9]);

/*function to save the board*/
bool save_board(const char* filename,char board[][9]);

/*function to solve the board. This function uses recursive backtracking to solve a 9 by 9 sudoku board*/
bool solve_board(char board[][9]);

/*functions to return the global variables solve_count and make_move_count used to measure the calls of the functions 'solve_board' and 'make_move'*/
int get_make_move_count();
int get_solve_count();
/*****/

/*function to reset the counts*/
void reset_counts();
/*****/

/*function to count the numbers inside board*/
int count_numbers(char board[][9]);
/******/

void display_info(struct info info_board);


#endif


#include <iostream>
#include <cstdio>
#include <ctime>
#include <chrono>
#include "sudoku.h"

using namespace std;


int main() {

  char board[9][9];  

  /* This section illustrates the use of the pre-supplied helper functions. */
  cout << "============== Pre-supplied functions ==================" << endl << endl;

  cout << "Calling load_board():" << endl;
  load_board("easy.dat", board);

  cout << endl << "Displaying Sudoku board with display_board():" << endl;
  display_board(board);
  cout << "Done!" << endl << endl;

  
  cout << "====================== Question 1 ======================" << endl << endl;

  load_board("easy.dat", board);
  cout << "Board is ";
  if (!is_complete(board))
    cout << "NOT ";
  cout << "complete." << endl << endl;

  load_board("easy-solution.dat", board);
  cout << "Board is ";
  if (!is_complete(board))
    cout << "NOT ";
  cout << "complete." << endl << endl;
 
 
  cout << "====================== Question 2 ======================" << endl << endl;

  load_board("easy.dat", board);

  // Should be OK
  cout << "Putting '3' into B5 is ";
  if (!make_move("B5", '3', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << endl;
  display_board(board);

	// write more tests
  
  cout << "====================== Question 3 ======================" << endl << endl;

  load_board("easy.dat", board);
  if (save_board("easy-copy.dat", board))
    cout << "Save board to 'easy-copy.dat' successful." << endl;
  else
    cout << "Save board failed." << endl;
  cout << endl;

  
  cout << "====================== Question 4 ======================" << endl << endl;

  load_board("easy.dat", board); 
  /*setting stating point of time measurement*/
  chrono::steady_clock::time_point start = chrono::steady_clock::now();
  /*****************/
  if (solve_board(board)) {
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    /*end of timing*/   
    cout << "The 'easy' board has a solution:" << endl;
    display_board(board);    
    int time_taken = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout<<"TIME TO SOLVE: "<<time_taken<<endl;
  } else 
    cout << "A solution cannot be found." << endl;
  cout << endl;

  load_board("medium.dat", board);
  
  /*start timig the solution*/
  chrono::steady_clock::time_point start2 = chrono::steady_clock::now();
  if (solve_board(board)) {
    chrono::steady_clock::time_point end2 = chrono::steady_clock::now();
    /*end of timing*/   
    cout << "The 'medium' board has a solution:" << endl;
    display_board(board);
    int time_taken = chrono::duration_cast<chrono::microseconds>(end2 - start2).count();
    cout<<"TIME TO SOLVE: "<<time_taken<<endl;
  } else 
    cout << "A solution cannot be found." << endl;
  cout << endl; 

	// write more tests

  cout << "====================== Question 5 ======================" << endl << endl;

    
  load_board("mystery1.dat", board);  
  /*start timing the solution*/
  chrono::steady_clock::time_point start3 = chrono::steady_clock::now();
  if (solve_board(board)) {
    chrono::steady_clock::time_point end3 = chrono::steady_clock::now();
    /*end of timing*/
    int time_taken = chrono::duration_cast<chrono::microseconds>(end3 - start3).count();    
    cout << "The 'mystery1' board has a solution:" << endl;    
    display_board(board);
    cout<<"TIME TO SOLVE: "<<time_taken<<endl;
  }else
    cout << "A solution cannot be found." << endl;
    cout << endl;    
    
    load_board("mystery2.dat", board);   
    /*start timing the solution*/
    chrono::steady_clock::time_point start4 = chrono::steady_clock::now();
     if (solve_board(board)) {
     chrono::steady_clock::time_point end4 = chrono::steady_clock::now();
      /*end of timing*/      
      int time_taken = chrono::duration_cast<chrono::microseconds>(end4 - start4).count();      
      cout << "The 'mystery2' board has a solution:" << endl;
      display_board(board); 
      cout<<"TIME TO SOLVE: "<<time_taken<<endl;
    }else
       {
         cout << "A solution cannot be found." << endl;
         cout << endl;         
       }
      
     
       load_board("mystery3.dat", board);       
       /*start timing the solution*/
       chrono::steady_clock::time_point start5 = chrono::steady_clock::now();
       if (solve_board(board)) {
       chrono::steady_clock::time_point end5 = chrono::steady_clock::now();
       /*end of timing*/       
       int time_taken = chrono::duration_cast<chrono::microseconds>(end5 - start5).count();      
       /***********/
       cout << "The 'mystery3' board has a solution:" << endl;
       display_board(board);
       cout<<"TIME TO SOLVE: "<<time_taken<<endl;
      }else
      cout << "A solution cannot be found." << endl;
      cout << endl;      
     
  return 0;
}

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <string>

using namespace std;

#include"maze.h"

/* You are pre-supplied with the functions below. Add your own 
   function definitions to the end of this file. */

/* helper function which allocates a dynamic 2D array */
char **allocate_2D_array(int rows, int columns) {
  char **m = new char *[rows];
  assert(m);
  for (int r=0; r<rows; r++) {
    m[r] = new char[columns];
    assert(m[r]);
  }
  return m;
}

/* helper function which deallocates a dynamic 2D array */
void deallocate_2D_array(char **m, int rows) {
  for (int r=0; r<rows; r++)
    delete [] m[r];
  delete [] m;
}

/* helper function for internal use only which gets the dimensions of a maze */
bool get_maze_dimensions(const char *filename, int &height, int &width) {
  char line[512];
  
  // ifstream input(filename);
  ifstream input;
  input.open(filename);

  if (input.fail()) {
    cerr << "couldn't open file" << endl;
    return false;
  }

  height = width = 0;

  input.getline(line,512);  

  cerr << "succeeded in extracting data from file" << endl;

  while (input) {
    if ( (int) strlen(line) > width)
      width = strlen(line);
    height++;
    input.getline(line,512);  
  }

  cerr << "dimensions: " << height << ", " << width << endl;

  if (height > 0) {
    cerr << "(get_maze_dimensions) all good, about to return true" << endl;
    return true;
  }
  return false;
}

/* pre-supplied function to load a maze from a file*/
char **load_maze(const char *filename, int &height, int &width) {

  cerr << "starting load maze" << endl;

  bool success = get_maze_dimensions(filename, height, width);

  cerr << "dimensions of this maze: " << height << ", " << width << endl;
  
  if (!success) {
    cerr << "couldn't get hold of this maze's dimensions!" << endl;
    return NULL;
  }

  char **m = allocate_2D_array(height, width);
  
  ifstream input(filename);

  char line[512];

  for (int r = 0; r<height; r++) {
    input.getline(line, 512);
    strcpy(m[r], line);
  }

  input.close();  

  return m;
}

/* pre-supplied function to print a maze */
void print_maze(char **m, int height, int width) {
  cout << setw(4) << " " << " ";
  for (int c=0; c<width; c++)
    if (c && (c % 10) == 0) 
      cout << c/10;
    else
      cout << " ";
  cout << endl;

  cout << setw(4) << " " << " ";
  for (int c=0; c<width; c++)
    cout << (c % 10);
  cout << endl;

  for (int r=0; r<height; r++) {
    cout << setw(4) << r << " ";    
    for (int c=0; c<width; c++) 
      cout << m[r][c];
    cout << endl;
  }
}



bool find_marker(char ch, char** maze, int height, int width, int& row, int& column){

  //traverse maze until char is found

  for(int i = 0; i < height; i++){
    for(int j = 0; j < width;j++){

      if(maze[i][j] == ch){
	//set row and column correspondinly
	row = i; column = j;
	return true;
      }
    }
  }

  //if char hasn't been found, set row and col to -1
  row = -1, column = -1;
  return false;
}


bool valid_solution(const char* path, char** maze, int height, int width){  
  

    //find the entrance
    int row_entr = 0;
    int col_entr = 0;
    if(!find_marker('>',maze,height,width,row_entr,col_entr)){
      cout<<"no entrance"<<endl;
      return false;
    }

    cout<<"Entrance is at: row "<<row_entr<<" and col "<<col_entr<<endl;
    
    int row_current = row_entr;
    int col_current = col_entr;

    int i = 0;
    //from entrance onwards, parse path
    for(; path[i] != '\0'; i++){

      //read direction
      if(path[i] == 'N'){
	row_current -= 1;
      }
      else if(path[i] == 'S'){
	row_current += 1;
      }
      else if(path[i] == 'E'){
	col_current += 1;
      }
      else if(path[i] == 'W'){
	col_current -= 1;
      }
      else{
	cout<<"this is not a direction"<<endl;
      }

      //move direction if possible
      if(maze[row_current][col_current] == '|'){
	cout<<"found hedge"<<endl;
	return false;
      }

      if(maze[row_current][col_current] == '+'){
	cout<<"found limit"<<endl;
	return false;
      }

      if(maze[row_current][col_current] == '-'){
	cout<<"found limit"<<endl;
	return false;
      }

      //otherwise just continue
    }

    //check if I am at the exit now
    if(maze[row_current][col_current] != 'X'){
      cout<<"not at the exit"<<endl;
      return false;
    }

    //otherwise, path must be ok
    return true;

}

	

const char* find_path(char** maze,int height,int width,char start, char end){

  //find start character
  int row_start = 0;
  int col_start = 0;

  if(!find_marker(start,maze,height,width,row_start,col_start)){
    cout<<"strating marker not found"<<endl;
  }
  
  char path_so_far[5000];
  path_so_far[0] = '\0';

  //call recursive helper function traversing the maze
  return find_path_rec(maze,height,width,row_start,col_start,end, path_so_far);

}


const char* find_path_rec(char** maze,int height, int width,int row_current,int col_current,char end, char* path_so_far){

  string sol1 = string();
  const char* solution = sol1.c_str();
  //char* solution = new char[500];
  //solution [0] = '\0';


  //base case: X is reached
  if(maze[row_current][col_current] == end){
    cout<<"Found char "<<end<<" and "<<row_current<<" "<<col_current<<endl;
    return path_so_far;
  }

  //check if all paths have been tried
  if(maze_full(maze,height,width)){
    cout<<"all paths have been tried"<<endl;
     string sol = "solution";
     const char* result = sol.c_str();
     return result;
      }


  int rownew = row_current + 1;      
  //try moving south
  cout<<maze[rownew][col_current]<<endl;

  if(can_move(maze,rownew,col_current,end)){
    if(maze[rownew][col_current] == end){
      cout<<"Found char "<<end<<" and "<<row_current<<" "<<col_current<<endl;
      return path_so_far;
    }
    cout<<"moving south"<<endl;
    char move[2];
    move[0] = 'S';
    move[1] = '\0';
    strcat(path_so_far,move);
    //place # char at position
    maze[rownew][col_current] = '#';
    //call find_path
    solution = find_path_rec(maze,height,width,rownew,col_current,end,path_so_far);
    cout<<"solution is: "<<solution<<endl;
    if(strcmp(solution, "no solution") != 0){
      return path_so_far;
    }
    //remove char concatenated
    remove_last(path_so_far);
  }

  //solution [0] = '\0';

  //try moving east
  int colnew = col_current + 1;
  if(can_move(maze,row_current,colnew,end)){
    if(maze[row_current][colnew] == end){
      cout<<"Found char "<<end<<" and "<<row_current<<" "<<col_current<<endl;
      return path_so_far;
    }
    cout<<"moving east"<<endl;
    //add 'E' to path_so_far
    char move[2];
    move[0] = 'E';
    move[1] = '\0';
    strcat(path_so_far,move);
    //place # char at position
    maze[row_current][colnew] = '#';
    //call find_path
    solution = find_path_rec(maze,height,width,row_current,colnew,end,path_so_far);    
    cout<<"solution is: "<<solution<<endl;
     if(strcmp(solution, "no solution") != 0){
       return path_so_far;
     }
     //remove char concatenated
    remove_last(path_so_far);
  }


  //solution [0] = '\0';


 	  
  //try moving west
  colnew = col_current - 1;
  if(can_move(maze, row_current, colnew,end )){
    if(maze[row_current][colnew] == end){
      cout<<"Found char "<<end<<" and "<<row_current<<" "<<col_current<<endl;
      return path_so_far;
    }
    cout<<"moving west"<<endl;
    char move[2];
    move[0] = 'W';
    move[1] = '\0';
    strcat(path_so_far,move);
    //place # char at position
    maze[row_current][colnew] = '#';
    //call find_path
    solution = find_path_rec(maze,height,width,row_current,colnew,end,path_so_far);
    cout<<"solution is: "<<solution<<endl;
    if(strcmp(solution, "no solution") != 0){
      return path_so_far;
    }
    //remove char concatenated
    remove_last(path_so_far);
  }

  //solution [0] = '\0';
	      
  //try moving north
  rownew = row_current - 1;
  if(can_move(maze, rownew ,col_current,end)){    
    if(maze[rownew][col_current] == end){
      cout<<"Found char "<<end<<" and "<<row_current<<" "<<col_current<<endl;
      return path_so_far;
    }
    cout<<"moving north"<<endl;
    char move[2];
    move[0] = 'N';
    move[1] = '\0';
    strcat(path_so_far,move);
    //place # char at position
    maze[rownew][col_current] = '#';
    //call find_path
    solution = find_path_rec(maze,height,width,rownew,col_current,end,path_so_far);
    cout<<"solution is: "<<solution<<endl;
    if(strcmp(solution, "no solution") != 0){
      return path_so_far;
    }
    //remove char concatenated
    remove_last(path_so_far);

  }


  //if no move can be made and/or the moves made result in find_path returning "no_solution"
  //then return "no_solution"
  cout<<"no solution"<<endl;
  string sol = "no solution";
  const char* result = sol.c_str();
  return result;
}


bool can_move(char** maze,int row_to_go,int col_to_go,char end){


  if(maze[row_to_go][col_to_go] != ' ' && maze[row_to_go][col_to_go] != end){
    return false;
  }
 
   if(maze[row_to_go][col_to_go] == '|'){
    //  cout<<"1found hedge"<<endl;
    return false;
  }

  if(maze[row_to_go][col_to_go] == '+'){
    // cout<<"1found limit"<<endl;
    return false;
  }

  if(maze[row_to_go][col_to_go] == '-'){
    // cout<<"1found limit"<<endl;
    return false;
    }

  /* if(maze[row_to_go][col_to_go] == '#'){
    // cout<<"1found limit"<<endl;
    return false;
    }*/
  //cout<<"can move"<<endl;
  //otherwise return true
  return true;
}
		  
	
void remove_last(char* path_so_far){
  
  int i = 0;
  for(; path_so_far[i+1] != '\0'; i++);
    
  path_so_far[i] = '\0';
  //cout<<path_so_far<<endl;
}
  

bool maze_full(char** maze,int height,int width){

  
  for(int i = 0; i < height; i++){
    for(int j = 0; j < width; j++){

      if(!(maze[i][j] == '|' || maze[i][j] == '+' || maze[i][j] == '-' || maze[i][j] == '#' || maze[i][j] == 'U')){
	return false;
      }
    }
  }

  return true;
}


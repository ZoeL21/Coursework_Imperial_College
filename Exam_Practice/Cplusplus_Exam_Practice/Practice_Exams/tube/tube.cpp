#include <iostream>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <vector>
#include <cstdlib>

using namespace std;

#include "tube.h"

/* You are pre-supplied with the functions below. Add your own 
   function definitions to the end of this file. */

/* internal helper function which allocates a dynamic 2D array */
char **allocate_2D_array(int rows, int columns) {
  char **m = new char *[rows];
  assert(m);
  for (int r=0; r<rows; r++) {
    m[r] = new char[columns];
    assert(m[r]);
  }
  return m;
}

/* internal helper function which deallocates a dynamic 2D array */
void deallocate_2D_array(char **m, int rows) {
  for (int r=0; r<rows; r++)
    delete [] m[r];
  delete [] m;
}

/* internal helper function which gets the dimensions of a map */
bool get_map_dimensions(const char *filename, int &height, int &width) {
  char line[512];
  
  ifstream input(filename);

  height = width = 0;

  input.getline(line,512);  
  while (input) {
    if ( (int) strlen(line) > width)
      width = strlen(line);
    height++;
    input.getline(line,512);  
  }

  if (height > 0)
    return true;
  return false;
}

/* pre-supplied function to load a tube map from a file*/
char **load_map(const char *filename, int &height, int &width) {

  bool success = get_map_dimensions(filename, height, width);
  
  if (!success)
    return NULL;

  char **m = allocate_2D_array(height, width);
  
  ifstream input(filename);

  char line[512];
  char space[] = " ";

  for (int r = 0; r<height; r++) {
    input.getline(line, 512);
    strcpy(m[r], line);
    while ( (int) strlen(m[r]) < width )
      strcat(m[r], space);
  }
  
  return m;
}

/* pre-supplied function to print the tube map */
void print_map(char **m, int height, int width) {
  cout << setw(2) << " " << " ";
  for (int c=0; c<width; c++)
    if (c && (c % 10) == 0) 
      cout << c/10;
    else
      cout << " ";
  cout << endl;

  cout << setw(2) << " " << " ";
  for (int c=0; c<width; c++)
    cout << (c % 10);
  cout << endl;

  for (int r=0; r<height; r++) {
    cout << setw(2) << r << " ";    
    for (int c=0; c<width; c++) 
      cout << m[r][c];
    cout << endl;
  }
}

/* pre-supplied helper function to report the errors encountered in Question 3 */
const char *error_description(int code) {
  switch(code) {
  case ERROR_START_STATION_INVALID: 
    return "Start station invalid";
  case ERROR_ROUTE_ENDPOINT_IS_NOT_STATION:
    return "Route endpoint is not a station";
  case ERROR_LINE_HOPPING_BETWEEN_STATIONS:
    return "Line hopping between stations not possible";
  case ERROR_BACKTRACKING_BETWEEN_STATIONS:
    return "Backtracking along line between stations not possible";
  case ERROR_INVALID_DIRECTION:
    return "Invalid direction";
  case ERROR_OFF_TRACK:
    return "Route goes off track";
  case ERROR_OUT_OF_BOUNDS:
    return "Route goes off map";
  }
  return "Unknown error";
}

/* presupplied helper function for converting string to direction enum */
Direction string_to_direction(const char *token) {
  const char *strings[] = {"N", "S", "W", "E", "NE", "NW", "SE", "SW"};
  for (int n=0; n<8; n++) {
    if (!strcmp(token, strings[n])) 
      return (Direction) n;
  }
  return INVALID_DIRECTION;
}


bool get_symbol_position(char** map,int height,int width,char target,int& r,int& c){

  r = -1;
  c = -1;

  //traverse map until target found
  for(int i = 0; i < height; i++){
      for(int j = 0; j < width; j++){
	
	if(map[i][j] == target){
	  r = i; c = j;
	  return true;
	}
      }
    }
	
  return false;
}


char get_symbol_for_station_or_line(const char* name){

  char space = ' ';

  //open file for stations
  FILE* stations = fopen("stations.txt","r");
  if(stations == NULL){
    cout<<"Coud not open file"<<endl;
  }

  //open file for stations
  FILE* lines = fopen("lines.txt","r");
  if(lines == NULL){
    cout<<"Coud not open file"<<endl;
  }

  //buffer to hold line of text
  char buffer[100];

  //traverse stations to look for name, line by line
  while(fgets(buffer,99,stations)){

      //save first char of line
      char c = buffer[0];

      //check if name is found in line read
      if(strstr(buffer,name) != NULL){

	return c;
      }
    }

    //if name not found in stations, look in lines
  while(fgets(buffer,99,lines)){

	//save first char of line
	char c = buffer[0];

	//check if name is found in line read
	if(strstr(buffer,name) != NULL){

	  return c;
	}
      }

  //if nohing has been found, return space chr
  return space;
}

bool is_valid(const char* direction,char* output){

  output[0] = '\0';

  char output_temp[4];
  int i = 0;
  for(; direction[i] != ','; i++){
    
    if(direction[i] == '\0'){
      break;
    }
      
    output_temp[i] = direction[i];
  }
  output_temp[i] = '\0';

  Direction d = string_to_direction(output_temp);

  if(d >= 0 && d < 8){
    strcpy(output,output_temp);
    return true;
  }
  strcat(output," ");
  return false;
}


int validate_route(char** map,int height,int width,const char* start_station, const char* route, const char* destination){

  //check if start_station is a valid station
  char station_symbol = get_symbol_for_station_or_line(start_station);

  //check that its not a space
  if(station_symbol == ' '){
    return ERROR_START_STATION_INVALID;
  }
  //check if symbol does not correspond to a station
  if(!isalnum(station_symbol)){
    return  ERROR_START_STATION_INVALID;
  }

  //get a pointer to route
  char* route_ptr = strdup(route);
  //char* route_ptr = route;
  

  //get position of start station on map
  int r = 0; int c = 0;
  if(!get_symbol_position(map,height,width,station_symbol,r,c)){
    cout<<"Can't find station on map"<<endl;
  }
  cout<<"r is: "<<r<<endl;
  cout<<"c is: "<<c<<endl;

  int changes = 0;
  char current_line = ' ';
  //call recursive function that checks route
  return val_rec(map,height,width,route_ptr,destination,r,c,station_symbol,current_line,changes);
  
}


int val_rec(char** map,int height,int width,char* route,const char* destination,int row_current, int col_current, char last_station, char current_line, int changes){


  /*base case*/
  if(*route == '\0'){
    //check if currently at station
    if(!isalnum(map[row_current][col_current])){
      return (changes - 1);
    }
    else{
      return ERROR_ROUTE_ENDPOINT_IS_NOT_STATION;
    }
  }

  //remember the line we are on
  if(!isalnum(map[row_current][col_current])){
    current_line = map[row_current][col_current];
  }

  /*if we are at a station, current line variable is
    not changed so that we remember teh line we came from*/
 

  char direction[5];
  //check route
  if(!is_valid(route,direction)){
    cout<<"invalid direction"<<endl;
      return ERROR_INVALID_DIRECTION;
    }

  cout<<"direction is: "<<direction<<endl;
  //remember offset of route
  int offset = 0;

  cout<<"encoded direction is: "<<string_to_direction(direction)<<endl;

  //check if by advancing in direction we are in a line or at a station
  int new_row = 0;int new_col = 0;

  if(string_to_direction(direction) == 0){
    new_row = row_current - 1; new_col = col_current;
    offset = 2;
  }
  else if(string_to_direction(direction) == 1){
    new_row = row_current + 1; new_col = col_current;
    offset = 2;
  }
  else if(string_to_direction(direction) == 3){
    new_row = row_current; new_col = col_current + 1;
    offset = 2;
  }
  else if(string_to_direction(direction) == 2){
    new_row = row_current; new_col = col_current - 1;
    offset = 2;
  }
  else if(string_to_direction(direction) == 4){
    new_row = row_current - 1; new_col = col_current + 1;
    offset = 3;
  }
  else if(string_to_direction(direction) == 5){
    new_row = row_current - 1; new_col = col_current - 1;
    offset = 3;
  }
  else if(string_to_direction(direction) == 6){
    new_row = row_current + 1; new_col = col_current + 1;
    offset = 3;
  }
  else if(string_to_direction(direction) == 7){
    new_row = row_current + 1; new_col = col_current - 1;
    offset = 3;
  }
  else{
    cout<<"Error in determining direction"<<endl;
    exit(1);
  }


  if(new_row > height || new_col > width){
    cout<<"going out of bounds"<<endl;
    return ERROR_OUT_OF_BOUNDS;
  }
  

  //check map coontent at current position
  char loc_current = map[row_current][col_current];

  cout<<"current location is: "<<loc_current<<endl;
  
  //check map content at new position
  char loc_to_go = map[new_row][new_col];

  cout<<"going to: "<<loc_to_go<<endl;

  //make sure that map is not a space
  if(isspace(loc_to_go)){
    cout<<"OffTrack"<<endl;
    return ERROR_OFF_TRACK;
  }
  //check that we are not switching lines other than at a station
  else if(!isalnum(loc_current) && loc_to_go != current_line){
    cout<<"invalid switching"<<endl;
    return ERROR_LINE_HOPPING_BETWEEN_STATIONS;
  }

  //record line change
  if(isalnum(loc_current) && loc_to_go != current_line){
    changes ++;
  }

  //increase pointer of route
  if(strlen(route) < offset){
    cout<<"about to segfault"<<endl;
  }

  route += offset;

  //call val_rec
  return val_rec(map,height,width,route,destination,new_row,new_col,last_station,current_line,changes);

}


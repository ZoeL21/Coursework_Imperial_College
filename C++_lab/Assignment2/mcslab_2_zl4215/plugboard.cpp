#include "enigma.h"
#include "errors.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

/*FUNCTION DEFINITIONS of access function*/
int Plugboard::get_size_cnfgdata(){
  return size_config_data;
}

vector<int>* Plugboard::get_mapvector(){
  return v_map;
}

int* Plugboard::get_map(){
  return map_pb;
}
/*END OF FUNCTION DEFINITIONS*/

/*FUNCTION DEFINITION of 'read_data'*/
int Plugboard::read_data(char* data){

  ifstream in;
  in.open(data);
  if(in.fail()){
    cerr<<"ERROR_OPENING_CONFIGURATION_FILE"<<endl;
    return ERROR_OPENING_CONFIGURATION_FILE;
  }

  //create a vector to save and analyse data as it is read in
  v_map = new vector<int>();

  //read in data into config vector
  int temp;
  while(true){
    in >> temp;
    //check for end of file
    if(in.eof()){ 
      break;
    }
   //if vector already contains 26 integers and instream contains integer
    if(v_map->size() == 26 && in.good()){
      cerr<<"Incorrect number of parameters in plugboard file plugboard.pb"<<endl;
      return INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS;
    }
   //if vector already contains 26 integers and instream contains trailing char
    if(v_map->size() == 26 && in.good()){
      cerr<<"Incorrect number of parameters in plugboard file plugboard.pb"<<endl;
      return INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS;
    }
    //check if temp is not an integer
    if(!in.good()){
      cerr<<"Non-numeric character in plugboard file plugboard.pb"<<endl;
      return  NON_NUMERIC_CHARACTER;
    }
    //check if data out of range
    if(temp > 25 || temp < 0){
      cerr<<"INVALID_INDEX"<<endl;
      return INVALID_INDEX;
    }
    //check against the rest of the vector for repetition
    for(unsigned int i = 0; i < (v_map->size()); i++){
      if(v_map->at(i) == temp){
	cerr<<"IMPOSSIBLE_PLUGBOARD_CONFIGURATION"<<endl;
	return IMPOSSIBLE_PLUGBOARD_CONFIGURATION;
      }
    }
    //after all checks have been passed, read into vector
    v_map->push_back(temp);
  }

  //check for uneven number of prameters
  if((v_map->size() % 2) != 0){
    cerr<<"Incorrect number of parameters in plugboard file plugboard.pb"<<endl;
    return INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS;
  }

  size_config_data = v_map->size(); 

  return NO_ERROR;
}
/*END OF FUNCTION DEFINITION*/
 
  
/*FUNCTION DEFINITION of 'map_data'*/
void Plugboard::map_data(){
  //declare array
  map_pb = new int[26];

  //initialize
  for(int i = 0; i < 26; i++){
  map_pb[i] = 30;
  }

  //run through v_map
  for(int i = 0; i < size_config_data; i++){
      
      if(((i % 2) == 0) && (i < (26 - 1))){        
	/*map the index of the map array to the number contained in
         the next positition fo the v_map array*/
	map_pb[v_map->at(i)] = v_map->at(i + 1);
	map_pb[v_map->at(i + 1)] = v_map->at(i);
	 }         
    }  

  //set all remaining values to themselves
  for(int i = 0; i < 26; i++){ 
      if(map_pb[i] == 30){        
         map_pb[i] = i;
      }
   }
  //free v_map
  v_map->clear();
  
}
/*END OF FUNCTION DEFINITION*/

/*FUNCTION DEFINITION of 'map letter'*/
int Plugboard::map_letter(const int letter){
  //go to index of map_pb corresponding to letter
  int mapped_letter = map_pb[letter];
  return mapped_letter;
}
/*END OF FUNCTION DEFINITION*/

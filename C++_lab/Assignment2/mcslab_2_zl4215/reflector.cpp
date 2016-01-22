#include "enigma.h"
#include "errors.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <assert.h>

using namespace std;

/*FUNCTION DEFINITIONS of access functions*/
int Reflector::get_size_cnfgdata(){
  return size_config_data;
}

vector<int>* Reflector::get_mapvector(){
  return v_map;
}

int* Reflector::get_map(){
  return map_rf;
}
/*END OF FUNCTION DEFINITIONS*/


/*FUNCTION DEFINITION of 'read_data'*/
int Reflector::read_data(char* data){

  ifstream in;
  in.open(data);
  if(in.fail()){
    cerr<<"ERROR_OPENING_CONFIGURATION_FILE"<<endl;
    return ERROR_OPENING_CONFIGURATION_FILE;
  }

  //create a vector to save and analyse data as it is read in
  v_map = new vector<int>();

  //read in data into v_map vector
  int temp;
  while(true){
    in >> temp;
    //check for end of file
    if(in.eof()){
      break;
    }
    //if vector already contains 26 integers and instream contains integer
    if(v_map->size() == 26 && in.good()){
      cerr<<"Incorrect (odd) number of parameters in reflector file reflector.rf"<<endl;
      return INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS;
    }
    //if vector already contains 26 integers and instream contains trailing character
    if(v_map->size() == 26 && !in.good()){
      cerr<<"Non-numeric character in reflector file reflector.rf"<<endl;
      return  NON_NUMERIC_CHARACTER;
    }

    //check if temp is not an integer
    if(!in.good()){
      cerr<<"Non-numeric character in reflector file reflector.rf"<<endl;
      return  NON_NUMERIC_CHARACTER;
    }
    //check if data is out of range
    if(temp > 25 || temp < 0){
      cerr<<"INVALID_INDEX"<<endl;
      return INVALID_INDEX;
    }
    
    //check against the rest of the vector for repetition
    for(unsigned int i = 0; i < (v_map->size()); i++){
      if(v_map->at(i) == temp){
        cerr<<"INVALID_REFLECTOR_MAPPING"<<endl;
        return  INVALID_REFLECTOR_MAPPING;
      }
    }    
   //after all checks have been passed, read into vector
    v_map->push_back(temp);
  }  


  //check for correct number of parameters
  if((v_map->size() < 26 && ((v_map->size() % 2) == 0))){
    cerr<<"Insufficient number of mappings in reflector file: reflector.rf"<<endl;
    return INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS;
  }
  if((v_map->size() < 26 && ((v_map->size() % 2) != 0))){
    cerr<<"Incorrect (odd) number of parameters in reflector file reflector.rf"<<endl;
    return INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS;
  }

  size_config_data = v_map->size();
  return NO_ERROR;
  
}
/*END OF FUNCTION DEFINITION*/

  
/*FUNCTION DEFINITION of 'map_data'*/
void Reflector::map_data(){
  //declare array
  map_rf = new int[26];

  //initialize
  for(int i = 0; i < 26; i++){
    map_rf[i] = 30;
  }

  //run through v_map
  for(int i = 0; i < size_config_data; i++){

    if(((i % 2) == 0) && (i < (26 - 1))){
      /*map the index of the map array to the number contained in
	the next positition fo the v_map array*/
      map_rf[v_map->at(i)] = v_map->at(i + 1);
      map_rf[v_map->at(i + 1)] = v_map->at(i);
    }
  }
  //free v_map
  v_map->clear();  
}
/*END OF FUNCTION DEFINITION*/


/*FUNCTION DEFINITION of 'map_letter'*/
int Reflector::map_letter(const int letter){
  //go to index of map_rf corresponding to letter
  // assert(letter <= 25 && letter >= 0);
  int mapped_letter = map_rf[letter];
  return mapped_letter;
}
/*END OF FUNCTION DEFINITION*/

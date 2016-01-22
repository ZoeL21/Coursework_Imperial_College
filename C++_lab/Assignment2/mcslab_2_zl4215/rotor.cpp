#include "enigma.h"
#include "errors.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

/*FUNCTION DEFINITIONS of Rotors-class access functions*/
int Rotors::get_position(){
  return position;
}
/*****/

void Rotors::set_position(int pos){
  position = pos;
}
/*****/

vector<int>* Rotors::get_mapvector(){
  return map_rot;
}
/*****/

vector<int>* Rotors::get_notchvector(){
  return v_notch;
}
/*****/

bool Rotors::get_notchstat(){
  return this->notchstat;
}
/*END OF FUNCTION DEFINITIONS*/


/*FUNCTION DEFINITION of 'setup_rotors'*/
int setup_rotors(const int argc,vector<Rotors>* &v_rotors, char** argv){
  unsigned int nbr_of_rotors = argc - 4;
  //index to access the rotor configuration files
  int index_argv = 3;
  //variable to keep track of the return value
  int ret_val = 0;
  
 //create each rotor and read data in for each object;
  for(unsigned int i = 0; i < nbr_of_rotors; i++){    
    v_rotors->push_back(Rotors());
  }

  for(int i = (nbr_of_rotors - 1); i >= 0; i--){
    ret_val = ((v_rotors->at(i)).read_data(argv[index_argv]));
    index_argv++;
    if(ret_val != 0){
      return ret_val;
      }
    }
  return 0;
}
/*END OF FUNCTION DEFINITION*/



/*FUNCTION DEFINITION of 'read_data'*/
int Rotors::read_data(char* data){

    ifstream in;
    in.open(data);
    if(in.fail()){
      cerr<<"ERROR_OPENING_CONFIGURATION_FILE"<<endl;
      return ERROR_OPENING_CONFIGURATION_FILE;
    }

    //create a vector to save and analyse data as it is read in
    map_rot = new vector<int>();

    //read in data into map_rot vector
    int temp_mapdata;
    for(int i = 0; i < 26; i++){
      in >> temp_mapdata;
      //check for end of file
      if(in.eof() || in.bad()){
	break;
      }
      //check if in fails if temp is not an integer
      if(in.fail()){
	cerr<<"Non-numeric character for mapping in rotor file rotor.rot"<<endl;
	return  NON_NUMERIC_CHARACTER;
      }
      //check if data is out of range
      if(temp_mapdata > 25 || temp_mapdata < 0){
	cerr<<"INVALID_INDEX"<<endl;
	return INVALID_INDEX;
      }
      //check against the rest of the vector for repetition
      for(unsigned int j = 0; j < (map_rot->size()); j++){
         if(map_rot->at(j) == temp_mapdata){
           cerr<<"Invalid mapping of input "<<i;
	   cerr<<" to output "<<map_rot->at(j)<<" (output "<<map_rot->at(j);
	   cerr<<" is already mapped to from input "<<j<<")";
	   cerr<<" in rotor file: rotor.rot"<<endl; 
           return INVALID_ROTOR_MAPPING;
	    }
      }
      //after all checks have been passed, read into vector
      map_rot->push_back(temp_mapdata);
    }

    //check for correct number of parameters
    if((map_rot->size() < 26)){
       cerr<<"Not all inputs mapped in rotor file: rotor.rot"<<endl;
       return INVALID_ROTOR_MAPPING;
    }
   
    //allocate memory for vector holding notch data
    v_notch = new vector<int>();

    //continue reading in from the same input stream
    int temp_notchdata = 0;
    while(true){
      in >> temp_notchdata;
      //check for end of file
      if(in.eof()){       
	break;
      }
      //check if in fails if temp is not an integer
      if(!in.good()){
	cerr<<"Non-numeric character for mapping in rotor file rotor.rot"<<endl;
	return  NON_NUMERIC_CHARACTER;
      }
      //check if data is out of range
      if(temp_notchdata > 25 || temp_notchdata < 0){
	cerr<<"INVALID_INDEX"<<endl;
	return INVALID_INDEX;
      }
      //check for notch repetition
      for(unsigned int i = 0; i < v_notch->size(); i++){
	if(v_notch->at(i) == temp_notchdata){
	  cout<<"Warning: Notch repetition!"<<endl;	  
	}
      }
     //after all checks have been passed, read into vector
      v_notch->push_back(temp_notchdata);
    }

    //check if notches are empty
    if(v_notch->size() == 0){
      cout<<"Warning: no notches"<<endl;
    }

    //check if there are too many notches
    if(v_notch->size() > 26){
      cerr<<"Too many notches"<<endl;
      return INVALID_ROTOR_MAPPING;
    }
    

    //read into size attribute of rotor
    size_notchdata = v_notch->size();    
    
    //close filestream
    in.close();

    return NO_ERROR;
 }
/*END OF FUNCTION DEFINITION*/

      	  

/*FUNCTION DEFINITION of 'map_letter_forward'*/
int Rotors::map_letter_forward(const int letter){
  //go to index of map_rf corresponding to letter
  int mapped_letter = map_rot->at(letter);
  return mapped_letter;
}
/*END OF FUNCTION DEFINITION*/

/*FUNCTION DEFINITION of 'map_letter_backwards'*/
int Rotors::map_letter_backward(const int letter){
  int mapped_letter = 0;
  //go to index of map_rf corresponding to letter
  for(int i = 0; i < (26); i++){
    //int index = 0;
    if(map_rot->at(i) == letter){
       mapped_letter = i;
    }
  }
  return mapped_letter;
}
/*END OF FUNCTION DEFINITION*/


/*FUNCTION DEFINITION of 'read_init_positions'*/
int read_init_positions(char* data, vector<Rotors>* v_rotors, const unsigned int nbr_of_rotors){

  //create a vector to hold the initial position of each rotor
  vector<int> rotor_init_pos;
  
  ifstream in;
  in.open(data);
  if(in.fail()){
    return ERROR_OPENING_CONFIGURATION_FILE;
  }

  //read data into array from last to first
  int temp_init_pos;
  for(unsigned int i = 0; i < nbr_of_rotors; i++){
    in >> temp_init_pos;
    //check for end of file
    if(in.eof()){
      break;
          }
    //check if input is an integer//CHECK OF IN.BAD() ETC.
    if(!in.good()){
	cerr<<"Non-numeric character in rotor positions file rotor.pos"<<endl;
	return  NON_NUMERIC_CHARACTER;
    }
    //check if data is out of range
      if(temp_init_pos > 25 || temp_init_pos < 0){
	cerr<<"INVALID_INDEX"<<endl;
	return INVALID_INDEX;
      }
      //if tests are passed, push into vector
      rotor_init_pos.push_back(temp_init_pos);
  }
  /*after reading the three integers, check the rest of the 
    file for trailing characters*/
  int trail_char;
  while(true){
    in >> trail_char;
    if(in.eof()){
      break;
    }
    if(!in.good()){
	cerr<<"Non-numeric character in rotor positions file rotor.pos"<<endl;
	return  NON_NUMERIC_CHARACTER;
    }
  }

  //close filestream
  in.close();
  
  //check if enough positions in file
  if(nbr_of_rotors != rotor_init_pos.size()){
    cerr<<"No starting position for rotor 0 in rotor position file: rotor.pos"<<endl;
    return NO_ROTOR_STARTING_POSITION;
  }

  /*read the initial positions backwards into the array
  as they are given in the wrong order*/  
  int read_backwards_index = nbr_of_rotors; 
  
  for(unsigned int i = 0; i < nbr_of_rotors; i++){
    read_backwards_index -= 1;
    v_rotors->at(read_backwards_index).set_position(rotor_init_pos.at(i));
   }    

  return 0;
}
/*END OF FUNCTION DEFINITION*/


/*FUNCTION DEFINITION of 'rotate'*/
void Rotors::rotate(){
  //temp array storage
  vector<int> vector_temp(26,0);
  /*move every element except for first one 
    in rotor_array one down and move the first one to the last position*/
  for(int i = 0; i < 25; i++){
    vector_temp.at(i) = map_rot->at(i+1);
  }
  //move first element of rotor_array to last element of array_temp
  vector_temp.at(25) = map_rot->at(0);
  //copy temp into rotor_array
  for(int i = 0; i < 26; i++){
    map_rot->at(i) = vector_temp.at(i);
  }
  /*decrease the content of each array cell by 1
   as the output position of the rotor changed*/
  for(int i = 0; i < 26; i++){
    if(map_rot->at(i) <= 0){
      map_rot->at(i) = 25;
    }
    else{
      map_rot->at(i) = ((map_rot->at(i)) - 1);
    }
  }
  
  //increase position by one
  position++;
  //return to zero when reaching 26
  if(position >= 26){
    position = 0;
  }
  
  //check if notch has been hit
  this->set_notchstat();  
}
/*END OF FUNCTION DEFINITION*/


/*FUNCTION DEFINITION of overloaded function 'rotate'*/
void Rotors::rotate(const int position){
  //cout<<"rotating to: "<<position<<endl;
  for(int k = 0; k < position; k++){
    this->rotate();
  } 
    
  //reset notchstat in case it has been hit
  this->reset_notchstat();
 }
/*END OF FUNCTION DEFINITION*/  


/*FUNCTION DEFINITION of rot_to_init_pos*/
void rot_to_init_pos(vector<Rotors>* v_rotors, unsigned int nbr_of_rotors){
  //rotate to initial positions
  for(unsigned int i = 0; i < nbr_of_rotors; i++){
    //save initial position before rotation
    int initial_pos = v_rotors->at(i).get_position();
    //rotate rotor
    v_rotors->at(i).rotate(v_rotors->at(i).get_position());
    //reset position
    v_rotors->at(i).set_position(initial_pos);
  }
}
/*END OF FUNCTION DEFINITION*/


/*FUNCTION DEFINITION of 'isnotchset'*/
void Rotors::isnotchset(Rotors prev_rotor){
  if(prev_rotor.get_notchstat() == true){
    //cerr<<"NOTCH HIT on previous rotor"<<endl;
    rotate();
  }
}
/*END OF FUNCTION DEFINITION*/

/*FUNCTION DEFINITION of 'set_notchstat'*/
void Rotors::set_notchstat(){
  //traverse array of notches and compare with position to see if notch is hit
  for(int i = 0; i < size_notchdata; i++){
    if(v_notch->at(i) == position){
      this->notchstat = true;
      break;
    }
  }
}
/*END OF FUNCTION DEFINITION*/

/*FUNCTION DEFINITION of 'reset_nocthstat*/
void Rotors::reset_notchstat(){
  this->notchstat = false;
}
/*END OF FUNCTION DEFINITION*/

#include <iostream>
#include <fstream>
#include <stdio.h>
#include "errors.h"
#include "enigma.h"

using namespace std;

/*FUNCTION DEFINITION of 'create_Plugboard'*/
int Enigma::create_Plugboard(char* data){ 
  
  ptr_pb = new Plugboard();
  int ret_val = ptr_pb->read_data(data);  
  ptr_pb->map_data();
  return ret_val;
}
/*END OF FUNCTION DEFINITION*/

/*FUNCTION DEFINITION of 'get_ptr_pb'*/
Plugboard* Enigma::get_ptr_pb(){
  return ptr_pb;
}
/*END OF FUNCTION DEFINITION*/

/*FUNCTION DEFINITION of 'create_Reflector'*/
int Enigma::create_Reflector(char* data){
  
  ptr_rf = new Reflector();
  int ret_val = ptr_rf->read_data(data);  
  ptr_rf->map_data();
  return ret_val;
}
/*END OF FUNCTION DEFINITION*/

/*FUNCTION DEFINITION of 'get_ptr_rf'*/
Reflector* Enigma::get_ptr_rf(){
  return ptr_rf;
}
/*END OF FUNCTION DEFINITION*/

/*FUNCTION DEFINITION of 'create_Rotors'*/
int Enigma::create_Rotors(char** data, int argc){
    
    //allocate memory for the rotor vector
    v_rotors = new vector<Rotors>();

    //declare variable for the number of rotors
    nbr_of_rotors = argc - 4;

    //read rotor_data
    int ret_val = setup_rotors(argc,v_rotors,data);
    if(ret_val != 0){
       return ret_val;
    }
    
    //read initial positions of the rotors
    ret_val = read_init_positions(data[argc - 1],v_rotors, nbr_of_rotors);
    if(ret_val != 0){
       return ret_val;
    }

    //rotate to initial positions
    rot_to_init_pos(v_rotors, nbr_of_rotors);    
        
    //display_rot_data(nbr_of_rotors,v_rotors);
    return NO_ERROR;
}
/*END OF FUNCTION DEFINITION*/

/*FUNCTION DEFINITION of 'get_v_rotors'*/
vector<Rotors>* Enigma::get_v_rotors(){
  return v_rotors;
}
/*END OF FUNCTION DEFINITION*/

/*FUNCTION DEFINITION of 'get_nbr_of_rotors'*/
int Enigma::get_nbr_of_rotors(){
  return nbr_of_rotors;
}
/*END OF FUNCTION DEFINITION*/

/*FUNCTION DEFINITION of 'get_input'*/
int get_input(int& letter){
  char letter_input;
  cin>>letter_input;
 
  if(cin.peek() == EOF){
    return 0;
  }
  if(letter_input == ' ' || letter_input == '\n'){
    return -2;
  }
  if(letter_input == '\t' || letter_input == '\r'){
    return -2;
  }
  if(letter_input > 'Z' || letter_input < 'A'){
  letter = letter_input;
    return -3;
  } 
  letter = letter_input - 65;
  
  return -1;
}
/*END OF FUNCTION DEFINITION*/


/*FUNCTION DEFINITION OF 'char output'*/
char output(int letter_encrypted){
  char letter_output = letter_encrypted + 65;
  return letter_output;
}
/*END OF FUNCTION DEFINITION*/


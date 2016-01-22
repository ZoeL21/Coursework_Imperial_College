#include <iostream>
#include <fstream>
#include "errors.h"
#include "enigma.h"
#include <stdio.h>
#include <cstring>

using namespace std;

int main(int argc, char** argv)
{

  //check if number of arguments is less than minimum
  if((argc < 3)){
    cerr<<"usage: enigma plugboard-file reflector-file (<rotor-file>* rotor-positions)?"<<endl;
    return INSUFFICIENT_NUMBER_OF_PARAMETERS;
  } 

  //check that if we have rotors, we have a position file
  if(argc > 3){
    if(strstr(argv[argc - 1], "pos") == NULL){
      cerr<<"No position file!"<<endl;
      return INSUFFICIENT_NUMBER_OF_PARAMETERS;
    }
  }

  //create an Enigma Class and a pointer to it
  Enigma E;
  Enigma* E_ptr = &E;
  /*create a variable to hold the return value
  throughout the creatin of the Enigma components*/
  int ret_val;
  //create and configure the plugboard
  ret_val = E.create_Plugboard(argv[1]);
  if(ret_val != 0){
    return ret_val;
  }

  //create and configure the reflector
  ret_val = E.create_Reflector(argv[2]);
  if(ret_val != 0){
    return ret_val;
  }   
  
 
  //create Rotors if there are rotor configuration files
  if(argc > 3){    
    int ret_val = E.create_Rotors(argv,argc);
    if(ret_val != 0){
       return ret_val;
    }
  }

  /*getting input, encypt letter and output it to std 
    output stream*/
  int letter = 0;  
  while(true){
    ret_val = get_input(letter);
    if(ret_val == 0){
      return ret_val;
    }
    if(ret_val == -3){
      cerr<<static_cast<char>(letter)<<" is not a valid input character (input characters must be upper case letters A-Z)!"<<endl;
      return INVALID_INPUT_CHARACTER;   
      }
    if(ret_val == -2){
      continue;
    }
    int letter_encrypted = encryption(letter,E_ptr);
    char letter = output(letter_encrypted);
    cout<<letter;
  } 
  
  return NO_ERROR;
}

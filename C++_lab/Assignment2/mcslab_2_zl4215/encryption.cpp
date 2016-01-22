#include <iostream>
#include <fstream>
#include <stdio.h>
#include "errors.h"
#include "enigma.h"

using namespace std;

/*FUNCTION DEFINITION of 'encryption.cpp'*/
int encryption(int letter,Enigma* E_ptr){

   //if there are rotors, rotate first rotor after input
  if(E_ptr->get_v_rotors() != NULL){
    (E_ptr->get_v_rotors()->at(0)).rotate();
  }

  //encrypt
  cout<<"letter is: "<<letter<<endl;
  //pass through plugboard and save inside encrypt_letter variable
  int encrypt_letter = E_ptr->get_ptr_pb()->map_letter(letter);
  cout<<"encryption after plugboard is: "<<encrypt_letter<<endl;
 
  //if there are rotors, pass through rotors
  if(E_ptr->get_v_rotors() != NULL){
    for(int i = 0; i < E_ptr->get_nbr_of_rotors(); i++){
      /*check from second rotor onwards if notch of previous rotor
      has been hit*/
      if(i > 0){
        E_ptr->get_v_rotors()->at(i).isnotchset(E_ptr->get_v_rotors()->at(i-1));
      }
      //pass rotor the letter and update encrypted letter
      encrypt_letter = E_ptr->get_v_rotors()->at(i).map_letter_forward(encrypt_letter);
      cout<<"encryption after rotor: "<<i<<" "<<encrypt_letter<<endl;
    }
    //reset notchstats
    for(int i = 0; i < E_ptr->get_nbr_of_rotors(); i++){
      E_ptr->get_v_rotors()->at(i).reset_notchstat();
    }
  }

  //pass through reflector
  encrypt_letter = E_ptr->get_ptr_rf()->map_letter(encrypt_letter);
  cout<<"encryption after reflector is: "<<encrypt_letter<<endl;

  //if there are rotors, pass backwards through rotors
  if(E_ptr->get_v_rotors() != NULL){
    for(int i = ((E_ptr->get_nbr_of_rotors()) - 1); i >= 0; i--){
    //pass rotor the letter and update encrypted letter
      encrypt_letter = E_ptr->get_v_rotors()->at(i).map_letter_backward(encrypt_letter);
      cout<<"encryption after rotor: "<<i<<" "<<encrypt_letter<<endl;
  }
  }

  //pass through plugboard 
  encrypt_letter = E_ptr->get_ptr_pb()->map_letter(encrypt_letter);
  cout<<"encryption after plugboard is: "<<encrypt_letter<<endl;
  return encrypt_letter;
}
/*END OF FUNCTION DEFINITION*/

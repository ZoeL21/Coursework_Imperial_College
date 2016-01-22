#include "multitap_better.h"
#include <cctype>
#include <cstring>
#include <iostream>

using namespace std;

int encode_character(char ch, char* multitap){
  
  int length = 0;

  //varibale to hold the encoding for ch
  int number = 0;
    

  //case where ch is a space
  if(ch == ' '){
    multitap[0] = '0';
    multitap[1] = '\0';
    length = 1;
    return length;
  }

  
  if(isdigit(ch) != 0){
    length = 2;
    multitap[0] = '*';
    multitap[1] = ch;
    multitap[3] = '\0';
    return length;
  }

  if(isalpha(ch) != 0){


    //check if uppercase
    if(!islower(ch)){
      //change to lowercase
      ch = tolower(ch);
    }

    //change to base 0
    int ch_int = static_cast<int>(ch) - 97;
    

    if(ch_int >= 15 && ch_int < 19){
      number = 7;
      length = (ch_int - 14) % 5;
    }
    else if(ch_int == 25){
      number = 9;
      length = 4;
    }
    else if(ch_int >= 19){      
      ch_int -= 1;
      number = ch_int/3 + 2;
      length = (ch_int % 3) + 1;
    }
    else{
      number = ch_int/3 + 2;
      length = (ch_int % 3) + 1;
    }

  }
  
  //append to multitap char array
  append_to(number,length,0,multitap);
  
  return length;
}


void append_to(int number,int length, int count,char* multitap){

  //base case
  if((count - length) >= 0){
    multitap[count] = '\0';
  }
  else{
    
    /*change into character*/
    char num_char = static_cast<char>(number + 48); 
    multitap[count] = num_char;
    count += 1;
    append_to(number,length,count,multitap);
  }
}

    
void encode(const char* plaintext,char* multitap){

  //set to lowercase initially
  bool up_case = 0;

  //call recursive helper function
  encode_recursive(plaintext,0,multitap,up_case);

}

void encode_recursive(const char* plaintext,int count,char* multitap,bool up_case){

  //base case
  if(plaintext[count] == '\0'){
    multitap = strcat(multitap,"\0");
  }
  else{

    //check if have to add #
    if(isalpha(plaintext[count])){
    if(!islower(plaintext[count]) && up_case == 0){
      multitap = strcat(multitap,"#");
      up_case = 1;
    }

    if(islower(plaintext[count]) && up_case == 1){
      multitap = strcat(multitap,"#");
      up_case = 0;
    }
      }

    char char_multitap[20];
    char_multitap[0] = '\0';

    //call encode_character
    encode_character(plaintext[count],char_multitap);

    //check for repetition
    if(multitap[0] != '\0'){
      if(char_multitap[0] == multitap[strlen(multitap) - 1]){
	multitap = strcat(multitap,"¦");
      }
    }

    //append
    multitap = strcat(multitap,char_multitap);
    //increase count
    count += 1;
    encode_recursive(plaintext,count, multitap,up_case);
    //call recursively
    
  }
}



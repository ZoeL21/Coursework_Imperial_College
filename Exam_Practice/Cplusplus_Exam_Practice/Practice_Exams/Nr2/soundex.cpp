#include "soundex.h"
#include <cstring>
#include <string>
#include <iostream>


using namespace std;

void encode(const char* surname, char* soundex){

  //initialize soundex
  soundex[0] = '\0';
 
  //save first letter to coundex
  char start = surname[0];

  string soundex_string = string() + start;

  char current = '0';
  char categ = '0';

  
  //traverse surname until end is reached
  for(int i = 0; surname[i] != '\0'; i++){
  
    if(soundex_string.length() > 3){
      break;
    }

    if(surname[i] == 'b' || surname[i] == 'f' || surname[i] == 'p' || surname[i] == 'v'){
      categ = '1';
    }
    else if(surname[i] == 'c' || surname[i] == 'g' || surname[i] == 'j' || surname[i] == 'k' || surname[i] == 'q' || surname[i] == 's' ||surname[i] == 'z' || surname[i] == 'x'){
      categ = '2';
    }
    else if(surname[i] == 'd' || surname[i] == 't'){
      categ = '3';
    }
    else if(surname[i] == 'l'){
      categ = '4';
    }
    else if(surname[i] == 'm' || surname[i] == 'n'){
      categ = '5';
    }
    else if(surname[i] == 'r'){
      categ = '6';
    }
    else{
      categ = '0';
      continue;
    }

    if(categ != current){
    //add code to the string
    soundex_string = soundex_string + categ;
    }

    //change current to categ
    current = categ;

   
   
      
    }

  //if length is smaller than 4, add 0 until length is 4
  while(soundex_string.length() != 4){
    soundex_string = soundex_string + '0';
  }

  //change soundex string into char*

  const char* soundex_char = soundex_string.c_str();
  
  //copy into soundex
  strcpy(soundex,soundex_char);

}


bool compare(const char* str1, const char* str2){

  if(*str1 == '\0' && *str2 == '\0'){
    return true;
  }

  if(*str1 == *str2){
    //advance pointers
    str1++; str2++;
    if(compare(str1,str2)){
      return true;
    }
  }

  //otherwise must be false
  return false;
}


int count(const char* surname, char* sentence){

  int count = 0;

  return count_rec(surname,sentence,count);

}

int count_rec(const char* surname, char* sentence,int count){

  if(strlen(sentence) <= 1){
    return count;
  }

  string buffer = string();
  
  //find word delimited by , and space
  char* delim = strchr(sentence, ' ');
  if(delim == NULL){
    //get the last word
    for(int i = 0; i < strlen(sentence); i++){
    buffer = buffer + sentence[i];
    }
  }
  else{
    int diff = delim - sentence;
    for(int i = 0; i < diff; i++){
      buffer = buffer + sentence[i];
    }
  }
 
  const char* buffer_c = buffer.c_str();

  if(buffer != "and"){
    //get the encoding for buffer and surname anch check if thy are equal
    char surname_enc[5];
    encode(surname,surname_enc);

    char buffer_enc[5];
    encode(buffer_c,buffer_enc);

    if(compare(surname_enc,buffer_enc)){
      count++;
    }
  }

  if(delim == NULL){
    return count;
  }

  //advance delim until next letter is reached
  while(!isalpha(*delim)){    
    delim++;
  }
 
  return count_rec(surname, delim, count);
}






  

#include "substring.h"
#include <iostream>
#include <cstring>

using namespace std;


bool is_prefix(const char* str1, const char* str2){

  if(*str1 != *str2){
    return false;
  } 

  else if(str1[1] == '\0'){
    return true;
  }

  else if(*str2 == '\0'){
    return false;
  }
  else
    {
      str1++;
      str2++;
      if(is_prefix(str1,str2)){
	return true;
      }
      else{
	return false;
      }
    }
}


int substring_position_rec(const char* sub,const char* text, int pos){
  
  //if end of text is reached, return -1
  if(text[0] == '\0'){
    return -1;
  }

  //and then check if sub is a prefix of current text
  if(is_prefix(sub,text)){
    return pos;
  }
  else{
    //advance position
    pos++;
    //advance text pointer to check next letter
    text++;
    //call substring position recursively
    return substring_position_rec(sub,text,pos);
  }
}




int substring_position(const char* sub,const char* text){

  //catch cases of sub being empty
  if(sub[0] == '\0'){
    return 0;
  }

  //catch case of text and sub being empty
  if(sub[0] == '\0' && text[0] == '\0'){
    return 0;
  }

  int pos = 0;

  return substring_position_rec(sub,text,pos);
  
}

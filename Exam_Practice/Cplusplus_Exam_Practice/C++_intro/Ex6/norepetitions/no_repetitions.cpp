#include "no_repetitions.h"
#include <cstring>
#include <string>

using namespace std;

char* remove_rep(char* array){

  char buffer[strlen(array)];
  buffer[0] = '\0';
  char* no_rep = new char[strlen(array)];
  no_rep[0] = '\0';

  int i = 0;
  while(array[i] != '\0'){
    if(!rep(buffer,array[i])){
      //add letter to array of no repetitions
      char buf[2];
      buf[0] = array[i];
      buf[1] = '\0';
      strcat(no_rep,buf);

      //add letter to buffer
      char c[2];
      c[1] = '\0';
      c[0] = array[i];
      strcat(buffer,c);
      }
    i +=1 ;
  }

  //as an alternative, copy norep into array
  strcpy(array,no_rep);

  return no_rep;
}

bool rep(char* array,char letter){

  for(unsigned int i = 0; i < strlen(array); i++){
    if(letter == array[i]){
    return true;
    }
  }

  return false;
}


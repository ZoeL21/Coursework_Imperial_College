#include "words.h"
#include <cstring>
#include <string>
#include <cctype>
#include <iostream> 

using namespace std;


void reverse(const char* str1, char* str2){

 int length = strlen(str1);

 //copy into str2
 int index = 0;
 for(int i = length - 1; i >= 0; i--){
   str2[index] = str1[i];
   index++;
 }

 //add sentinel char
 str2[length] = '\0';


}


bool check_foralpha(const char* sentence){

  while(*sentence != '\0'){
      if(isalpha(*sentence)){
	return true;
      }
      sentence++;
    }
  return false;
}

bool compare(const char* one, const char* two){

 //check for end of equal words
  if(*one == '\0' && *two == '\0'){
    return true;
  }

  if(*one == '\0'){

    if(check_foralpha(two)){
      return false;
    }
    else{
      return true;
    }
  }

 if(*two == '\0'){

   if(check_foralpha(one)){
      return false;
    }
    else{
      return true;
    }
  } 
 

  //advance if char is not a letter
  while(!isalpha(*one)){
    if(*one == '\0'){
      if(check_foralpha(two)){
	return false;
      }
      else{
	return true;
      }
    }
    one++;
  }

  while(!isalpha(*two)){
    if(*two == '\0'){
      if(check_foralpha(one)){
	return false;
      }
      else{
	return true;
      }
    }
    two++;  }

  
  char one_c;
  char two_c;

  //change both to lowercase to compare
  if(isupper(*one)){
      one_c = tolower(*one);
    }
    else{
      one_c = *one;
    } 

    if(isupper(*two)){
      two_c = tolower(*two);
    }
    else{
      two_c = *two;
    } 

  if(one_c == two_c){
    one++;
    two++;
    if(compare(one,two)){
      return true;
    }
  }

  return false;
}
  
bool one_letter(const char* sentence){

  int count = 0;

  for(int i = 0; sentence[i] != '\0'; i++){
    if(isalpha(sentence[i])){
	count++;
      }
  }
  if(count > 1){
    return false;
  }
  return true;
}

bool palindrome(const char* sentence){


  if(strlen(sentence) == 1){
    return true;
  }

  //check for longer strings if there is only one letter
  if(strlen(sentence) >= 1){
    if(one_letter(sentence)){
	return true;
      }
  }
      
  //divide sentence in two
  int length = strlen(sentence);
  int half = 0;
  if((length % 2) == 0){
    half = length/2 - 1;
  }
  else{
    half = length/2;
  }

  //check that if it is an even lettered 

  char first_half[half + 1];
  char second_half[half + 1];

  for(int i = 0; i < half; i++){
    first_half[i] = sentence[i];      
  }
  first_half[half] = '\0';

  int index = 0;
  for(int i = strlen(sentence) - half; i <= length; i++){
    second_half[index] = sentence[i];
    index++;
    
  }
  second_half[half] = '\0';
  //reverse second half

  char second_reversed[half + 1];
  reverse(second_half,second_reversed);

  
  //compare the halves
  if(compare(first_half,second_reversed)){
    return true;
  }

  return false;
}

int smaller(int index, int length, const char* sent){

  char value = tolower(sent[index]);
  int index_smallest = index;

  for(int i = index + 1; i < length; i++){
    if(tolower(sent[i]) < value){
      index_smallest = i;
      value = tolower(sent[i]);
    }
  }
  return index_smallest;
}

void order(char* sent){

  int length = strlen(sent);

  for(int i = 0;i < length; i++){
    
    int i_ = smaller(i,length,sent);
    if(i_ != i){
      char temp = tolower(sent[i]);
      sent[i] = tolower(sent[i_]);
      sent[i_] = temp;
    }
  }

}

bool anagram(const char* str1, const char* str2){

  //save all the letters in buffer
  string buffer1 = string();

  for(int i = 0; i < strlen(str1); i++){
    if(isalpha(str1[i])){
	buffer1 = buffer1 + str1[i];
      }
  }

  //save all the letters in buffer
  string buffer2 = string();

  for(int i = 0; i < strlen(str2); i++){
    if(isalpha(str2[i])){
	buffer2 = buffer2 + str2[i];
      }
  }

  //change to cstring
  const char* buffer1_c = buffer1.c_str();
  const char* buffer2_c = buffer2.c_str();

  char copy1[strlen(buffer1_c) + 1];
  char copy2[strlen(buffer2_c) + 1];

  strcpy(copy1,buffer1_c);
  strcpy(copy2,buffer2_c);

  //cout<<buffer1<<endl;
  // cout<<buffer2<<endl;
  //order both strings alphabetically
  order(copy1);
  order(copy2);

  //cout<<copy1<<endl;
  //cout<<copy2<<endl;


  
  if(strcmp(copy1,copy2) == 0){
    return true;
  }

  return false;
}



      

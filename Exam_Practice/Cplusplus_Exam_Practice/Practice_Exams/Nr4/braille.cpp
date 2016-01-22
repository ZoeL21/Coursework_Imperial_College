#include "braille.h"
#include <cstring>
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ostream>

using namespace std;

int encode_character(char c,char* braille){

  string prefix = string();

  if(isupper(c)){
    prefix = ".....0";
    c = tolower(c);
  }

  if(isdigit(c)){
    prefix = "..0000";
  }

  //string buffer = string();

  //Or use a map
  //map<char><string> 
  const char* buffer_c = lookup_char(c);

  //encode each char
    /* if(c == 'a' || c == '1'){
    buffer = "0.....";
  }
  else if( c == 'b' || c == '2'){
    buffer = "00....";
  }
  else if( c == 'c' || c == '3'){
    buffer = "0..0..";
  }
  else if( c == 'd' || c == '4'){
    buffer = "0..00.";
  }
  else if( c == 'e' || c == '5'){
    buffer = "0...0.";
  }
  else if( c == 'f' || c == '6'){
    buffer = "00.0..";
  }
  else if( c == 'g' || c == '7'){
    buffer = "00.00.";
  }
  else if( c == 'h' || c == '8'){
    buffer = "00..0.";
  }
  else if( c == 'i' || c == '9'){
    buffer = ".0.0..";
  }
  else if( c == 'j' || c == '0'){
    buffer = ".0.00.";
  }
  else if( c == 'k'){
    buffer = "0.0...";
  }
  else if( c == 'l'){
    buffer = "000...";
  }
  else if( c == 'm'){
    buffer = "0.00..";
  }
  else if( c == 'n'){
    buffer = "0.000.";
  }
  else if( c == 'o'){
    buffer = "0.0.0.";
  }
  else if( c == 'p'){
    buffer = "0000..";
  }
  else if( c == 'q'){
    buffer = "00000.";
  }
  else if( c == 'r'){
    buffer = "000.0.";
  }
  else if( c == 's'){
    buffer = ".000..";
  }
  else if( c == 't'){
    buffer = ".0000.";
  }
  else if( c == 'u'){
    buffer = "0.0..0";
  }
  else if( c == 'v'){
    buffer = "000..0";
  }
  else if( c == 'w'){
    buffer = ".0.000";
  }
  else if( c == 'x'){
    buffer = "0.00.0";
  }
  else if( c == 'y'){
    buffer = "0.0000";
  }
  else if( c == 'z'){
    buffer = "0.0.00";
  }
  else if( c == '.'){
    buffer = ".0..00";
  }
  else if(c == ','){
    buffer = ".0....";
  }
  else if(c == ';'){
    buffer = ".00...";
  }
  else if( c == '-'){
    buffer = "..0..0";
  }
  else if( c == '!'){
    buffer = ".00.0.";
  }
  else if( c == '?'){
    buffer = ".00..0";
  }
  else if( c == '(' || c == ')'){
    buffer = ".00.00";
  }
    */
  string braille_str = prefix + buffer_c;
  const char* braille_c = braille_str.c_str();
  int size = strlen(braille_c);
  strcpy(braille,braille_c);

  return size;
}    


void encode(const char* plaintext,char* braille){

  //initialize braille
  braille[0] = '\0';

  //encode first character and concatenate to braille
  encode_rec(plaintext,braille);
}

void encode_rec(const char* plaintext,char* braille){

  //return if reched end of plaintext
  if(*plaintext == '\0'){
    return;
  }

  //encode first char of plaintext
  char buffer[20];
  encode_character(*plaintext,buffer);

  //attach encoding to braille
  strcat(braille,buffer);
  //advance pointer
  plaintext++;
  //call encode_rec
  encode_rec(plaintext,braille);
}

bool can_advance(char*& ptr){
  for(int i = 0; i < 3; i++){
    ptr++;
    if(strlen(ptr) <1){
      return false;
    }
  }
  return true;
}

void print_braille(const char* plaintext,ostream& out){

  //string to save actual word
  int size = strlen(plaintext);
  char text[size*2];
  strcpy(text,plaintext);
  
  char* ptr = text;
  
  char buffer[size*2];
  out<<plaintext<<endl;


  //create string of word
  int i = 0;
  while(*ptr != '\0'){
    if(isupper(*ptr) || isdigit(*ptr)){
      buffer[i] = ' ';
      ++i;
      buffer[i] = *ptr;
      i++;
      ptr++;
    }
    else{
      buffer[i] = *ptr;
      ++i;
      ptr++;
    }
  }
  //add sentinel char
  buffer[i + 1] = '\0';

  for(int i = 0; i < strlen(buffer); i++){
    cout<<buffer[i]<<"   ";
  }
  cout<<endl;


  //get braille string of plaintext
  char braille[size*12];
  encode(plaintext,braille);

  //print every third element until the endofstring is reached
  for(int i = 0; i < 3; i++){
    char* ptr_a = braille;
    ptr_a += i;
    while(*ptr_a != '\0'){
      out<<*ptr_a<<" ";
      //advance 3 unless eof is reached
      if(!can_advance(ptr_a)){
	break;
      }
    }

    cout<<endl;
  }


  for(int i = 0; i < strlen(buffer); i++){
    cout<<buffer[i]<<"   ";
  }
  cout<<endl;

}

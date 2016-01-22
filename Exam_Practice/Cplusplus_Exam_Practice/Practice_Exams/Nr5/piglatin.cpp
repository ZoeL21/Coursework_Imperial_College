#include "piglatin.h"
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int findFirstVowel(const char* word){

  int length = strlen(word);

  for(int i = 0; i < length; i++){

    if(word[i] == 'a' || word[i] == 'o' || word[i] == 'u' || word[i] == 'e' || word[i] == 'i'){
      return i;
    }
  }
    return -1;
}


void translateWord(const char* english, char* translated){

  translated[0] = '\0';

  //if first letter is a number, just copy whole thing to translated
  if(isdigit(english[0])){
    strcpy(translated,english);
    translated[strlen(english)] = '\0';
    return;
  }
  
  //find first vowel
  int vpos = findFirstVowel(english);


  char first_part[vpos + 1];

  strncpy(first_part, english, vpos);
  first_part[vpos] = '\0';

  //cout<<first_part<<endl;  

  char pigend[] = "ay";  

  char end[strlen(english) - vpos + 1];
  int index = 0;
  //copy last part of string
  for(int i = vpos; english[i] != '\0'; i++){
    end[index] = english[i];
    index++;
  }

  end[strlen(english) - vpos] = '\0';

  //attach ptr, first part and ay
  strcat(end,first_part);
  
  strcat(end,pigend);

 
  //copy into translated
  strcpy(translated,end);

}


void translateStream(ifstream& in, ostream& out){
 
  //take a word at a time

  while(true){

    string word = string();
    char buffer;   

    in.get(buffer);
    if(in.eof()){
      break;
    }

    //cout<<"here"<<endl;
    if(isalnum(buffer)){
	
	//cout<<"here"<<endl;
	while(isalnum(buffer)){

	  //attach to word
	  word = word + buffer;
	  in.get(buffer);
	  if(in.eof()){
	    cout<<"reached eof"<<endl;
	    break;
	  }
	}  

	
	//change into cstring
	const char* word_c = word.c_str();

	//translate
	char translated[65];
	translateWord(word_c,translated);

	//translated[strlen(word_c) + 1] = '\0';
	int wordlength = strlen(word_c) + 1;

	//pass to output stream
	for(int i = 0; i < wordlength; i++){
	  out.put(translated[i]);
	}

      }
    
      //if buffer is not alnum, just add it to outstream
      out.put(buffer);
     
  }
}

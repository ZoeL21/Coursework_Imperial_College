#include "words.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

void add_info(int count,vector<wordinfo>& words){
  //traverse whole vector to see if word with this amount of letters does already exists
  for(int i = 0;i < words.size();i++){
    if(words[i].length == count){
      words[i].amount += 1;
      return;
    }
  }
  //if hasn't returned yet, no word of length count exists, so add
  words.push_back(wordinfo(count,1));
}
      


void read_text(FILE* file, vector<wordinfo>& words){

  char buffer;
  //traverse file 
  while(!feof(file)){

    int count = 0;
    //read char until whitespace reached
    while(fgetc(file) != ' '){
      if(feof(file) || ferror(file)){
	break;
      }
      count++;
      cout<<count<<endl;
    }
    //if space character is reached, add space to first vector element
    if(words.size() == 0){
      cout<<"size is empty"<<endl;
      
      //push back one wors.push_back
      words.push_back(wordinfo(0,1));
      //words[0].length = 0;
      //words[0].amount = 1;
      //add word info to vectr
      add_info(count,words);
    }
    else{
      cout<<"added one more space"<<endl;
      words[0].amount += 1;
      add_info(count,words);
    }
  }
}

#include "words.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main(int argc, char* argv[]){


  if(argc != 2){
    cout<<"usage error"<<endl;
    exit(1);
  }

  //read text from function arguments
  ifstream in;
  FILE* file = fopen(argv[1],"r");
  if(in.fail()){
    cout<<"Could not open file"<<endl;
    exit(1);
  }

  //create a vector to hold the info about the words
  vector<wordinfo> words;

  //parse text
  read_text(file, words);

  if(words.size() !=  0){
    for(int i  = 0; i < words.size(); i++){
	cout.setf(ios::left);
	cout.width(20);
	cout<<words[i].length;
	cout<<words[i].amount<<endl;
    }
  }
  else{
    cout<<"vector is empty"<<endl;
  }
  // display_vector(words);

  return(0);
}

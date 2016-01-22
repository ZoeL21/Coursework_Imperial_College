/*This file contains several simple examples of string manipulation*/


#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

int main(){

  //first only using character arrays

  char sentence[] = " This is a texting string";

  int size_sentence = strlen(sentence);

  char user_input[100];
  //getting a string from a user
  cin.getline(user_input,19);

  cout<<"Your input was: "<<user_input<<endl;

  //checking if failbit is set if deliminating char is not found after reading more than 20 chars
  if(cin.fail()){
    cout<<"string was too long"<<endl;
  }



  //concatenating the strings
  char new_sentence[100];
  strcat(user_input,sentence);

  cout<<user_input<<endl;
  /*  //getting unknown user input using realloc
  //char* next_word = NULL;  
  //char unknown_sentence[] = "\0";
  char* longer_sentence = NULL;
  cout<<"Enter a sentence: (enter 0 to end)"<<endl;

  char buffer[10];
  int count = 0;

  cin.getline(buffer,4);
  int size = cin.gcount();
  cout<<"This worked, read : "<<size<<" characters"<<endl;
  while(buffer[0] != '0'){

    count++;

    longer_sentence = (char*)realloc(buffer, strlen(buffer)*10  );

    strcat(longer_sentence,buffer);
    longer_sentence[count*strlen(buffer) - 1] = '\0';
    cin.getline(buffer,10);

    cout<<"sentence is now: "<<longer_sentence<<endl;
  }
  */

  //copying the string
  
  return(0);
}

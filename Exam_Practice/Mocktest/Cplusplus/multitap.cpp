#include "multitap.h"
#include <cctype>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;



void clear(char* multitap){

  int size = strlen(multitap);
  memset(multitap,0,size);

}


int encode_character(char ch,char* multitap){

  //integer to hold length
  int length = 0;

  //character to hold the number
  char number;
  
  
  
  //case digit
  if(isdigit(ch) != 0){
    cout<<"is digit"<<endl;
    //set length to 2
    length = 2;

    //string one = "*";
    //string two = string(ch);

    multitap[0] = '*';
    multitap[1] = ch;
    multitap[2] = '\0';
   

    //multitap = strcat(multitap,one.c_str());
    //multitap = strcat(multitap,two.c_str());

    //multitap = "*5\0";

  }

  //check if it is a space
    if(ch == ' '){      
      multitap[0] = '0';
      multitap[1] = '\0';
      length = 1;
      return length;
    }

  //case letter
  if(isalpha(ch) != 0){    

    

    //check if is uppercase
    if(islower(ch) == 0){
      //change to lowercase
      ch = tolower(ch);
    }


    //change into integer
    int c_int = static_cast<int>(ch);

    //change to base 0;
    c_int -= 97;

    //cout<<"char in int is: "<<c_int<<endl;

    //get representative number and length of string
    if(c_int < 3){
      length = (c_int % 3) + 1;
      number = '2';
    }
    else if(c_int < 6){
      length = (c_int % 6) + 1 - 3;
      number = '3';
    }
    else if(c_int < 9){
      length = (c_int % 9) + 1 - 6;
      number = '4';
    }
    else if(c_int < 12){
      length = (c_int % 12) + 1 - 9;
      number = '5';
    }
    else if(c_int < 15){
      length = (c_int % 15) + 1 - 12;
      number = '6';
    }
    else if(c_int < 19){
      length = (c_int % 19) + 1 - 15;
      number = '7';
    }
    else if(c_int < 22){
      length = (c_int % 22) + 1 - 19;
      number = '8';
    }
    else{
      length = (c_int % 26) + 1 - 22;
      number = '9';
    }
    //result = string();
    string result = "";

    for(int i = 0; i < length; i++){
      result += number;
    }


    //c_intonc_intatenate string
    strcat(multitap,result.c_str());
    
  }
  memset(&ch,0,sizeof(ch));
return length;
}



void encode(const char* plaintext,char* multitap){

  /*clear multitap before reusing*/
  multitap[0] = '\0';

  //variable to keep track of upper or lower case state
  bool up_case = false;

  //save length of string input
  int length = strlen(plaintext);
  
  //traverse string input until end,
  //appending each result to multitap

  for(int i = 0; i < length; i++){

    
    if(isalpha(plaintext[i]) != 0){
      if((!islower(plaintext[i])) && up_case == false){
	
	/*add # to string*/
	multitap = strcat(multitap,"#");
	/*set up_case to true*/
	up_case = true;      
      }

      
      if(islower(plaintext[i]) && up_case == true){
	/*add # to string*/
	multitap = strcat(multitap,"#");
	/*set up_case to false*/
	up_case = false;
      }
    }
    

    char multitap_char[20];
    multitap_char[0] = '\0';    

    
    encode_character(plaintext[i],multitap_char);   
    
    //check for consecutive encoding
    if(multitap[0] != '\0'){
      
      if(multitap_char[0] == multitap[strlen(multitap) - 1]){
	//add a pause character
	multitap = strcat(multitap,"|");
      }
    }


    multitap = strcat(multitap,multitap_char);

  }
}

  

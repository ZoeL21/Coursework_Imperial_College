#include "multitap.h"
#include <iostream>

using namespace std;


int main(){


  /******checking Question 1**********/
  char multitap[512];
  multitap[0] = '\0';

  int size;
  size = encode_character('1',multitap);

  cout<<"encoding of character w: "<<multitap<<endl;
  cout<<"size: "<<size<<endl;

  clear(multitap);
  
  //multitap[0] = "\0";

  multitap[0] = '\0';
  size = encode_character('1',multitap);

  cout<<"encoding of character l: "<<multitap<<endl;
  cout<<"size: "<<size<<endl;

  /******checking Question 2**********/
  /*encode("Meet Anna at 5pm",multitap);
    cout<<"encoding of 'Meet Anna at 5pm'\n"<<multitap<<endl;*/
 
}


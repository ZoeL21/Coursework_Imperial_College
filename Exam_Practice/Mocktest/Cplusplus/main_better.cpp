#include "multitap.h"
#include <iostream>
#include <cstring>

using namespace std;


int main(){


  /******checking Question 1**********/
  char multitap[512];
  multitap[0] = '\0';

  int size;
  size = encode_character('w',multitap);

  cout<<"encoding of character w: "<<multitap<<endl;
  cout<<"size: "<<size<<endl;  

  memset(multitap,0,strlen(multitap));
  multitap[0] = '\0';
  size = encode_character('1',multitap);

  cout<<"encoding of character l: "<<multitap<<endl;
  cout<<"size: "<<size<<endl;

  multitap[0] = '\0';
  /******checking Question 2**********/
  encode("Meet Anna at 5pm",multitap);
    cout<<"encoding of 'Meet Anna at 5pm'\n"<<multitap<<endl;
  return 0;

}

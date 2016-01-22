#include <iostream>
#include <fstream>

using namespace std;

int main(){

  char ch;

  //declare stream object
  ifstream in;

  //open file and cnnect to stream
  in.open("printmyself.cpp");

  //read content of file to std output
  while(!in.eof()){
    in.get(ch);
    cout<<ch;
  }

  return(0);
}

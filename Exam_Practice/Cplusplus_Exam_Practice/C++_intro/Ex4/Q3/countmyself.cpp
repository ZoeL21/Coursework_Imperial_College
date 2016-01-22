#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(){

  //creating streams
  ifstream in;

  //opening the stream and testing
  in.open("countmyself.cpp");
  if(in.fail()){
    cout<<"could not open file"<<endl;
    exit(1);
  }

  //variable to hold count
  int count = 0;

  //chr buffer
  char c;

  //counting chars
  in.get(c);
  while(!in.eof()){
    count++;
    in.get(c);
  }

  //output count
  cout<<"count: "<<count<<endl;

  //closing the stream
  in.close();

  return(0);
}

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void print_backwards(int count);
void count_chars(int& count);

int main(){

  //count characters that are in file
  int count = 300;
  count_chars(count);

  cout<<count<<endl<<endl;

  print_backwards(count);

  return(0);
}

void count_chars(int& count){

  //create stream
  ifstream in;
  in.open("print_backwards.cpp");
  if(in.fail()){
    cout<<"could not open"<<endl;
    exit(1);
  }

  char c;
  in.get(c);
  while(!in.fail()){
    count++;
    in.get(c);
  }

  in.close();
}  

void print_backwards(int count){

  char c;

  while(count > 0){

    //create stream
    ifstream in;
    in.open("print_backwards.cpp");
    if(in.fail()){
      cout<<"could not open"<<endl;
      exit(1);
    }


  for(int i = 0; i < (count);i++){
    in.get(c);
  }
  //print last character
  cout<<c;

  //decrease count
  count--;

  //close stream
  in.close();
  }
}



  

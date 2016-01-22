#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(){

  ifstream in;
  char c;
  int count;

  //print title
  cout.setf(ios::left);
  cout.width(10);
  cout<<" ";
  cout.width(20);
  cout<<"CHARACTER";
  cout<<"OCCURRENCE"<<endl;

  //traverse file
  for(int i = static_cast<int>('a'); i <= static_cast<char>('z'); i++){
    //open file
    in.open("char_count.cpp");
    if(in.fail()){
      cout<<"could not open"<<endl;
      exit(1);
    }

    //reset count;
    count = 0;
    in.get(c);
    while(!in.eof()){
      if(static_cast<int>(c) == i){
	count++;
      }
      in.get(c);
    }
    //close file
    in.close();

    //print result
      cout.width(10);
      cout<<" ";
      cout.width(20);
      cout<<static_cast<char>(i);
      cout<<count<<endl;
  }

  return(0);
}

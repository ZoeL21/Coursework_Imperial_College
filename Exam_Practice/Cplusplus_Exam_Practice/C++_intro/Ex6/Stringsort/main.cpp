#include <iostream>
#include "stringsort.h"
#include <cstdlib>

using namespace std;

int main(){

   int size;
   cout<<"input the size of your string\n";
   cin>>size;
   cin.ignore();
  if(cin.fail()){
    cout<<"invalid size"<<endl;    
    exit(1);
  }

  char* thestring = new char[size];

  cout<<"content of string?:\n";
  cin.getline(thestring,size);

  //  char thestring[30];
  //cin.getline(thestring,30);

  cout<<"the unsorted string:"<<endl;
  display_string(thestring);

  sort_string(thestring);

  cout<<"The sorted string: "<<endl;
  display_string(thestring);

  cout<<"the sorted string: "<<thestring<<endl;

  return(0);
}

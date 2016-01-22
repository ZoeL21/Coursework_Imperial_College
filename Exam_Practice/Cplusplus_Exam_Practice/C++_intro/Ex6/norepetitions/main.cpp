#include "no_repetitions.h"
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main(){


  char first_array[20];
  cout<<"Content of first array:"<<endl;
  cin.getline(first_array,19);
  cout<<"first array: "<<endl;
  cout<<first_array<<endl;

  int size;
  cout<<"Size of second array: "<<endl;
  cin>>size;
  if(cin.fail()){
    cout<<"invalid size"<<endl;
    exit(1);
  }
  cin.ignore();
  char* second_array = new char[size+1];
  cout<<"content of second array: "<<endl;
  cin.getline(second_array,size);

  cout<<"second array: "<<endl;
  cout<<second_array<<endl;

  //removing repetitions
  char* result1 = remove_rep(first_array);
  char* result2 = remove_rep(second_array);

  cout<<"First array without rep: "<<result1<<endl;
  cout<<"Second array without rep: "<<remove_rep(second_array)<<endl;

  cout<<endl;
  cout<<first_array<<endl;
  cout<<second_array<<endl;

  delete result1;
  delete result2;

  return(0);
}

#include "isprime.h"
#include <iostream>

using namespace std;

int main(){

  cout<<"Please input a number between 1 and 1000"<<endl;
  int number;
  cin>>number;
  if(cin.fail() || number < 1 || number > 1000){
    cout<<"Wrong input"<<endl;
  }

  if(isprime(number)){
      cout<<number<<" is a prime."<<endl;
    }
    else{
      cout<<number<<" is not a prime"<<endl;
    }

  return(0);
}

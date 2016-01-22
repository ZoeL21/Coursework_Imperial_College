#include <iostream>
#include <cmath>
#include "prime.h"
using namespace std;

int main()
{
  //define var
  int num = 0;

  //ask user for input
  cout<<"please type in a number to test between 1 and 1000"<<endl;
  cin>>num;

  cout<< prime(num)<<endl;

  return 0;
}

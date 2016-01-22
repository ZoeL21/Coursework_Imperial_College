#include <iostream>
#include "binarysearch.h"

using namespace std;

int main()
{
  int array[10];

  cout<<"please enter "<<10<<" values."<<endl;
  for(unsigned int i = 0; i < 10; i++)
    {
      cin>>array[i];
    }

  int value;
  cout<<"Search for value: "<<endl;
  cin>>value;

  cout<<"location of value: "<<binary_search(value,array,0,9)<<endl;

  return 0;
}

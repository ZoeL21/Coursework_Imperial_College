#include "binarysearch.h"
#include <iostream>

using namespace std;

int binary_search(int value, int list[], int first, int last)
{
  int median = (first + last)/2;
  //base case
  if(value == list[median])
    return median;
  else if(first == last || first > last)
    {
      cout<<"not in list"<<endl;
      return -1;
    }
  else if(value > list[median])
    {
      //only consider right half of list
      return binary_search(value,list,(median + 1),last);
    }
  else if(value < list[median])
    {
      //only coonsider left half of list
      return binary_search(value,list,first,(median - 1));
    }
  else
    {
    cout<<"ERROR"<<endl;
    return -2;;\
    }
}

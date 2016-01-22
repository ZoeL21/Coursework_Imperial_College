#include <iostream>
#include <math.h>
#include "IntegerArray.h"

using namespace std;

int main()
{
  int n = 7;
  int a[n];

  //input values
  input_array(a,n);
  display_array(a,n);

  int a_copy[n];
  copy_array(a_copy,a,n);

  display_array(a_copy,n);

  cout<<"stddev of a: "<<standard_deviation(a,n)<<endl;

  return 0;
}

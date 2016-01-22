#include "arrays.h"
#include <iostream>

using namespace std;

int main(){

  int array1[12];
  int array2[6];
  cout<<"sizeof array2: "<<sizeof(array2)<<endl;
 
  input_array(array1,12);

  cout<<endl;
  cout<<"array1: "<<endl;

  display_array(array1,12);

  input_array(array2,5);

  cout<<endl;
  cout<<"array 2: "<<endl;

  display_array(array2,sizeof(array2));

  cout<<endl;

  copy_array(array1,array2,12);

  cout<<endl;
  cout<<"again, array1: "<<endl;

  display_array(array1,12);

  return(0);
}

#include "arrays.h"
#include <iostream>

using namespace std;

void input_array(int array[],int n){

  cout<<"Enter "<<n<<" integers separated by a space."<<endl;

  for(int i = 0; i < n; i++){
    cin>>array[i];
  }

  cout<<"Thank you"<<endl;
}

void display_array(int array[],int n){

  for(int i = 0; i < n;i++){
    cout<<array[i]<<" ";
  }
  cout<<endl;
}

void copy_array(int a1[],int a2[],int n){
  
  for(int i = 0; i < n;i++){
    a1[i] = a2[i];
  }
}

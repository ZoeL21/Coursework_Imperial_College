#include <iostream>
#include <cstdlib>

using namespace std;

//prototypes
void print(int height);

int main(){

  int height;

  cout<<"Give a height (1 to 30) for the pyramid"<<endl;
  cin>>height;
  if(cin.fail() || height > 30 || height < 1){
    cout<<"Wrong input"<<endl;
    exit(1);
  }

  //print pyramid
  print(height);

  return(0);
}

void print(int height){

  int width = height;

  for(int i = 0; i < height; i++, width--){
    cout.width(width);
    for(int amount = 0; amount < ((i*2)+2); amount++){
      cout<<"*";
    }
    cout<<endl;
  }
}
  

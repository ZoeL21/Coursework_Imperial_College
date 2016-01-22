#include <iostream>
#include <cctype>
#include <cstdio>

using namespace std;

int main(){

  char input;

  //getting char input
  cin>>input;

  if(isupper(input)){
    cout<<"lowercase equivalent of "<<input<<" is: "<<static_cast<char>(tolower(input))<<endl;
  }
  else if(islower(input)){
    cout<<"uppercase equivalent of "<<input<<" is: "<<static_cast<char>(toupper(input))<<endl;
  }
  else{
    cout<<"invalid input, input lowercase or uppercase letter"<<endl;
  }

  return(0);
}

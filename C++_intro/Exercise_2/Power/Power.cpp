#include <iostream>

using namespace std;

int main()
{
  //define variables
  int number;
  int power;
  
  //get user input
  cout<<"Please enter any real number"<<endl;
  cin>>number;

  cout<<"Please enter a positive power"<<endl;
  cin>>power;

  //define variable
  int numberp = number;

  //check if power is positive
  if(power < 0)
    {
      cout<<"Power is not positive"<<endl;
      return 1;
    }
  
  //raise to power
  for(int i = 1; i < power; i++)
    {
      numberp = numberp*number;
    }
  //show number
  cout<<number<<" to the power of "<<power<<" is: "<<numberp<<endl;

  return 0;
}

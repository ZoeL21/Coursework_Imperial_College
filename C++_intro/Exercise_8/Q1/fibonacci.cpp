#include <iostream>
#include <cmath>

using namespace std;

/*DECLARATION of function which computes the fibonnaci number of an integer*/
int fibonacci(int number);

int main()
{

  int number;
  cout<<"enter an integer to comput fibonacci number"<<endl;
  cin>>number;

  cout<<"fibonacci number of "<<number<<" is: "<<fibonacci(number)<<endl;

  return 0;
}

/*FUNCTION DEFINITION FOR "fibonacci"*/
int fibonacci(int number)
{
  //base cases
  if(number == 0)
    {
      return number;
    }
  else if(number == 1)
    {
      return number;
    }
  else if(number == 2)
    {
      return 1;
    }

  return number = fibonacci((number - 1)) + fibonacci((number - 2));

}
/*END OF FUNCTION DEFINITION */

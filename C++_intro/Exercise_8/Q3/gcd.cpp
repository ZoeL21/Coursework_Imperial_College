#include <iostream>
#include <cstdlib>
using namespace std;

/*Function declaration to determine the greatest common divisor of 2 integers*/
int gcd(int m, int n);

int main()
{
  int m = 0;
  int n = 0;

  cout<<"Type in two integers leaving a space:"<<endl;
  cin>>m>>n;

  cout<<"greatest common divisor is: "<<gcd(m,n)<<endl;
    
  return 0;
}

/*FUNCTION DEFINITION OF "gcd"*/
int gcd(int m, int n)
{
  //base cases
  if(m == n)
    {
       return m;
    }
  else if(m <=0 || n <=0)
    {
    cout<<"no greatest commo divisor"<<endl;
    exit(1);
    } 
  else if(m > n)
    {
    return gcd(n, (m-n));
    }
  else
    {
    return gcd(m, (n-m));
    }
}

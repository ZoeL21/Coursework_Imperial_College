#include <iostream>
#include <cmath>
#include "IntegerArray.h"

using namespace std;

//function definitions
void input_array(int a[],int n)
{
  cout<<"Please input "<<n<<" values into array a: "<<endl;
  for(int i= 0; i < n; i++)
    {
      cin>>a[i];
    }

}

void display_array(int a[], int n)
{
  cout<<endl<<"array: ";
  for(int i = 0; i < n; i++)
    {
      cout.width(2);
      cout<<a[i];
    }
  cout<<endl;
}

void copy_array(int a1[], int a2[], int n)
{
  for(int i = 0; i < n; i++)
    {
      a1[i] = a2[i]; 
    }
 
}

double standard_deviation(int a[], int n)
{
  double sum = 0;
  //compute average
  for(int i = 0; i < n; i++)
    {
      sum += a[i];
    }

  double average = sum/n;

  double variance = 0;

  for(int i = 0; i < n; i++)
    {
      variance += pow((a[i] - average),2);
    }

  double stddev = sqrt(variance/n);
  return stddev; 


}

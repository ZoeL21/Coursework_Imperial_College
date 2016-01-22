#include <iostream>
#include <cstdlib>
#include <string>
#include "boolean.h"

using namespace std;

int main()
{

  //getting the size of the string frm the USER
  int size1;
  int size2;
  cout<<"Please put in the size of string1"<<endl;
  cin>>size1;
  //  cin>>size1;
  //cin.clear();cin.sync();
  cout<<"Please input the size of string2"<<endl;
  cin>>size2;
  //cin>>size2;
  //cin.clear();cin.sync();

  //declaring pointers to dynamically allocated arrays
  strptr string1 = NULL;
  
  strptr string2 = NULL;

    try
    {
      string1 = new char[size1];
     cout<<"allocated1"<<endl;
    }catch(bad_alloc)
    {
      cout<<"Sorry out of memory"<<endl;
      exit(1);
      }
  try
    {
      string2 = new char[size2];
     cout<<"allocated2"<<endl;
    }catch(bad_alloc)
    {
      cout<<"Sorry out of memory"<<endl;
      exit(1);
    } 
  cout<<"loc1:"<<&string1<<endl; 
    cout<<"loc2: "<<&string2<<endl;
  cout<<"Size1: "<<size1<<endl;
  cout<<"Size2: "<<size2<<endl;

  cout<<"\n Please enter string1: "<<endl;
  cin.getline(string1,size1);

  cout<<"\nPlease enter string2: "<<endl;
  cin.getline(string2,size2);

  //call function
  if(smaller(string1,string2))
    {
      cout<<"string 1 is alphabetically smaller than string 2"<<endl;
    }
  else
    {
      cout<<"string 2 is alphabetically smaller than string 1"<<endl;
    }

  //deallocate memry
  delete [] string1;
  delete [] string2;

  return 0;
}

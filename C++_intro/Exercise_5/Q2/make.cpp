#include <iostream>
#include "Pyramid.h"

using namespace std;

int main()
{
  int height = 0;
  do
    {
       cout<<"put in the height for the pyramid"<<endl;
       cin>>height;

       if(height < 1 && height > 30)
        {
           cout<<"sorry invalid input, height between 1 and 30"<<endl;
        }
    }while(height < 1 || height > 30);

    //call function
    Pyramid(height);

  return 0;

}

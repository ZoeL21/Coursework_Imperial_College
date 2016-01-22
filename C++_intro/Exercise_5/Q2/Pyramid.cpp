#include "Pyramid.h"
#include <iostream>

using namespace std;

void Pyramid(int height)
{
  //start with two stars
  
  //calculate space that will be needed to output pyramid
  int space = (height*2*2) + 1;
  
  
  for(int i = 1; i < (height + 1); i++)
    {

      cout.width(space);
      for(int j = 1; j < (i + i); j++)
         {
            cout<<"*";
            if(j == (i + i - 1))
              {
		  cout<<"*"<<endl;
                  space -= 1;
		}
	 }

         //increase the space by one
         //space += 1;
           
      
    }
}

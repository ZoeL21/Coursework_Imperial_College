#include <iostream>
#include "statistics.h"

using namespace std;


int main()
{

  //variable def
  int input = 0;

  //prompt user for input
  cout<<"how many values would you like to use?(1-4)"<<endl;
  cin>>input;

  if(input < 1 || input > 4)
    {
      return 1;
      cout<<"error"<<endl;
    }

  /*cout<< "input the values" <<endl;

  for(int i=0; i<input; i++) 
    {
      cin >> array[i];
      }*/

  //declare values
  double n1 = 0,n2 = 0,n3 = 0, n4 = 0;

  switch (input)
    {

    case 1:
	
          
            cout<<"input value: "<<endl;
            cin>>n1;

            //call functions
            cout<<"average: "<<average(n1)<<endl;
            cout<<"standard deviation: "<<stndiv(n1)<<endl;
            //ask the user for the values
	    break;
	
    case 2:
        
           
      cout<<"input values: "<<endl;
      cin>>n1;
      cin>>n2;

      //call functions
      cout<<"average: "<<average(n1, n2)<<endl;
      cout<<"standard deviation: "<<stndiv(n1, n2)<<endl;
      break;
        
    case 3:
      
 
      cout<<"input values: "<<endl;
      cin>>n1;
      cin>>n2;
      cin>>n3;

      //call functions
      cout<<"average: "<<average(n1, n2, n3)<<endl;
      cout<<"standard deviation: "<<stndiv(n1, n2, n3)<<endl;
      break;
       
    case 4:
      
 
      cout<<"input values: "<<endl;
      cin>>n1;
      cin>>n2;
      cin>>n3;
      cin>>n4;

      //call functions
      cout<<"average: "<<average(n1, n2, n3, n4)<<endl;
      cout<<"standard deviation: "<<stndiv(n1, n2, n3, n4)<<endl;
         break;
       
    default:
        return 1; 

    }




  return 0;
}



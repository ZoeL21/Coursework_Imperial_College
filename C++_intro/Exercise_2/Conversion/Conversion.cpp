#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  //ask user if he wants to use fixed amount of conversions or a min and max with step size

  int decision = 0;
  while(decision != 1 && decision != 2)
    {
       cout<<"would you like to convert a number of values (1) or a range of values with step size (2)?\n";
  cin>>decision;
    }

  if(decision == 1)
    {
      //ask user how many conversions
      int amount = 0;
      cout<<"how many conversions \n";
      cin>>amount;
      cout<<"amount : "<<amount<<"\n";

      //define variables
      double Fvalue[amount], Cvalue[amount], Avalue[amount];


      //read in value for Fahrenheit
       cout<<"please enter all values in Fahrenheit which you whish to convert into Celcius and Kelvin \n";
      for(int i = 0; i < amount; i++)
	{
	  cin>>Fvalue[i];
          cout<<"\n";
	
        //calculate values in Celcius and Kelvin
        Cvalue[i] = (Fvalue[i] - 32)*5/9;
        Avalue[i] = (Cvalue[i] + 273.15);
	}


        //output header
          cout.width(15);
          cout<<"Fahrenheit";
          cout.width(15);
          cout<<"Celsius";
          cout.width(15*2);
          cout<<"Absolute Value \n\n";

        //output content
       for(int i = 0; i < amount; i++)
       	{
          cout.width(15);
	  cout<<setprecision(2)<<fixed<<Fvalue[i];
          cout.width(15);
          cout<<setprecision(2)<<fixed<<Cvalue[i];
          cout.width(18);
          cout<<setprecision(2)<<fixed<<Avalue[i]<<endl;
       	}
       }
  else if(decision == 2)
    {
      //define variables
      int max, min, step;
      int amount;
      
      //read in values
      cout<<"give in the max value in Fahrenheit \n";
      cin>>max;
      cout<<"max : "<<max<<"\n";
      cout<<"give in the min value in Fahrenheit \n";
      cin>>min;
      cout<<"min : "<<min<<"\n";
      cout<<"give in the steps \n";
      cin>>step;
      cout<<"step : "<<step<<"\n";

      //calculate how many values are needed      
      amount = ((max - min) / step) + 1;

      

      //calculate
      if((max-min) % step == 0)
	{
          //steps are even

          //define arrays
          double Fvalue[amount], Cvalue[amount], Avalue[amount];
      

          //set first value to min
          Fvalue[0] = min;

          //Calculate
          for(int i = 0; i < amount; i++)
	    {
              Cvalue[i] = (Fvalue[i] - 32)*5/9; 
              Avalue[i] = Cvalue[i] + 273.15;
              if(i < (amount-1))
		{
                  Fvalue[i + 1] = Fvalue[i] + step;
		}
	    }
          //output
          cout.width(15);
	  cout<<"Fahrenheit";
          cout.width(15);
          cout<<"Celsius";
          cout.width(15*2);
          cout<<"Absolute Value";
          
          cout<<"\n\n";

	  for(int i = 0; i < amount; i++)
	     {
	       cout.width(15);
               cout<<setprecision(2)<<fixed<<Fvalue[i];
               cout.width(15);
               cout<<setprecision(2)<<fixed<<Cvalue[i];
               cout.width(18);
               cout<<setprecision(2)<<fixed<<Avalue[i]<<endl;
	     }
	}
      else 
	{
          //steps are uneven
          //define arrays
          double Fvalue[amount + 1], Cvalue[amount + 1], Avalue[amount + 1];
      

          //set first value to min
          Fvalue[0] = min;

          //Calculate
          for(int i = 0; i < amount; i++)
	    {
              Cvalue[i] = (Fvalue[i] - 32)*5/9; 
              Avalue[i] = Cvalue[i] + 273.15;
              if(i < (amount - 1))
		{
                  Fvalue[i + 1] = Fvalue[i] + step;
		}
	    }
	  //set last value to the max
         
          Fvalue[amount] = max;
           cout<<"last value : "<<Fvalue[amount]<<endl;
          Cvalue[amount] = (Fvalue[amount] - 32)*5/9; 
          Avalue[amount] = Cvalue[amount] + 273.15;

          //output
          cout.width(15);
	  cout<<"Fahrenheit";
          cout.width(15);
          cout<<"Celsius";
          cout.width(15*2);
          cout<<"Absolute Value";
          
          cout<<"\n\n";

	  for(int i = 0; i < (amount + 1); i++)
	    {
	       cout.width(15);
               cout<<setprecision(2)<<fixed<<Fvalue[i];
               cout.width(15);
               cout<<setprecision(2)<<fixed<<Cvalue[i];
               cout.width(18);
               cout<<setprecision(2)<<fixed<<Avalue[i]<<endl;
	    }
	}
      
    
         
    }
  return 0;
}





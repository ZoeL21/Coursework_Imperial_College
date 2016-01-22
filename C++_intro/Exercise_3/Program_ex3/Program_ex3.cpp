/* This program prints out a conversion table of temperatures, after
   prompting the user for upper and lower bounds of the table in
   Fahrenheit, and the temperature difference between table entries. */ 

#include <iostream>
#include <iomanip>
#include "Program_ex3.h"
using namespace std;

//function definitions

void print_preliminary_message()
{
  cout<<"This program prints out a conversion table of temperatures.Enter the minimum (whole number) temperature you want in the table, in Fahrenheit: 0 Enter the maximum temperature you want in the table: 100 Enter the temperature difference you want between table entries: 20"<<endl;
}

/* FUNCTION TO CONVERT FAHRENHEIT TO CELSIUS */
	double celsius_of(int fahr)
	{
		return (static_cast<double>(5)/9) * (fahr - 32);
	}
	/* END OF FUNCTION */

	/* FUNCTION TO CONVERT FAHRENHEIT TO ABSOLUTE VALUE */
	double absolute_value_of(int fahr)
	{
		return ((static_cast<double>(5)/9) * (fahr - 32)) + 273.15;
	}
/* END OF FUNCTION */



void print_table(int& lower, int& upper, int& step)
{  
   //define variables
    int amount = ((upper - lower)/step) + 1;

   //calculate
      if((upper-lower) % step == 0)
	{
          //steps are even

	  

          //define arrays
          double Fvalue[amount], Cvalue[amount], Avalue[amount];
      

          //set first value to min
          Fvalue[0] = lower;

          //Calculate
          for(int i = 0; i < amount; i++)
	    {
              Cvalue[i] = celsius_of(Fvalue[i]); 
              Avalue[i] = absolute_value_of(Fvalue[i]);
              if(i < (amount - 1))
		{
                  Fvalue[i + 1] = Fvalue[i] + step;
		}
	    }
          //output
          cout.width(15);
	  cout<<left<<"Fahrenheit";
          cout.width(18);
          cout<<left<<"Celsius";
          cout.width(15 + 7);
          cout<<left<<"Absolute Value";
          
          cout<<"\n\n";

	  for(int i = 0; i < amount; i++)
	     {
	       cout.width(15);
               cout<<left<<setprecision(2)<<fixed<<Fvalue[i];
               cout.width(18);
               cout<<left<<setprecision(2)<<fixed<<Cvalue[i];
               cout.width(15 + 7);
               cout<<left<<setprecision(2)<<fixed<<Avalue[i]<<endl;
	     }
	}
      else 
	{
          //steps are uneven
          //define arrays
          double Fvalue[amount + 1], Cvalue[amount + 1], Avalue[amount + 1];
      

          //set first value to min
          Fvalue[0] = lower;

          //Calculate
          for(int i = 0; i < amount; i++)
	    {
              Cvalue[i] = celsius_of(Fvalue[i]); 
              Avalue[i] = absolute_value_of(Fvalue[i]);
              if(i < (amount - 1))
		{
                  Fvalue[i + 1] = Fvalue[i] + step;
		}
	    }
	  //set last value to the max
         
          Fvalue[amount] = upper;
           cout<<"last value : "<<Fvalue[amount]<<endl;
	   Cvalue[amount] = celsius_of(Fvalue[amount]); 
	   Avalue[amount] = absolute_value_of(Fvalue[amount]);

          //output
          cout.width(15);
	  cout<<left<<"Fahrenheit";
          cout.width(18);
          cout<<left<<"Celsius";
          cout.width(15 + 7);
          cout<<left<<"Absolute Value";
          
          cout<<"\n\n";

	  for(int i = 0; i < (amount + 1); i++)
	    {
	       cout.width(15);
               cout<<left<<setprecision(2)<<fixed<<Fvalue[i];
               cout.width(18);
               cout<<left<<setprecision(2)<<fixed<<Cvalue[i];
               cout.width(15 + 7);
               cout<<left<<setprecision(2)<<fixed<<Avalue[i]<<endl;
	    }
	}
      
}

void input_table_specifications(int& lower, int& upper, int& step)
{
  cout<<"enter a max temp: "<<endl;
  cin>>upper;
  cout<<"enter a min temp: "<<endl;
  cin>> lower;
  cout<<"enter a step: "<<endl;
  cin>>step;
  
}

void print_message_echoing_input(int& lower, int& upper, int& step)
{
  cout<<"upper is: "<<upper<<endl;
  cout<<"lower is: "<<lower<<endl;
  cout<<"step is: "<<step<<endl;
}

/* START OF MAIN PROGRAM */
int main() 
{
  int lower = 0; /* the lowest Fahrenheit entry in the table */
  int upper = 0; /* the highest Fahrenheit entry in the table */
  int step = 1;  /* difference in Fahrenheit between entries */

  //define pointers

  /* print a message explaining what the program does: */
  print_preliminary_message();
  
  /* prompt the user for table specifications in Fahrenheit: */
  input_table_specifications(lower, upper, step);
  
  /* print appropriate message including an echo of the input: */
  print_message_echoing_input(lower, upper, step);
  
  /* Print the table (including the column headings): */
  print_table(lower, upper, step);


  return 0;
}

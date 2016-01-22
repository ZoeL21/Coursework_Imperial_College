/* This program prints out a conversion table of temperatures, after
   prompting the user for upper and lower bounds of the table in
   Fahrenheit, and the temperature difference between table entries. */ 

#include <iostream>
#include "conversion.h"
using namespace std;

/* START OF MAIN PROGRAM */
int main() 
{
  int lower = 0; /* the lowest Fahrenheit entry in the table */
  int upper = 0; /* the highest Fahrenheit entry in the table */
  int step = 1;  /* difference in Fahrenheit between entries */

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
/* END OF MAIN PROGRAM */

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

void print_preliminary_message(){
  cout<<"This program prints out a conversion table of temperatures, after";
   cout<<"prompting the user for upper and lower bounds of the table in";
   cout<<"Fahrenheit, and the temperature difference between table entries."<<endl;
}

void input_table_specifications(int& lower, int& upper, int& step){
  cout<<"Please enter values for lower bound, upper bound and step in integers,separated by a space"<<endl;
  cin>>lower>>upper>>step;
}

void print_message_echoing_input(int& lower, int& upper, int& step){
  cout<<"lower: "<<lower<<endl;
  cout<<"upper: "<<upper<<endl;
  cout<<"step: "<<step<<endl;
}

void print_table(int& lower, int& upper, int& step){
 

  print_header();

  for(int i = lower; i < upper;i += step){
  cout.setf(ios::left,ios::adjustfield);
  cout.width(10);
  cout<<" ";
  cout.width(20);
  cout<<i;
  cout.width(20);
  cout<<celsius_of(i);
  cout.width(20);
  cout<<absolute_value_of(i)<<endl;
  }
}

void print_header(){
  cout.setf(ios::left,ios::adjustfield);
  cout.width(10);
  cout<<" ";
  cout.width(20);
  cout<<"Fahrenheit";
  cout.width(20);
  cout<<"Celsius";
  cout.width(20);
  cout<<"Absolute"<<endl<<endl;
}

/* END OF FUNCTION */

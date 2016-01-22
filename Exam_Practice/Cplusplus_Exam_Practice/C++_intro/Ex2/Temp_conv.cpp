#include <iostream>

using namespace std;


//prototypes
double convert_to_Celsius(double value);
double convert_to_Kelvin(double value);

int main(){

  double min = 0;
  double max = 0;
  double step = 0;

  cout<<"This program will convert values in Fahrenheit to Celsius and Kelvin"<<endl;

  cout<<"Give the minimum Fahrenheit value"<<endl;
  cin>>min;
  cout<<"min value is: "<<min<<endl;

  cout<<"Give the maximum Fahrenheit value"<<endl;
  cin>>max;
  cout<<"max value is: "<<max<<endl;

  cout<<"Give the step value"<<endl;
  cin>>step;
  cout<<"step value is: "<<step<<endl;

  
  //display titles
  cout.setf(ios::left, ios::adjustfield);

  cout.width(10);
  cout<<" ";
  cout.width(30);
  cout<<"Fahrenheit";
  cout.width(30);
  cout<<"Celsius";
  cout.width(30);
  cout<<"Kelvin"<<endl<<endl;


  //display conversion for a few values

  for(double i = min; i <= max; i += step){
    cout.width(10);
    cout<<" ";
    cout.width(30);
    cout<<i;
    cout.width(30);
    cout<<convert_to_Celsius(i);
    cout.width(30);
    cout<<convert_to_Kelvin(convert_to_Celsius(i))<<endl;
  }

  return(0);
}


double convert_to_Celsius(double value){
  return (value - 32)*5.0/9.0;
}

double convert_to_Kelvin(double value){
  return (value + 273.15);
}



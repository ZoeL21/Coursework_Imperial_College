#include <iostream>
using namespace std;

int main()
{
  int year_now, age_now, another_year, another_age;
  int month_now, another_month, born_month;

  cout<<"enter the current year then press return. \n";
  cin>> year_now;

  cout<<"enter the current month then press return. \n";
  cin>> month_now;

  cout<< "enter your current age in years. \n";
  cin>>age_now;

  cout<< "enter the month in which you were born. \n";
  cin>>born_month;

  cout<< "enter the year for which you wish to know your age. \n";
  cin>>another_year;

  cout<< "enter the month for which you wish to kow your age. \n";  
  cin>>another_month;

  int temp_current_age = age_now*12 + (month_now - born_month);   
  int another_age_temp = (another_year*12 + another_month) - (year_now*12 + month_now) + temp_current_age;

  int months = another_age_temp % 12;
  another_age = another_age_temp/12;

  //define output variables
  std::string month_calc = "months";
  
  std::string year_calc = "years";
  

  if(months == 1)
    {
      month_calc = ("month");
    }
  
   if(another_age == 1)
    {
      year_calc = ("year");
    }
  

  //output information
  if(another_age >= 0)
    {
      if(another_age >= 150)
	{
	  cout<< "I'm sorry, you will probably be dead by this year. \n";
	}
      else
	{
          cout<< "Your age in " <<another_month<<" / "<<another_year<< ": "<<another_age<<" "<<year_calc<< " and "<<months<<" "<<month_calc<< "!\n";
	}
    }
  else
    {
      cout<< " You were not even born in year "<<another_year<< " \n";
    }
  return 0;
}
    
       
  

#include <iostream>
using namespace std;

enum Day {Sun, Mon, Tue, Wed, Thu, Fri, Sat};

int closing_time(Day day_of_the_week);
void print_day(Day day, ostream& os);

/* MAIN PROGRAM */
int main()
{
  int count;
  
  cout.setf(ios::left);
  /* Print table heading */
  cout.width(17);
  cout << "DAY";
  cout << "CLOSING TIME\n\n";
  
  /* Print table from Sunday to Saturday */
  for (count = static_cast<int>(Sun) ; count <= static_cast<int>(Sat) ; count++)
    {
      cout.width(19);
      print_day(static_cast<Day>(count),cout);
      cout << closing_time(static_cast<Day>(count)) << "pm\n";
    }
  
  return 0;
}
/* END OF MAIN PROGRAM */

/* FUNCTION TO GENERATE SHOP CLOSING TIMES FROM DAY OF THE WEEK */
int closing_time(Day day_of_the_week)
{
  switch(day_of_the_week){
  case 0: return 1; break;
  case 1: return 6; break;
  case 2: return 6; break;
  case 3: return 8; break;
  case 4: return 6; break;
  case 5: return 6; break;
  case 6: return 5; break;
  default: return 13;
  }
}

void print_day(Day day, ostream& os){
  switch(day){
  case Sun: os << "Sunday";break;
  case Mon: os << "Monday";break;
  case Tue: os << "Tuesday"; break;
  case Wed: os << "Wednesday"; break;
  case Thu: os << "Thursday"; break;
  case Fri: os << "Friday"; break;
  case Sat: os << "Saturday"; break;
  default: os << "Error";
  }
}

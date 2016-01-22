#include <iostream>

using namespace std;

int main()
{
  //define variables
  char c;

  //get character from user
  cin>>c;
  if(!isalpha(c))
    {
      cout<<"input is not a character"<<endl;
    }
  else if((static_cast<int>(c)) > 64 && (static_cast<int>(c) < 91))
    {
      //character is Capital
      int temp = static_cast<int>(c) + 32;
      cout<<"The lowercase letter of: "<<c<<" is: "<<static_cast<char>(temp)<<endl;
    }
  else
    {
      int temp = static_cast<int>(c) - 32;
      cout<<"The uppercase letter of: "<<c<<" is: "<<static_cast<char>(temp)<<endl;
    }


  return 0;
}

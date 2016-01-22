#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
  /*declare variable to count characters and to read in from file*/
  int count = 0;
  char c;
  
  /*create streams*/
  ifstream in_stream;


  /*open in_stream*/
  in_stream.open("Countchar_copy.cpp");

    /*check if opened correctly*/
    if(in_stream.fail())
      {
	cout<<"Error"<<endl;
	exit(1);
      }

  /*count characters in file*/
  in_stream.get(c);
  while(!in_stream.eof())
      {
        count++;
	in_stream.get(c);
      }
  /*declare character count*/
  cout<<"characters: "<<count<<endl;

  return 0;
}

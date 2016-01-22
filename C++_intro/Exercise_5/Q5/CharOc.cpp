#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
  /*declare variables*/
  char c; int Oc = 0;

  /*declare filestream*/
  ifstream in_stream;


    /*print out title*/
    cout.setf(ios::left);
    cout.width(17);
    cout<<"CHARACTEER";
    cout<<"OCCURRENCE"<<endl;

    int i = static_cast<int>('a'); //cout<<i<<endl;
    int j = static_cast<int>('z'); //cout<<j<<endl;

    /*read in characters and increase occurrence*/
    for(; i < (j + 1); i++)
      {
        /*read in from file*/
        in_stream.open("CharOc_copy.cpp");

	/*check if opened correctly*/
	if(in_stream.fail())
	  {
	    cout<<"Error"<<endl;
	    exit(1);
	  }

        /*traverse file*/
        in_stream.get(c);
        while(!in_stream.eof())
            {
	      //int ca = static_cast<char>(i);
	      //cout<<"ca: "<<ca<<endl;
              //check if wanted alphabetical character*/
	      if(c == static_cast<char>(i))
		{
		  Oc++;
		}
	      in_stream.get(c);
	    }

	/*print out Occurrence*/
	cout.width(17);
	cout<<static_cast<char>(i);
	cout<<Oc<<endl;

	/*close infile*/
	in_stream.close();

	/*reset occurence*/
	Oc = 0;
      }


  return 0;
}

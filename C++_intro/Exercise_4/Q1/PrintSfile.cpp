#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
  //declaring instream
  ifstream in_stream;
  

  //connect them to this file and to cout
  in_stream.open("PrintSfile_copy.cpp");

  //check for failure
  if(in_stream.fail())
    {
      cout<<"Error"<<endl;
      exit(1);
    }

  //declare character buffer to read in character from source_file
  char character;

  //read into buffer and print to screen
  in_stream.get(character);
  for(in_stream.get(character);!in_stream.eof(); in_stream.get(character))
    {
      //if(!(alphanum(character))
      cout<<character;
    }

  //close filestream
  in_stream.close();

  return 0;
}

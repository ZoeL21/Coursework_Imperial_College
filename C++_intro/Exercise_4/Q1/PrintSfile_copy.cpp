#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  //declaring instream
  ifstream in_stream;
  

  //connect them to this file and to cout
  in_stream.open("printSfile_copy.cpp");
  
  //declare character buffer to read in character from source_file
  char character;

  //read into buffer and print to screen
  in_stream.get(character);
  for(in_stream.get(character);!in_stream.eof(); in_stream.get(character))
    {
      //if(!(alphanum(character))
      cout<<character;
    }

  return 0;
}

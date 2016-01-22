#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
  /*output*/
  cout<<"Testing: " << 16/2 <<" = "<< 4 * 2 << ".\n\n";

  /*declaring output and input streams*/
  ifstream in_stream;
  ofstream out_stream;

  /*declaring character*/
  char c; 

  /*open streams*/
  in_stream.open("WithComments_copy.cpp");
  out_stream.open("WithoutComments.cpp");

  /*check if opened successfully*/
  if(in_stream.fail())
    {
      cout<<"Error infile"<<endl;
      exit(1);
    }
  if(out_stream.fail())
    {
      cout<<"Error outfile"<<endl;
      exit(1);
    }

  /*reading from in_stream, writing to screen and to output file*/
  for(in_stream.get(c); !in_stream.eof(); in_stream.get(c))
    {
       

      /*detecting comments*/
      if(c == '/' && in_stream.peek() == '*')
	{
	      in_stream.get(c);
              /*do not output while inside comments*/
	      while(!((c == '*') && (in_stream.peek() == '/')))
		{
		   in_stream.get(c);
		}
	      in_stream.get(c);
	    
       }
      else
	{
   

         /*output to screen*/
         cout<<c;

         /*output to file*/
         out_stream.put(c);
	}
    }
  /*closing files*/
  in_stream.close();
  out_stream.close();

  return 0;

}

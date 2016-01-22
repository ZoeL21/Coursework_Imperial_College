#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
  
  cout<<"Testing: " << 16/2 <<" = "<< 4 * 2 << ".\n\n";

  
  ifstream in_stream;
  ofstream out_stream;

  
  char c; 

  
  in_stream.open("WithComments_copy.cpp");
  out_stream.open("WithoutComments.cpp");

  
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

  
  for(in_stream.get(c); !in_stream.eof(); in_stream.get(c))
    {
       

      
      if(c == '/' && in_stream.peek() == '*')
	{
	      in_stream.get(c);
              
	      while(!((c == '*') && (in_stream.peek() == '/')))
		{
		   in_stream.get(c);
		}
	      in_stream.get(c);
	    
       }
      else
	{
   

         
         cout<<c;

         
         out_stream.put(c);
	}
    }
  
  in_stream.close();
  out_stream.close();

  return 0;

}

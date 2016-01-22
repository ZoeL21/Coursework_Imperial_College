#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{

  /*count characters of program*/
  int count = 0; char c;

  ifstream in_stream;

  in_stream.open("Backwards_copy.cpp");

  if(in_stream.fail())
    {
      cout<<"Error"<<endl;
      exit(1);
    }
  in_stream.get(c);
  while(!in_stream.eof())
    {
      count++;
     in_stream.get(c);
    }

  in_stream.close();

  cout << "Count done!" <<count<< endl << endl;
  

  /*open an instream, read and ignore all characters until the last one and 
    continue doing so until the first character*/
  for(int i = count; i > 0; i--)
    {
      /*open instream*/
      in_stream.open("Backwards_copy.cpp");
      if(in_stream.fail())
	{
	  cout<<"Error"<<endl;
	  exit(1);
	}
      /*traverse file until ith character reached*/
      int charcount = 0;
      in_stream.get(c);
      while(charcount < i)
	{
	  charcount++;
	  in_stream.get(c);
	}

      /*when ith character has been reached, output character*/
      /*if(c==13) {
	cout << endl;
      } else {
        cout<< (int) c;
      }*/
      cout<<c;

      /*close instream*/
      in_stream.close();
    }

  return 0;
}

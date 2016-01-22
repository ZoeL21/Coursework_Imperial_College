#include <fstream>

using namespace std;

int main(){

  /*create streams*/
  ifstream in;
  ofstream out;

  /*open files*/
  in.open("print_me_tofile.cpp");
  out.open("printed_to_file_without_comments.cpp");

  /*char buffer*/
  char c;

  /*read from and to files*/
  while(!in.eof()){
    in.get(c);
    if(c == '/' && in.peek() == '*'){
      while(!(c == '*' && in.peek() == '/') && !in.eof()){
	in.get(c);
      }
      /*jump * and /*/
      in.get(c);
      in.get(c);
    }
    /*otherwise write to file*/
    out.put(c);
  }

  /*close streams*/
  in.close();
  out.close();

  return(0);
}

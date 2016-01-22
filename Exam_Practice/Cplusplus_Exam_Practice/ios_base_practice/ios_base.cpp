#include <iostream>


using namespace std;

int main(){

  //create variables
  int ex_int = 100;
  double ex_dou = 4.6786;
  double ex_dou2 = 5.897456;
  double ex_dou3 = 3.5673;  


  //outputting in various formats
  
  cout<<"SIMPLE"<<endl<<endl;
  //simple:
  cout<<ex_int<<endl;
  cout<<ex_dou<<endl;
  cout<<ex_dou2<<endl;
  cout<<ex_dou3<<endl;
  cout<<endl;

  //save original precision
  streamsize ss = cout.precision();

  cout<<"SETTING PRECISION TO 3"<<endl<<endl;
  //new precision
  cout.precision(3);
  cout<<ex_int<<endl;
  cout<<ex_dou<<endl;
  cout<<ex_dou2<<endl;
  cout<<ex_dou3<<endl;
  cout<<endl;


  cout<<"FIXING PRECISION simple"<<endl<<endl;
  //fixed, simple
  cout<<fixed<<ex_dou<<endl;
  cout<<ex_dou2<<endl;
  cout<<ex_dou2<<endl;
  cout<<ex_dou3<<endl;
  cout<<endl;

  cout<<"FIXING PRECISION permanently"<<endl<<endl;
  //fixed using setf
  cout.setf(ios::fixed, ios::floatfield);
  cout<<ex_dou<<endl;
  cout<<ex_dou2<<endl;
  cout<<ex_dou3<<endl;
  cout<<endl;

  cout<<"SCIENTIFIC"<<endl;
  cout.setf(ios::scientific, ios::floatfield);
  cout<<ex_dou<<endl;
  cout<<ex_dou2<<endl;
  cout<<ex_dou3<<endl;
  cout<<endl;

  cout<<"UNSETTING PRECISION"<<endl<<endl;
  //reset
  cout.unsetf(ios::floatfield);
  cout<<ex_dou<<endl;
  cout<<ex_dou2<<endl;
  cout<<ex_dou3<<endl;
  cout<<endl;

  cout<<"SCIENTIFIC"<<endl;
  cout.setf(ios::scientific, ios::floatfield);
  cout<<ex_dou<<endl;
  cout<<ex_dou2<<endl;
  cout<<ex_dou3<<endl;
  cout<<endl;


  cout<<"CHANGING BASE"<<endl<<endl;
  //changing base
  cout.setf(ios::hex, ios::basefield);
  cout<<ex_int<<endl;

  //don't show the base
  cout.setf(ios::showbase);
  cout<<ex_int<<endl;

  //unset the base
  cout.unsetf(ios::basefield);
  cout<<ex_int<<endl;
  cout<<endl;

  cout<<"ADJUSTFIELD and UNDOING FIXED\n"<<endl<<endl;
  //using the adjustfield and undoing fixed
  cout.unsetf(ios::floatfield);
  cout.setf(ios::left, ios::adjustfield);

  cout.width(10);
  cout<<ex_int;
  cout.width(10);
  cout<<ex_dou;
  cout.width(10);
  cout<<ex_dou2;
  cout.width(10);
  cout<<ex_dou3<<endl;

  cout.setf(ios::right, ios::adjustfield);
  
  cout.width(10);
  cout<<ex_int;
  cout.width(10);
  cout<<ex_dou;
  cout.width(10);
  cout<<ex_dou2;
  cout.width(10);
  cout<<ex_dou3<<endl;
  cout<<endl;


  cout<<"OLD PRECISION, UNDOING ADJUSTFIELD and MANUAL ADJUSTING"<<endl<<endl;

  //old precision,fixed
  cout.precision(ss);
  cout.setf(ios::fixed, ios::floatfield);

  //undoing the adjustfield
  cout.unsetf(ios::adjustfield);  

  cout.width(10);
  cout<<left<<ex_int;
  cout.width(20);
  cout<<ex_dou;
  cout.width(20);
  cout<<right<<ex_dou2;
  cout.width(20);
  cout<<ex_dou3<<endl;



  return(0);
}


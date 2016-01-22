#include <iostream>
#include "Matrix.h"


using namespace std;

int main()
{
  //define Matrices
  int Matrix1[m][n];
  int Matrix2[n][r];
  int Matrix_new[x][y];

  cout<<"input first ("<<m<<"x"<<n<<") Matrix."<<endl;
  cout<<"Type in"<<m*n<<" values for Matrix1 "<<endl;
  
  for(int row = 0; row < m; row++)
    for(int col = 0; col < n; col++)
      {
        cin>>Matrix1[row][col];
      }

  cout<<"input second ("<<n<<"x"<<r<<") Matrix."<<endl;
  cout<<"Type in"<<n*r<<" values for Matrix1 "<<endl;
  
  for(int row = 0; row < n; row++)
    for(int col = 0; col < r; col++)
      {
        cin>>Matrix2[row][col];
      }

  //print out Matrix1 

  print_out(Matrix1, m);

  cout<<"TIMES"<<endl;

  //print out Matrix2
  // print_out(Matrix2, n);

  cout<<"EQUALS"<<endl;

  //function call
  multiply_Matrices(Matrix_new,Matrix1,Matrix2,m);

  print_result(Matrix_new, x);

  return 0;
}

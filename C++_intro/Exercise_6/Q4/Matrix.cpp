#include "Matrix.h"
#include <iostream>

using namespace std;

//function definitions

/*FUNCTION TO MULTIPLY 2 MATRICES*/
void multiply_Matrices(int Matrix_new[][y], int Matrix1[][n], int Matrix2[][r], int rows1)
{
  
  for(int i = 0; i < rows1; i++)
    {
      for(int k = 0;k < r; k++)
	{
	  int temp = 0; 
          for(int j = 0; j < n; j++)
	    {
	      temp = temp + (Matrix1[i][j] * Matrix2[j][k]);
	    }
            Matrix_new[i][k] = temp;
	}
    }
}

/*FUNCTION TO PRINT OUT A MATRIX1*/
void print_out(int Matrix1[][n], int row_length)
{

 for(int row = 0; row < row_length; row++)
    {
      cout.width(8);
      cout<<" ";
    for(int col = 0; col < n; col++)
      {
	cout.width(3);
	cout<<left<<Matrix1[row][col];
      }
      cout<<endl;
    }

}

/*FUNCTION TO PRINT OUT RESULTING MATRIX*/
void print_result(int Matrix_new[][y],int row_length)
{
  for(int row = 0; row < row_length; row++)
    {
      cout.width(8);
      cout<<" ";
      for(int col = 0; col < y; col++)
	{
	  cout.width(3);
	  cout<<left<<Matrix_new[row][col];
	}
      cout<<endl;
    }
}

#include "matrix.h"
#include <iostream>

using namespace std;

int main(){

  int matrix1[m][n];

  cout<<"Fill the matrix with values: "<<endl;
  for(int i = 0; i < m; i++){
    cout<<" **** ROW "<<i<<" ***"<<endl;
    for(int j = 0;j < n; j++){
      cout<<"Column "<<j;
      cin>>matrix1[i][j];
    }
  }

  //array to save the content of the first matrix
  int matrix2[n][k];

  cout<<"Fill the matrix with values: "<<endl;
  for(int i = 0; i < n; i++){
    cout<<" **** ROW "<<i<<" ***"<<endl;
    for(int j = 0;j < k; j++){
      cout<<"Column "<<j;
      cin>>matrix2[i][j];
    }
  }
  int matrix3[m][k];
  multiply_mat(matrix1,m, matrix2, matrix3);
  display_matrix(matrix1,n);
  cout<<"times: :"<<endl;
  display_matrix(matrix2,k);
  cout<<"is: "<<endl;
  display_matrix(matrix3,m);
  return(0);
}

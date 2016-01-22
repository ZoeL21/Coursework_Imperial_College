#include "matrix.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void display_matrix(int matrix[][k],int m){
  for(int i = 0; i < m; i++){
    cout.width(10);
    for(int j = 0; j < k; j++){
      cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
  }
}

void display_matrix(int matrix[][m], int n){
  for(int i = 0; i < n; i++){
    cout.width(10);
    for(int j = 0; j < m; j++){
      cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
  }
}

void display_matrix(int matrix[][n], int m){
  for(int i = 0; i < m; i++){
    cout.width(10);
    for(int j = 0; j < n; j++){
      cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
  }
}



void multiply_mat(int matrix1[][n],int m,int matrix2[][k],int matrix3[][k]){

  for(int l = 0; l < m;l++){
    //multiply rows by columns
    for(int i = 0; i < k; i++){
      int temp = 0;
      for(int j = 0; j < n;j++){
	temp += matrix1[l][j] * matrix2[j][i];
      }
      cout<<temp<<" ";
      matrix3[l][i] = temp;
    }
    cout<<endl;
  }
} 
    
    

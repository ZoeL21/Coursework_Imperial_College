#ifndef MATRIX_H
#define MATRIX_H

//global variables
const int k = 3;
const int m = 4;
const int n = 2; 

void  multiply_mat(int matrix1[][n], int m, int matrix2[][k], int matrix3[][k]);

void display_matrix(int matrix[][k], int m);
void display_matrix(int matrix[][m], int n);
void display_matrix(int matrix[][n], int m);


#endif

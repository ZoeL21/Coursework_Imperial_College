#ifndef MATRIX_H
#define MATRIX_H

//global variables
const int m = 2;
const int n = 2;
const int r = 2;

const int x = 2;
const int y = 2;

//function declarations

/*FUNCTION TO MULTIPLY 2 MATRICES*/
void multiply_Matrices(int Matrix_new[][y], int Matrix1[] [n], int Matrix2[] [r], int rows1);

/*FUNCTION TO PRINT OUT A MATRIX*/
void print_out(int Matrix1[][n], int row_length);

/*FUNCTION TO PRINT OUT RESULTING MATRIX*/
void print_result(int Matrix_new[][y], int row_length);

#endif

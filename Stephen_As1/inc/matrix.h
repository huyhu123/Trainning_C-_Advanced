#include <stdio.h>
#include <stdlib.h>

void get_matrix_data(int **matrix, int rows, int collums);

void print_matrix(int **matrix, int rows, int collums);

int **sum_matrix(int **matrix_a, int matrix_a_row, int matrix_a_col, int **matrix_b, int matrix_b_row, int matrix_b_col);

int **product_matrix(int **matrix_a, int matrix_a_row, int matrix_a_col, int **matrix_b, int matrix_b_row, int matrix_b_col);
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int m_row;
    int m_column;
	int **m_data;
} matrix_t;

void get_matrix_data(matrix_t *matrix);

void print_matrix(matrix_t *matrix);

matrix_t *sum_matrix(matrix_t *matrix_a, matrix_t *matrix_b);

matrix_t *product_matrix(matrix_t *matrix_a, matrix_t *matrix_b);

void free_matrix(matrix_t *matrix);
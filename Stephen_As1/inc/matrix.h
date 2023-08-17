#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int m_row;
    int m_column;
	int **m_data;
} matrix_t;

/*!
* @brief <Take input matrix from the keyboard>
*
* @param *p_matrix [In/Out] <pointer point to struct matrix_t of the matrix>
*
*return None
*/
void get_matrix_data(matrix_t *p_matrix);

/*!
* @brief <Print the matrix to the terminal>
*
* @param *p_matrix [In] <pointer point to struct matrix_t of the matrix>
*
*return None
*/
void print_matrix(matrix_t *p_matrix);

/*!
* @brief <Calculate the sum of two matrices>
*
* @param *p_matrix_a [In] <pointer point to struct matrix_t of the first matrix>
*
* @param *p_matrix_b [In] <pointer point to struct matrix_t of the seccond matrix>
*
*return *sum_matrix <pointer point to struct matrix_t of the sum of 2 matrix>
*/
matrix_t *sum_matrix(matrix_t *p_matrix_a, matrix_t *p_matrix_b);

/*!
* @brief <Calculate the sum of two matrices>
*
* @param *p_matrix_a [In] <pointer point to struct matrix_t of the first matrix>
*
* @param *p_matrix_b [In] <pointer point to struct matrix_t of the seccond matrix>
*
*return *product_matrix <pointer point to struct matrix_t of the product of 2 matrix>
*/
matrix_t *product_matrix(matrix_t *p_matrix_a, matrix_t *p_matrix_b);

/*!
* @brief <Free matrix allocated memory>
*
* @param *p_matrix [In] <pointer point to struct matrix_t of the matrix>
*
*return None
*/
void free_matrix(matrix_t *p_matrix);
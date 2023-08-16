#include "matrix.h"

int main()
{
    matrix_t *matrix_a = malloc(sizeof(size_t));
    matrix_t *matrix_b = malloc(sizeof(size_t));

    //Get matrix data
    printf("Input matrix A\n");
    get_matrix_data(matrix_a);
    printf("Input matrix B\n");
    get_matrix_data(matrix_b);

    //Print matrix
    printf("Matrix A:\n");
    print_matrix(matrix_a);
    printf("Matrix B:\n");
    print_matrix(matrix_b);

    //Calculate and print sum of 2 matrix
    matrix_t *sum = sum_matrix(matrix_a, matrix_b);
    if(sum != NULL)
    {
        printf("Matrix A + Matrix B:\n");
        print_matrix(sum);
    }
    else
    {
        printf("Matrix A, Matrix B cant add together\n");
    }

    //Calculate and print product of 2 matrix
    matrix_t *product = product_matrix(matrix_a, matrix_b);
    if(product != NULL)
    {
        printf("Matrix A * Matrix B:\n");
        print_matrix(product);
    }
    else
    {
        printf("Matrix A, Matrix B cant multi together\n");
    }

    //Free allocated memory
    free_matrix(matrix_a);
    free_matrix(matrix_b);
    if(sum != NULL)
    {
        free_matrix(sum);
    }
    if(product != NULL)
    {
        free_matrix(product);
    }
    
    return 0;
}
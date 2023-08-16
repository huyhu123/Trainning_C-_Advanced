#include "matrix.h"

int main()
{
    int matrix_a_row, matrix_a_col, matrix_b_row, matrix_b_col = 0;

    //Get matrix a size
    printf("Matrix A Row: ");
    scanf("%i", &matrix_a_row);
    printf("Matrix A Col: ");
    scanf("%i", &matrix_a_col);

    printf("Matrix B Row: ");
    scanf("%i", &matrix_b_row);
    printf("Matrix B Col: ");
    scanf("%i", &matrix_b_col);

    //Allocate memory for matrix 
    int **matrix_a = (int **)malloc(matrix_a_row * sizeof(int *));
    for (int i = 0; i < matrix_a_row; i++) 
    {
        matrix_a[i] = (int *)malloc(matrix_a_col * sizeof(int));
    }

    int **matrix_b = (int **)malloc(matrix_b_row * sizeof(int *));
    for (int i = 0; i < matrix_b_row; i++) 
    {
        matrix_b[i] = (int *)malloc(matrix_b_col * sizeof(int));
    }

    //Get matrix data
    printf("Input matrix A:\n");
    get_matrix_data(matrix_a, matrix_a_row, matrix_a_col);
    printf("Input matrix B:\n");
    get_matrix_data(matrix_b, matrix_b_row, matrix_b_col);

    //Print matrix
    printf("Matrix A:\n");
    print_matrix(matrix_a, matrix_a_row, matrix_a_col);
    printf("Matrix B:\n");
    print_matrix(matrix_b, matrix_b_row, matrix_b_col);

    //Calculate and print sum matrix
    int **sum = sum_matrix(matrix_a, matrix_a_row, matrix_a_col, matrix_b, matrix_b_row, matrix_b_col);
    if(sum != NULL)
    {
        printf("Matrix A + Matrix B:\n");
        print_matrix(sum, matrix_a_row, matrix_a_col);
    }
    else
    {
        printf("Matrix A, Matrix B cant add together\n");
    }

    //Calculate and print matrix multification
    int **product = product_matrix(matrix_a, matrix_a_row, matrix_a_col, matrix_b, matrix_b_row, matrix_b_col);
    if(product != NULL)
    {
        printf("Matrix A * Matrix B:\n");
        print_matrix(product, matrix_a_row, matrix_b_col);
    }
    else
    {
        printf("Matrix A, Matrix B cant multi together\n");
    }

    //Free allocated memory
    for (int i = 0; i < matrix_a_row; i++) 
    {
        free(matrix_a[i]);
    }
    free(matrix_a);
    
    for (int i = 0; i < matrix_b_row; i++) 
    {
        free(matrix_b[i]);
    }
    free(matrix_b);

    if(sum != NULL)
    {
        for (int i = 0; i < matrix_a_row; i++) 
        {
            free(sum[i]);
        }
        free(sum);
    }
    
    if(product != NULL)
    {
        for (int i = 0; i < matrix_a_row; i++) 
        {
            free(product[i]);
        }
        free(product);
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Function to take input matrix from the keyboard test
void get_matrix_data(int **matrix, int rows, int collums)
{
    for(int row = 0; row < rows; row++)
    {
        for(int collum = 0 ; collum < collums ; collum++)
        {
            scanf("%i", &matrix[row][collum]);
        }
    }
}

// Function to print matrix
void print_matrix(int **matrix, int rows, int collums)
{
    for(int row = 0 ; row < rows ; row++)
    {
        for(int collum = 0; collum < collums; collum++)
        {
            printf("%10i", matrix[row][collum]);
        }
        printf("\n");
    }
}

// Function to calculate the sum of two matrices
int **sum_matrix(int **matrix_a, int matrix_a_row, int matrix_a_col, int **matrix_b, int matrix_b_row, int matrix_b_col)
{
    if(matrix_a_row != matrix_b_row || matrix_a_col != matrix_b_col)
    {
        return NULL;
    }
    
    int **matrix_sum = (int **)malloc(matrix_a_row * sizeof(int *));
    for (int i = 0; i < matrix_a_row; i++) 
    {
        matrix_sum[i] = (int *)malloc(matrix_a_col * sizeof(int));
    }

    for(int row = 0 ; row < matrix_a_row; row++)
    {
        for(int collum = 0; collum < matrix_a_col; collum++)
        {
            matrix_sum[row][collum] = matrix_a[row][collum] + matrix_b[row][collum];
        }
    }
    
    return matrix_sum;
}

// Function to calculate the product of two matrices
int **product_matrix(int **matrix_a, int matrix_a_row, int matrix_a_col, int **matrix_b, int matrix_b_row, int matrix_b_col)
{
    if(matrix_a_col != matrix_b_row)
    {
        return NULL;
    }
    
    int **product = (int **)malloc(matrix_a_row * sizeof(int *));
    for (int i = 0; i < matrix_a_row; i++) {
        product[i] = (int *)malloc(matrix_b_col * sizeof(int));
    }
    
    for (int i = 0; i < matrix_a_row; i++) {
        for (int j = 0; j < matrix_b_col; j++) {
            product[i][j] = 0;
            for (int k = 0; k < matrix_a_col; k++) {
                product[i][j] += matrix_a[i][k] * matrix_b[k][j];
            }
        }
    }
    
    return product;
}

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

    //Calculate and print sum of 2 matrix
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

    //Calculate and print product of 2 matrix
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
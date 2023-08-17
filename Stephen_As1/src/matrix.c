#include "matrix.h"

static bool check_matrix_can_add(matrix_t *p_matrix_a, matrix_t *p_matrix_b)
{
    if(p_matrix_a->m_row != p_matrix_b->m_row || p_matrix_a->m_column != p_matrix_b->m_column)
    {
        return false;
    }
    return true;
}

static bool check_matrix_can_multiply(matrix_t *p_matrix_a, matrix_t *p_matrix_b)
{
    if(p_matrix_a->m_column != p_matrix_b->m_row)
    {
        return false;
    }
    return true;
}

static int get_input_int() {
    int return_value = 0;

    while(return_value <= 0)
    {
        while (scanf("%i", &return_value) != 1)
        {
            while(getchar() != '\n');
        }
    }
    
    return return_value;
}

static float get_input_float() {
    float return_value = 0;

    while (scanf("%f", &return_value) != 1)
    {
        printf("Not int\n");
        while(getchar() != '\n');
    }
    
    return return_value;
}

/*FUNCTION===================================================================================
*   Function Name : initialize_matrix
*   Description   : Allocate memory for matrix 
============================================================================================*/
matrix_t *initialize_matrix()
{
   return malloc(sizeof(matrix_t));
}

/*FUNCTION===================================================================================
*   Function Name : get_matrix_data
*   Description   : Take input matrix from the keyboard
============================================================================================*/
void get_matrix_data(matrix_t *p_matrix)
{
    //Get matrix a size
    printf("Matrix Row: ");
    p_matrix->m_row = get_input_int();
    printf("Matrix Col: ");
    p_matrix->m_column = get_input_int();

    //Allocate memory for matrix 
    p_matrix->m_data = (float **)malloc(p_matrix->m_row * sizeof(float *));
    for (int i = 0; i < p_matrix->m_row; i++) 
    {
        p_matrix->m_data[i] = (float *)malloc(p_matrix->m_column * sizeof(float));
    }

    //Take input matrix from the keyboard
    printf("Input matrix:\n");
    for(int row = 0; row < p_matrix->m_row; row++)
    {
        for(int collum = 0 ; collum < p_matrix->m_column ; collum++)
        {
            p_matrix->m_data[row][collum] = get_input_float();
        }
    }
}

/*FUNCTION===================================================================================
*   Function Name : print_matrix
*   Description   : Print the matrix to the terminal
============================================================================================*/
void print_matrix(matrix_t *p_matrix)
{
    for(int row = 0 ; row < p_matrix->m_row ; row++)
    {
        for(int collum = 0; collum < p_matrix->m_column; collum++)
        {
            printf("%10f", p_matrix->m_data[row][collum]);
        }
        printf("\n");
    }
}

/*FUNCTION===================================================================================
*   Function Name : sum_matrix
*   Description   : Calculate the sum of two matrices
============================================================================================*/
matrix_t *sum_matrix(matrix_t *p_matrix_a, matrix_t *p_matrix_b)
{
    if(!check_matrix_can_add(p_matrix_a, p_matrix_b))
    {
        return NULL;
    }
    
    matrix_t *p_matrix_sum = malloc(sizeof(matrix_t)); 
    p_matrix_sum->m_row = p_matrix_a->m_row;
    p_matrix_sum->m_column = p_matrix_a->m_column;
    p_matrix_sum->m_data = (float **)malloc(p_matrix_sum->m_row * sizeof(float *));
    for (int i = 0; i < p_matrix_sum->m_row; i++) 
    {
        p_matrix_sum->m_data[i] = (float *)malloc(p_matrix_sum->m_column * sizeof(float));
    }

    for(int row = 0 ; row < p_matrix_sum->m_row; row++)
    {
        for(int collum = 0; collum < p_matrix_sum->m_column; collum++)
        {
            p_matrix_sum->m_data[row][collum] = p_matrix_a->m_data[row][collum] + p_matrix_b->m_data[row][collum];
        }
    }
    
    return p_matrix_sum;
}

/*FUNCTION===================================================================================
*   Function Name : multiply_matrix
*   Description   : Calculate the product of two matrices
============================================================================================*/
matrix_t *multiply_matrix(matrix_t *p_matrix_a, matrix_t *p_matrix_b)
{
    if(!check_matrix_can_multiply(p_matrix_a, p_matrix_b))
    {
        return NULL;
    }
    
    matrix_t *p_matrix_product = malloc(sizeof(matrix_t)); 
    p_matrix_product->m_row = p_matrix_a->m_row;
    p_matrix_product->m_column = p_matrix_b->m_column;

    p_matrix_product->m_data = (float **)malloc(p_matrix_a->m_row * sizeof(float *));
    for (int i = 0; i < p_matrix_a->m_row; i++) {
        p_matrix_product->m_data[i] = (float *)malloc(p_matrix_b->m_column * sizeof(float));
    }
    
    for (int i = 0; i < p_matrix_a->m_row; i++) {
        for (int j = 0; j < p_matrix_b->m_column; j++) {
            p_matrix_product->m_data[i][j] = 0;
            for (int k = 0; k < p_matrix_a->m_column; k++) {
                p_matrix_product->m_data[i][j] += p_matrix_a->m_data[i][k] * p_matrix_b->m_data[k][j];
            }
        }
    }
    
    return p_matrix_product;
}

/*FUNCTION===================================================================================
*   Function Name : free_matrix
*   Description   : Free matrix allocated memory
============================================================================================*/
void free_matrix(int count, ...)
{
    va_list list;
    va_start(list, count); 

    //Loop through list of matrix
    for(int i = 0; i < count; i++)
    {
        matrix_t *p_matrix = va_arg(list, matrix_t *);
        if(p_matrix == NULL)
        {
            return;
        }

        for (int j = 0; j < p_matrix->m_row; j++) 
        {
            free(p_matrix->m_data[j]);
        }
        free(p_matrix->m_data);
        free(p_matrix);

        p_matrix = NULL;
    }
}


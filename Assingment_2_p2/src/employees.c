#include <employees.h>

static int Clean_stdin()
{
    while (getchar() != '\n');
    return 1;
}

static int Get_input_size() 
{
    int input;
    unsigned int i =0;
    char c;

    while ((scanf("%d", &input) != 1 || input < 1 || input >50) && Clean_stdin()) {
        printf("\n*Warning:Failed! Please enter an interger between 0 and 50.\nEnter again:  ");
    }
    Clean_stdin();
    
    return input;
}

static float Get_input_float()
{
    float input;

    while ((scanf("%f", &input) != 1 || input < 0) && Clean_stdin()) {
        printf("\n*Warning:Failed! Please enter an positive real number.\nEnter again:  ");
    }
    Clean_stdin();

    return input;
}

static int Get_input_int() 
{
    int input;

    while ((scanf("%d", &input) != 1 || input < 0) && Clean_stdin()) {
        printf("\n*Warning:Failed! Please enter an interger.\nEnter again:  ");
    }
    Clean_stdin();

    return input;
}

static char *Get_input_char() 
{
    char *input = malloc(MAX_STRING);

    fgets(input, MAX_STRING, stdin);
    
    return input;
}

void get_employee_num(int *size)
{
    *size = Get_input_size();
}

void get_employee_data(employee_t *employee)
{
    printf("Enter employee id: ");
    employee->id = Get_input_int();

    printf("Enter employee full name: ");
    employee->full_name = Get_input_char();
    printf("%s\n", employee->full_name);

    printf("Enter employee department: ");
    employee->department = Get_input_char();
    printf("%s\n", employee->department);

    printf("Enter employee salary: ");
    employee->salary = Get_input_float();
    printf("%f\n", employee->salary);
}
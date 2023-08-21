#include <employees.h>

static int Clean_stdin()
{
    while (getchar() != '\n');
    return 1;
}

static int Get_input_size() 
{
    float input;

    while ((scanf("%d", &input) != 1 || input < 0 || input - (int)input != 0) && Clean_stdin()) {
        printf("\n*Warning:Failed! Please enter an interger.\nEnter again:  ");
    }

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
        printf("\n*Warning:Failed! Please enter an positive interger.\nEnter again:  ");
    }
    Clean_stdin();

    return input;
}

static char *Get_input_char() 
{
    char *input = malloc(MAX_STRING);

    fgets(input, MAX_STRING, stdin);
    input[strcspn(input, "\n")] = 0;

    return input;
}

static bool Check_day(int day, int month) 
{
    if (month % 2 == 1 && day > 31) {
        return false;
    }

    if (month == 2 && day > 28) {
        return false;
    } 

    if (day > 30) {
        return false;
    }   

    return true;
}

node_t *push_node(node_t *head, employee_t *data)
{
    node_t *new_node = malloc(sizeof(node_t));
    new_node->employee_data = data;
    new_node->next = head;

    return new_node;
}

void print_linked_list(node_t *head)
{
    if (head == NULL) {
        printf("List empty\n");
    }

    node_t *temp = head;
    while (temp != NULL) {
        printf("%i", temp->employee_data->id);
        printf(" - %s\n", temp->employee_data->full_name);
        printf("    Department: %s\n", temp->employee_data->department);
        printf("    Salary: %f\n", temp->employee_data->salary);
        printf("    Start date: %i/%i/%i\n", temp->employee_data->start_date->day, temp->employee_data->start_date->month, temp->employee_data->start_date->year);
        temp = temp->next;
    }
}

void get_employee_num(int *size)
{
    *size = Get_input_size();
}

date_t *get_date()
{
    date_t *date = malloc(sizeof(date_t));

    do {
        printf("        Enter a valid year: ");
        date->year = Get_input_int();
    } while (date->year < 2000 || date->year > 2023);

    do {
        printf("        Enter a valid month: ");
        date->month = Get_input_int();
    } while (date->month > 12);
    
    do {
        printf("        Enter a valid day: ");
        date->day = Get_input_int();
    } while (!Check_day(date->day, date->month));

    return date;
}

void get_employee_data(employee_t *employee)
{
    printf("    Enter employee id: ");
    employee->id = Get_input_int();

    printf("    Enter employee full name: ");
    employee->full_name = Get_input_char();

    printf("    Enter employee department: ");
    employee->department = Get_input_char();

    printf("    Enter employee salary: ");
    employee->salary = Get_input_float();

    printf("    Enter employee start date\n");
    employee->start_date = get_date();
}

node_t *init_employees(int size)
{
    node_t *head = NULL;

    for (int i = 0; i < size; i++) {
        printf("\nEnter infomation of employee %i\n", i + 1);
        employee_t *temp = malloc(sizeof(employee_t));
        get_employee_data(temp);
        head = push_node(head, temp);
    }

    print_linked_list(head);

    return head;
}
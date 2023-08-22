#include <employees.h>

#define START_YEAR_MIN 1500
#define START_YEAR_MAX 2023

static int clean_stdin()
{
    int c;
    while (c = getchar() != '\n' && c != EOF);
    return 1;
}

static bool check_input_buffer(char *input)
{
    if (strcspn(input, "\n") == MAX_STRING-1) {
        clean_stdin();
        return true;
    }
    return false;
}


static int get_input_size() 
{
    float input;

    while ((scanf("%f", &input) != 1 || input < 0 || input - (int)input != 0) && clean_stdin()) {
        printf("\n*Warning:Failed! Please enter an positive interger.\nEnter again:  ");
    }
    clean_stdin();

    return (int)input;
}

static float get_input_float()
{
    float input;

    while ((scanf("%f", &input) != 1 || input < 0) && clean_stdin()) {
        printf("\n\t*Warning:Failed! Please enter an positive real number.\nEnter again:  ");
    }
    clean_stdin();

    return input;
}

static int get_input_int() 
{
    float input;

    while ((scanf("%f", &input) != 1 || input < 0 || input - (int)input != 0) && clean_stdin()) {
        printf("\n\t*Warning:Failed! Please enter an positive interger.\nEnter again:  ");
    }
    clean_stdin();

    return (int)input;
}

static char *get_input_char() 
{
    char *input = malloc(MAX_STRING);

    fgets(input, MAX_STRING, stdin);
    while (check_input_buffer(input) == 1) {
        printf("\t\tInput too long, enter again: ");
        fgets(input, MAX_STRING, stdin);
    }
    input[strcspn(input, "\n")] = 0;

    return input;
}

static bool check_day(int day, int month) 
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

    printf("\n");
    printf("%-15s %-15s %-15s %-15s %-15s\n", "ID", "Full name", "Department", "Salary","Start date");
    while (temp != NULL) {
        printf("%-15d %-15s %-15s %-15f %d/%d/%d\n", temp->employee_data->id, temp->employee_data->full_name, temp->employee_data->department, temp->employee_data->salary,temp->employee_data->start_date->day, temp->employee_data->start_date->month, temp->employee_data->start_date->year);
        temp = temp->next;
    }
    printf("\n");
}

void get_employee_num(int *size)
{
    *size = get_input_size();
}

date_t *get_date()
{
    date_t *date = malloc(sizeof(date_t));

    printf("\t\tEnter start year: ");  
    date->year = get_input_int();
    while (date->year < START_YEAR_MIN || date->year > START_YEAR_MAX) {
        printf("\t\t\tNot a valid year, enter again: ");
        date->year = get_input_int();
    }

    printf("\t\tEnter start month: ");
    date->month = get_input_int();
    while (date->month > 12) {
        printf("\t\t\tNot a valid month, enter again: ");
        date->month = get_input_int();
    }

    printf("\t\tEnter start day: ");
    date->day = get_input_int();
    while (!check_day(date->day, date->month)) {
        printf("\t\t\tNot a valid day, enter again: ");
        date->day = get_input_int();
    }

    return date;
}

void get_employee_data(employee_t *employee)
{
    printf("\tEnter employee id: ");
    employee->id = get_input_int();

    printf("\tEnter employee full name: ");
    employee->full_name = get_input_char();

    printf("\tEnter employee department: ");
    employee->department = get_input_char();

    printf("\tEnter employee salary: ");
    employee->salary = get_input_float();

    printf("\tEnter employee start date\n");
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

    return head;
}

void free_employee(employee_t *employee)
{
    free(employee->start_date);
    free(employee->full_name);
    free(employee->department);
    free(employee);

    employee = NULL;
}

void free_linked_list(node_t *head)
{
    node_t *temp = head;

    while(head != NULL) {
        temp = head;
        head = head->next;
        free_employee(temp->employee_data);
        free(temp);
    }

    head = NULL;
    temp = NULL;
}

void swap_element_linked_list(node_t *node_1, node_t *node_2)
{
    employee_t *temp = node_1->employee_data;
    node_1->employee_data = node_2->employee_data;
    node_2->employee_data = temp;
}

int find_linked_list_size(node_t *head)
{
    node_t *temp = head;
    int count = 0;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

bool compare_name(char *name_1, char *name_2)
{
    int name_1_size = strlen(name_1);
    int name_2_size = strlen(name_2);
    int index_1 = 0;
    int index_2 = 0;

    while (index_1 < name_1_size && index_2 < name_2_size) {
        if (name_1[index_1] == ' ') {
            index_1++;
            continue;
        }
        if (name_2[index_2] == ' ') {
            index_2++;
            continue;
        }

        if (tolower(name_1[index_1]) > tolower(name_2[index_2])) {
            return true;
        }
        if (tolower(name_1[index_1]) < tolower(name_2[index_2])) {
            return false;
        }

        index_1++;
        index_2++;
    }
    
    return false;
}

void sort_linked_list(node_t *head, int order)
{
    int index_1 = 0;
    int index_2 = 0;
    int size = find_linked_list_size(head);

    node_t *temp = head;

    for(index_1; index_1 < size-1; index_1++) {
        for(index_2 = 0; index_2 < size-index_1; index_2++) {
            switch (order)
            {
            case 0:
                if (compare_name(temp->employee_data->full_name, temp->next->employee_data->full_name)) {
                    swap_element_linked_list(temp, temp->next);
                }
                break;
            case 1:
                if (temp->employee_data->salary < temp->next->employee_data->salary) {
                    swap_element_linked_list(temp, temp->next);
                }
                break;
            case 2:
                if (temp->employee_data->salary > temp->next->employee_data->salary) {
                    swap_element_linked_list(temp, temp->next);
                }
                break;
            default:
                break;
            }
        }
        temp = temp->next;
    }
}

int get_input_sort_order() 
{
    float input;
    printf("Select the sorted order of employees salary (1 = descending or 2 =ascending, or 0 = sorting employees full name alphabetically): ");
    while ((scanf("%f", &input) != 1 || input < 0 || input > 2 || input - (int)input != 0) && clean_stdin()) {
        printf("\n*Warning:Failed! Please enter an 1, 2 or 3 interger.\nEnter again:  ");
    }
    clean_stdin();

    return (int)input;
}


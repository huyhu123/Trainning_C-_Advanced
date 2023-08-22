#include <employees.h>

#define START_YEAR_MIN     1500
#define START_YEAR_MAX     2023
#define MAX_EMPLOYEES      50

typedef enum {
    e_name_sorting = 0x00U,
    e_salary_decend_sorting = 0x01U,
    e_salary_accend_sorting = 0x02U,
} e_sort_mode_t;

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

    while ((scanf("%f", &input) != 1 || input < 0 || input > MAX_EMPLOYEES || input - (int)input != 0) && clean_stdin()) {
        printf("\n*Warning:Failed! Please enter an interger from 0 to 50.\nEnter again:  ");
    }
    clean_stdin();

    return (int)input;
}

static float get_input_float()
{
    float input;

    while ((scanf("%f", &input) != 1 || input <= 0) && clean_stdin()) {
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

static bool find_id(employees_list_t *head, int id)
{
    employees_list_t *temp = head;

    while (temp != NULL) {
        if (temp->employee_data->id == id) {
            return true;
        }
        temp = temp->next;
    }

    return false;
}

static int get_input_id(employees_list_t *head)
{
    int id = get_input_int();
    while (find_id(head, id)) {
        printf("\tID already existed, enter again: ");
        id = get_input_int();
    }
    
    return id;
}

static bool check_name(char *name)
{
    int index = 0;
    int name_length = strlen(name);
    if (name_length <= 1) {
        return false;
    }

    for (index; index < name_length-1; index++) {
        if (!isalpha(name[index])) {
            return false;
        }
    }

    return true;
}

static char *get_input_name() 
{
    char *input = malloc(MAX_STRING);

    fgets(input, MAX_STRING, stdin);
    while (check_input_buffer(input) == 1 || !check_name(input)) {
        printf("\tInput too long or contain numbers/special character, enter again: ");
        fgets(input, MAX_STRING, stdin);
    }
    input[strcspn(input, "\n")] = 0;

    return input;
}

static char *get_input_char() 
{
    char *input = malloc(MAX_STRING);

    fgets(input, MAX_STRING, stdin);
    while (check_input_buffer(input) == 1) {
        printf("\tInput too long, enter again: ");
        fgets(input, MAX_STRING, stdin);
    }
    input[strcspn(input, "\n")] = 0;

    return input;
}

static bool check_date(int day, int month) 
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

employees_list_t *push_node(employees_list_t *head, employee_t *data)
{
    employees_list_t *new_node = malloc(sizeof(employees_list_t));
    new_node->employee_data = data;
    new_node->next = head;

    return new_node;
}

void print_employees_list(employees_list_t *head)
{
    if (head == NULL) {
        printf("List empty\n");
    }

    employees_list_t *temp = head;

    printf("\n");
    printf("%-15s %-15s %-15s %-15s %-15s\n", "ID", "Full name", "Department", "Salary","Start date");
    while (temp != NULL) {
        printf("%-15d %-15s %-15s %-15f %d/%d/%d\n", temp->employee_data->id, 
                                                     temp->employee_data->full_name, 
                                                     temp->employee_data->department, 
                                                     temp->employee_data->salary,
                                                     temp->employee_data->start_date->day, 
                                                     temp->employee_data->start_date->month, 
                                                     temp->employee_data->start_date->year);
        temp = temp->next;
    }
    printf("\n");
}

void get_employee_num(int *size)
{
    *size = get_input_size();
    clrscr();
}

date_t *get_date()
{
    date_t *date = malloc(sizeof(date_t));

    printf("\tEnter start year (1500-2023): ");  
    date->year = get_input_int();
    while (date->year < START_YEAR_MIN || date->year > START_YEAR_MAX) {
        printf("\t\tNot a valid year, enter again: ");
        date->year = get_input_int();
    }

    printf("\tEnter start month: ");
    date->month = get_input_int();
    while (date->month > 12) {
        printf("\t\tNot a valid month, enter again: ");
        date->month = get_input_int();
    }

    printf("\tEnter start day: ");
    date->day = get_input_int();
    while (!check_date(date->day, date->month)) {
        printf("\t\tNot a valid day, enter again: ");
        date->day = get_input_int();
    }

    return date;
}

void get_employee_data(employee_t *employee, employees_list_t *head)
{
    printf("Enter employee id: ");
    employee->id = get_input_id(head);

    printf("Enter employee full name: ");
    employee->full_name = get_input_name();

    printf("Enter employee department: ");
    employee->department = get_input_char();

    printf("Enter employee salary: ");
    employee->salary = get_input_float();

    printf("Enter employee start date\n");
    employee->start_date = get_date();

    clrscr();
    //printf("\e[1;1H\e[2J");
}

employees_list_t *input_employees_information(int size)
{
    employees_list_t *head = NULL;

    for (int i = 0; i < size; i++) {
        printf("\nEnter infomation of employee %i\n", i + 1);
        employee_t *temp = malloc(sizeof(employee_t));
        get_employee_data(temp, head);
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

void free_employees_list(employees_list_t *head)
{
    employees_list_t *temp = head;

    while(head != NULL) {
        temp = head;
        head = head->next;
        free_employee(temp->employee_data);
        free(temp);
    }

    head = NULL;
    temp = NULL;
}

void swap_element_employees_list(employees_list_t *node_1, employees_list_t *node_2)
{
    employee_t *temp = node_1->employee_data;
    node_1->employee_data = node_2->employee_data;
    node_2->employee_data = temp;
}

int find_employees_list_size(employees_list_t *head)
{
    employees_list_t *temp = head;
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

employees_list_t *find_by_index_employees_list(employees_list_t *head, int index)
{
    employees_list_t *temp = head;

    for (int i = 0; i < index-1; i++) {
        if (temp == NULL) {
            return NULL;
        }
        temp = temp->next;
    }

    return temp;
}

void sort_employees_list(employees_list_t *head, int order)
{
    int index_1 = 0;
    int index_2 = 0;
    int size = find_employees_list_size(head);

    employees_list_t *temp = head;

    for(index_1; index_1 < size-1; index_1++) {
        for(index_2 = 0; index_2 < size-index_1; index_2++) {
            temp = find_by_index_employees_list(head, index_2);
            printf("%i\n", index_2);
        
            switch (order)
            {
            case e_name_sorting:
                if (compare_name(temp->employee_data->full_name, temp->next->employee_data->full_name)) {
                    swap_element_employees_list(temp, temp->next);
                }
                break;
            case e_salary_decend_sorting:
                if (temp->employee_data->salary < temp->next->employee_data->salary) {
                    swap_element_employees_list(temp, temp->next);
                }
                break;
            case e_salary_accend_sorting:
                if (temp->employee_data->salary > temp->next->employee_data->salary) {
                    swap_element_employees_list(temp, temp->next);
                }
                break;
            }
        }
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

int get_input_main_interface() 
{
    float input;
    while ((scanf("%f", &input) != 1 || input < 0 || input > 3 || input - (int)input != 0) && clean_stdin()) {
        printf("\n*Warning:Failed! Please enter an 0, 1, 2 or 3 interger.\nEnter again:  ");
    }
    clean_stdin();

    return (int)input;
}

int show_main_interface() 
{
    printf("Choose an option:\n");
    printf("1. Input a number of employees\n");
    printf("2. Add an employees\n");
    printf("3. Sort employee list\n");
    printf("0. Exit\n");
    printf("Your option: ");
    int option = get_input_main_interface();
    clrscr();

    return option;
}

employees_list_t *input_employees(int *employee_num)
{
    //Get number of employee
    printf("Enter number of employee: ");
    get_employee_num(employee_num);

    //Get employee data
    employees_list_t *head = input_employees_information(*employee_num);

    return head;
}

void sort_employee(employees_list_t *head)
{
    int sort_order = 0;
    
    //Sort linked list
    sort_order = get_input_sort_order();
    sort_employees_list(head, sort_order);

    //Print employees_list
    print_employees_list(head);
}
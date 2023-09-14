#include <employees.h>

#define START_YEAR_MIN     1500
#define START_YEAR_MAX     2023

employees_list_t *g_employee_list = NULL;

void linked_list_to_array(employee_t employee_list[], int *employee_num)
{ 
    // Put data of employee to array
    employees_list_t *temp = g_employee_list;
    int index = 0;
    while (temp != NULL) {
        // Set data of linked list to array
        employee_list[index].id = temp->employee_data->id;
        employee_list[index].full_name = temp->employee_data->full_name;
        employee_list[index].department = temp->employee_data->department;
        employee_list[index].salary = temp->employee_data->salary;
        employee_list[index].start_date = temp->employee_data->start_date;

        index++;
        temp = temp->next;
    }
    
    *employee_num = index;
}

//clear stdin
static int clean_stdin()
{
    int c;
    while (c = getchar() != '\n' && c != EOF);
    return 1;
}

// Check if buffer if overflow
static bool check_input_buffer(char *input)
{
    if (strcspn(input, "\n") == MAX_STRING-1) {
        clean_stdin();
        return true;
    }
    return false;
}

// Get input size of employee
static int get_input_size(int employee_num) 
{
    float input;

    // Check if input is valid
    while ((scanf("%f", &input) != 1 || input < -1 || input + employee_num > MAX_EMPLOYEES || input - (int)input != 0) && clean_stdin()) {
        printf("\n*Warning:Failed! Not valid input or number of employee more than 50 (or -1 to exit).\nEnter again:  ");
    }
    clean_stdin();

    return (int)input;
}

// Get positive float input
static float get_input_float()
{
    float input;

    // Check if input is valid
    while ((scanf("%f", &input) != 1 || input <= 0) && clean_stdin()) {
        printf("\n\t*Warning:Failed! Please enter an positive real number.\nEnter again:  ");
    }
    clean_stdin();

    return input;
}

// Get positive interger input
static int get_input_int() 
{
    float input;

    // Check if input is valid
    while ((scanf("%f", &input) != 1 || input < 0 || input - (int)input != 0) && clean_stdin()) {
        printf("\n\t*Warning:Failed! Please enter an positive interger.\nEnter again:  ");
    }
    clean_stdin();

    return (int)input;
}

// Get positive interger input (-1 to exit) for delete function 
static int get_input_int_to_delete() 
{
    float input;

    // Check if input is valid
    while ((scanf("%f", &input) != 1 || input < -1 || input - (int)input != 0) && clean_stdin()) {
        printf("\n\t*Warning:Failed! Please enter an positive interger or -1.\nEnter again:  ");
    }
    clean_stdin();

    return (int)input;
}

// Find index of an employee id (return -1 if not found)
static int find_id(employees_list_t *g_employee_list, int id)
{
    employees_list_t *temp = NULL;
    int count = 0;

    // Check if linked list is empty
    if (g_employee_list == NULL) {
        return -1;
    }

    temp = g_employee_list;

    // Loop through linked list
    while (temp != NULL) {
        // Check if id of node is equal to key
        if (temp->employee_data->id == id) {
            return count;
        }
        temp = temp->next;
        count++;
    }

    return -1;
}

// Get interger input and check if id is alrealdy in the list
static int get_input_id(employees_list_t *g_employee_list)
{
    int id = get_input_int();

    // Check if input is valid
    while (find_id(g_employee_list, id) != -1) {
        printf("\tID already existed, enter again: ");
        id = get_input_int();
    }
    
    return id;
}

// Check if string is empty or contain other character than alphabet
static bool check_name(char *name)
{
    int index = 0;
    int name_length = strlen(name);

    // Check if name if empty
    if (name_length <= 1) {
        return false;
    }

    // Check if input is valid
    for (index; index < name_length-1; index++) {
        if (!isalpha(name[index])) {
            return false;
        }
    }

    return true;
}

// Get input string for full name field
static char *get_input_name() 
{
    char *input = malloc(MAX_STRING);

    fgets(input, MAX_STRING, stdin);
    // Check if input is valid
    while (check_input_buffer(input) == 1 || !check_name(input)) {
        printf("\tInput too long or contain numbers/special character, enter again: ");
        fgets(input, MAX_STRING, stdin);
    }
    // Strip line break at the end of input
    input[strcspn(input, "\n")] = 0;

    return input;
}

// Get input string for department field
static char *get_input_char() 
{
    char *input = malloc(MAX_STRING);

    fgets(input, MAX_STRING, stdin);
    // Check if input is valid
    while (check_input_buffer(input) == 1) {
        printf("\tInput too long, enter again: ");
        fgets(input, MAX_STRING, stdin);
    }
    // Strip line break at the end of input
    input[strcspn(input, "\n")] = 0;

    return input;
}

// Check if date if valid
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

// Append employee node to linked list 
void append_employee(employees_list_t** g_employee_list, employee_t *data)
{
    // Create a new node
    employees_list_t *new_node = malloc(sizeof(employees_list_t));
    new_node->employee_data = data;
 
    // Store the g_employee_list reference in a temporary variable
    employees_list_t *last = *g_employee_list;
 
    // Set the next pointer of the new node as NULL since it
    // will be the last node
    new_node->next = NULL;
 
    // If the Linked List is empty, make the new node as the
    // g_employee_list and return
    if (*g_employee_list == NULL) {
        *g_employee_list = new_node;
        return;
    }
 
    // Else traverse till the last node
    while (last->next != NULL) {
        last = last->next;
    }
 
    // Change the next pointer of the last node to point to
    // the new node
    last->next = new_node;
}


int find_employees_list_size(employees_list_t *g_employee_list)
{
    employees_list_t *temp = g_employee_list;
    int count = 0;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

void free_employee(employee_t *employee)
{
    free(employee->start_date);
    free(employee->full_name);
    free(employee->department);
    free(employee);

    employee = NULL;
}


void print_employees_array(employee_t employee_list[], int employee_num)
{
    printf("\n");
    printf("%-15s %-15s %-15s %-15s %-15s\n", "ID", "Full name", "Department", "Salary","Start date");
    for (int i = 0; i < employee_num; i++) {
        printf("%-15d %-15s %-15s %-15.2f %d/%d/%d\n", employee_list[i].id, 
                                                     employee_list[i].full_name, 
                                                     employee_list[i].department, 
                                                     employee_list[i].salary,
                                                     employee_list[i].start_date->day, 
                                                     employee_list[i].start_date->month, 
                                                     employee_list[i].start_date->year);
    }
    printf("\n");
}

int get_employee_num(int employee_num)
{
    int size = get_input_size(employee_num);
    clrscr();
    return size;
}

date_t *get_date()
{
    date_t *date = malloc(sizeof(date_t));

    // Get year from user and check if valid
    printf("\tEnter start year (1500-2023): ");  
    date->year = get_input_int();
    while (date->year < START_YEAR_MIN || date->year > START_YEAR_MAX) {
        printf("\t\tNot a valid year, enter again: ");
        date->year = get_input_int();
    }

    // Get month from user and check if valid
    printf("\tEnter start month: ");
    date->month = get_input_int();
    while (date->month > 12) {
        printf("\t\tNot a valid month, enter again: ");
        date->month = get_input_int();
    }

    // Get date from user and check if valid
    printf("\tEnter start day: ");
    date->day = get_input_int();
    while (!check_date(date->day, date->month)) {
        printf("\t\tNot a valid day, enter again: ");
        date->day = get_input_int();
    }

    return date;
}

void get_employee_data(employee_t *employee, employees_list_t *g_employee_list)
{
    printf("Enter employee id: ");
    employee->id = get_input_id(g_employee_list);

    printf("Enter employee full name: ");
    employee->full_name = get_input_name();

    printf("Enter employee department: ");
    employee->department = get_input_char();

    printf("Enter employee salary: ");
    employee->salary = get_input_float();

    printf("Enter employee start date\n");
    employee->start_date = get_date();

    clrscr();
}

employees_list_t *input_employees_information(employees_list_t *g_employee_list, int size)
{
    // Get employee data and append to linked list
    for (int i = 0; i < size; i++) {
        printf("\nEnter infomation of employee %i\n", i + 1);
        employee_t *temp = malloc(sizeof(employee_t));
        get_employee_data(temp, g_employee_list);
        append_employee(&g_employee_list, temp);
    }

    return g_employee_list;
}

void free_employee_pointer(employee_t *employee)
{
    free(employee->start_date);
    free(employee->full_name);
    free(employee->department);
    free(employee);

    employee = NULL;
}

void free_employees_list()
{
    employees_list_t *temp = g_employee_list;

    while(g_employee_list != NULL) {
        temp = g_employee_list;
        g_employee_list = g_employee_list->next;
        free_employee_pointer(temp->employee_data);
        free(temp);
    }

    g_employee_list = NULL;
    temp = NULL;
}


bool compare_name(employees_list_t *employees_1, employees_list_t *employees_2)
{
    char *name_1 = employees_1->employee_data->full_name;
    char *name_2 = employees_2->employee_data->full_name;

    // Check if 2 name are the same
    if (strcmp(name_1, name_2) == 0) {
        // If yes compare by id
        if (employees_1->employee_data->id > employees_2->employee_data->id) {
            return true;
        }
        return false;
    }

    int name_1_size = strlen(name_1);
    int name_2_size = strlen(name_2);
    int index_1 = 0;
    int index_2 = 0;

    // Compare 2 name by chareacter from left to right, ignore space
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

// Merges two list of employee.
// First list is from l to m
// Second list is from m+1 to r
employees_list_t* merge(employees_list_t* left, employees_list_t* right, e_sort_mode_t order)
{
    employees_list_t* result = NULL;

    // Base cases
    if (left == NULL) {
        return right;
    }
    else if (right == NULL) {
        return left;
    }

    // Compare the salaries of the employees in the linked lists and merge accordingly
    switch (order)
    {
    case e_salary_decend_sorting:
        if (left->employee_data->salary >= right->employee_data->salary) {
            result = left;
            result->next = merge(left->next, right, order);
        } else {
            result = right;
            result->next = merge(left, right->next, order);
        }
        break;
    case e_salary_accend_sorting:
        if (left->employee_data->salary <= right->employee_data->salary) {
            result = left;
            result->next = merge(left->next, right, order);
        } else {
            result = right;
            result->next = merge(left, right->next, order);
        }
        break;
    case e_name_sorting:
        if (!compare_name(left, right)) {
            result = left;
            result->next = merge(left->next, right, order);
        } else {
            result = right;
            result->next = merge(left, right->next, order);
        }
        break;
    default:
        break;
    }

    return result;
}

//Splitting the linked list of the employee into 2 haft
void split(employees_list_t* source, employees_list_t** front, employees_list_t** back)
{
    employees_list_t* fast;
    employees_list_t* slow;

    if (source == NULL || source->next == NULL) {
        *front = source;
        *back = NULL;
    } else {
        slow = source;
        fast = source->next;

        // Move fast pointer by two and slow pointer by one
        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        // Split the linked list into two halves
        *front = source;
        *back = slow->next;
        slow->next = NULL;
    }
}

// linked list of employee and order to be sorted
void merge_sort(employees_list_t **g_employee_list, e_sort_mode_t order)
{
    if (order == -1) {
        return;
    }

    employees_list_t *temp = *g_employee_list;
    employees_list_t *left;
    employees_list_t *right;

    if (temp == NULL || temp->next == NULL) {
        return;
    }

    split(temp, &left, &right);

    // Recursively sort the two halves
    merge_sort(&left, order);
    merge_sort(&right, order);

    // Merge the sorted halves
    *g_employee_list = merge(left, right, order);
}

e_sort_mode_t get_input_sort_order() 
{
    float input;
    printf("Select the sorted order of employees salary (1 = descending or 2 =ascending, or 0 = sorting employees full name alphabetically) or -1 to exit: ");
    // Check if input is valid
    while ((scanf("%f", &input) != 1 || input < -1 || input > 2 || input - (int)input != 0) && clean_stdin()) {
        printf("\n*Warning:Failed! Please enter an 1, 2 or 3 interger.\nEnter again:  ");
    }
    clean_stdin();

    return (e_sort_mode_t)input;
}

void sort_employee_list(employee_t employee_list[], int *employee_num)
{
    e_sort_mode_t order = get_input_sort_order(); 
    merge_sort(&g_employee_list, order);
    linked_list_to_array(employee_list, employee_num);
}

e_main_interface_option get_input_main_interface() 
{
    float input;
    // Check if input is valid
    while ((scanf("%f", &input) != 1 || input < 0 || input > 5 || input - (int)input != 0) && clean_stdin()) {
        printf("\n*Warning:Failed! Please enter a number from 0 to 5.\nEnter again:  ");
    }
    clean_stdin();

    return (e_main_interface_option)input;
}

e_main_interface_option show_main_interface() 
{
    printf("Choose an option:\n");
    printf("1. Add employees\n");
    printf("2. Show employee table\n");
    printf("3. Sort employee list\n");
    printf("4. Delete employee by id\n");
    printf("5. Delete employee by full name\n");
    printf("0. Exit\n");
    printf("Your option: ");
    e_main_interface_option option = get_input_main_interface();
    clrscr();

    return option;
}

void input_employees(employee_t employee_list[], int *employee_num)
{
    //Get number of employee
    printf("Enter number of employee (or -1 to exit): ");
    int employee_num_add = get_employee_num(*employee_num);

    if (employee_num_add == -1) {
        return;
    }

    //Get employee data
    g_employee_list = input_employees_information(g_employee_list, employee_num_add);

    linked_list_to_array(employee_list, employee_num);
}

void delete_employee_by_index(employees_list_t **g_employee_list, int index) 
{
    // Check if list empty
    if (*g_employee_list == NULL || index == -1) {
        return;
    }

    employees_list_t *current = *g_employee_list;

    // If delete the fisrt element, change g_employee_list to next node
    if (index == 0) {
        *g_employee_list = current->next;
        free_employee(current->employee_data);
        free(current); 
        return;
    }

    // Loop throug list until the index'th node
    int count = 0;
    while (current != NULL && count < index - 1) {
        current = current->next;
        count++;
    }

    if (current == NULL || current->next == NULL) {
        return;
    }

    // Unlink node
    employees_list_t *next = current->next->next;

    // Free node
    free_employee(current->next->employee_data);
    free(current->next); 
    current->next = next;
}

int find_employee_by_id()
{
    // Check if list empty
    if (g_employee_list == NULL) {
        printf("Table empty\n\n");
        return -1;
    }

    // Find the index of the employee by input
    printf("Enter ID of the employee you want to delete (or -1 to exit): ");
    int index = get_input_int_to_delete();
    if (index == -1) {
        return -1;
    }
    while (find_id(g_employee_list, index) == -1 ) {
        printf("\tID not existed, enter again (or -1 to exit): ");
        index = get_input_int_to_delete();
        if (index == -1) {
            return -1;
        }
    }

    return find_id(g_employee_list, index);
}

void delete_employee_by_id(employee_t employee_list[], int *employee_num)
{
    print_employees_array(employee_list, *employee_num);
    delete_employee_by_index(&g_employee_list, find_employee_by_id());
    clrscr();
    linked_list_to_array(employee_list, employee_num);
    print_employees_array(employee_list, *employee_num);
}

bool check_name_duplicate(employees_list_t *g_employee_list, char *name)
{
    employees_list_t *temp = g_employee_list;
    int count = 0;

    // Check if list empty
    if (g_employee_list == NULL) {
        return false;
    }

    // Check if threre are more than 1 of the same name in list
    while (temp != NULL) {
        if (strcmp(temp->employee_data->full_name, name) == 0) {
            count++;
        }
        temp = temp->next;
    }

    if (count >= 2) {
        return true;
    }

    return false;
}

int find_name(char *name)
{
    employees_list_t *temp = g_employee_list;
    int count = 0;

    // Check if list empty
    if (g_employee_list == NULL) {
        return -1;
    }

    // Find the index of the same name as key
    while (temp != NULL) {
        if (strcmp(temp->employee_data->full_name, name) == 0) {
            return count;
        }
        temp = temp->next;
        count++;
    }

    return -1;
}

int find_employee_by_name()
{
    int index = 0;
    char *name = NULL;

    // Check if list empty
    if (g_employee_list == NULL) {
        printf("Table empty\n\n");
        return -1;
    }

    // Get the input name of the user
    printf("Enter full name of the employee you want to delete (or press e to exit): ");
    name = get_input_name(g_employee_list);
    printf("%d\n", strcmp(name, "e"));
    if (strcmp(name, "e") == 0) {
        free(name);
        return -1;
    }
    // Check if name already exised in the list
    while (find_name(name) == -1) {
        free(name);
        printf("\tName not existed, enter again (or press e to exit): ");
        name = get_input_name();
        if (strcmp(name, "e") == 0) {
            free(name);
            return -1;
        }
    }
    
    if (check_name_duplicate(g_employee_list, name)) {
        printf("\tThere are more than 1 person with the same name, please delete by ID instead!!\n");
        free(name);
        return -1;
    }

    index = find_name(name);
    free(name);

    return index;
}

void delete_employee_by_full_name(employee_t employee_list[], int *employee_num)
{
    print_employees_array(employee_list, *employee_num);
    delete_employee_by_index(&g_employee_list, find_employee_by_name());
    clrscr();
    linked_list_to_array(employee_list, employee_num);
    print_employees_array(employee_list, *employee_num);
}
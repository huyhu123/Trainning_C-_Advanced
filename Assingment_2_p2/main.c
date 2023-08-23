#include <employees.h>

int main() {
    //int test;
    //scanf("%i", &test);

    e_main_interface_option option = 1;
    int employee_num = 0;
    int sort_order = 0;
    employees_list_t *employee_list = NULL;

    clrscr();
    while (option != 0)
    {
        option = show_main_interface();
        switch (option)
        {
        case e_quit:
            break;
        case e_input_employees:
            employee_list = input_employees(employee_list, &employee_num);
            break;
        case e_show_employee_table:
            show_employee_table(employee_list);
            break;
        case e_sort:
            mergeSort(&employee_list);
            print_employees_list(employee_list);
            break;
        case e_delete_employee:
            employee_list = delete_employee_by_index(employee_list, 0);
            break;
        }
    }

    //Free allocated memory
    free_employees_list(employee_list);
}
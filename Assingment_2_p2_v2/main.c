#include "employees.h"

employee_t employee_list[MAX_EMPLOYEES];

int main() {
    e_main_interface_option option = 1;
    int employee_num = 0;

    clrscr();
    while (option != 0)
    {
        option = show_main_interface();
        switch (option)
        {
        case e_quit:
            break;
        case e_input_employees:
            input_employees(employee_list , &employee_num);
            break;
        case e_show_employee_table:
            print_employees_array(employee_list, employee_num);
            break;
        case e_sort:
            sort_employee_list(employee_list, &employee_num);
            print_employees_array(employee_list, employee_num);
            break;
        case e_delete_employee_id:
            delete_employee_by_id(employee_list, &employee_num);
            break;
        case e_delete_employee_full_name:
            delete_employee_by_full_name(employee_list, &employee_num);
            break;
        }
    }

    //Free allocated memory
    free_employees_list();

    return 0;
}



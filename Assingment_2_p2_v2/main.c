#include <employees.h>

employee_t *employee_list[MAX_EMPLOYEES];

int main() {
    //int test;
    //scanf("%i", &test);

    e_main_interface_option option = 1;
    int employee_num = 0;
    int employee_index = 0;


    clrscr();
    while (option != 0)
    {
        option = show_main_interface();
        switch (option)
        {
        case e_quit:
            break;
        case e_input_employees:
            input_employees();
            break;
        case e_show_employee_table:
            show_employee_table();
            break;
        case e_sort:
            sort_employee_list();
            show_employee_table();
            break;
        /*
        case e_delete_employee_id:
            print_employees_list(g_employee_list);
            employee_index = find_employee_by_id(g_employee_list);
            delete_employee_by_index(&g_employee_list, employee_index);
            clrscr();
            print_employees_list(g_employee_list);
            break;
        case e_delete_employee_full_name:
            print_employees_list(g_employee_list);
            employee_index = find_employee_by_name(g_employee_list);
            delete_employee_by_index(&g_employee_list, employee_index);
            print_employees_list(g_employee_list);
            break;
        */
        }
    }

    //Free allocated memory
    //free_employees_list(g_employee_list);

    return 0;
}



#include <employees.h>

employees_list_t *g_employee_list = NULL;

//Todo
//emloyee_data_t employee_list[MAX]
//khong dung linked list o main

int main() {
    e_main_interface_option option = 1;
    int employee_num = 0;
    int sort_order = 0;
    int employee_index = 0;
    e_sort_mode_t order = 0;
    

    clrscr();
    while (option != 0)
    {
        option = show_main_interface();
        switch (option)
        {
        case e_quit:
            break;
        case e_input_employees:
            g_employee_list = input_employees(g_employee_list, &employee_num);
            break;
        case e_show_employee_table:
            show_employee_table(g_employee_list);
            break;
        case e_sort:
            order = get_input_sort_order(); 
            merge_sort(&g_employee_list, order);
            print_employees_list(g_employee_list);
            break;
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
        }
    }

    //Free allocated memory
    free_employees_list(g_employee_list);

    return 0;
}



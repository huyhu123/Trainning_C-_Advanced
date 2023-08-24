#include <employees.h>

int main() {
    e_main_interface_option option = 1;
    int employee_num = 0;
    int sort_order = 0;
    int index = 0;
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
            e_sort_mode_t order = get_input_sort_order(); 
            merge_sort(&employee_list, order);
            print_employees_list(employee_list);
            break;
        case e_delete_employee_id:
            print_employees_list(employee_list);
            index = find_employee_by_id(employee_list);
            delete_node_by_index(&employee_list, index);
            clrscr();
            print_employees_list(employee_list);
            break;
        case e_delete_employee_full_name:
            print_employees_list(employee_list);
            index = find_employee_by_name(employee_list);
            delete_node_by_index(&employee_list, index);
            print_employees_list(employee_list);
            break;
        }
    }

    //Free allocated memory
    free_employees_list(employee_list);

    return 0;
}
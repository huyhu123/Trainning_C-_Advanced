#include <employees.h>

int main() {
    int option = 1;
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
            employee_list = input_employees(&employee_num);
            break;
        case e_add_employee:
            //Todo
            break;
        case e_sort:
            sort_employee(employee_list);
            break;
        }
    }

    //Free allocated memory
    free_employees_list(employee_list);
}
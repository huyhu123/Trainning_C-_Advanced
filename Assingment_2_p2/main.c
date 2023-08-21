#include <employees.h>

int main() {
    int employee_num = 0;
    int sort_order = 0;

    //Get number of employee
    printf("Enter number of employee: ");
    get_employee_num(&employee_num);

    //Get employee data
    node_t *head = init_employees(employee_num);

    //Sort linked list
    sort_order = get_input_sort_order();
    sort_linked_list(head, sort_order);

    //Print linked_list
    print_linked_list(head);

    //Free allocated memory
    free_linked_list(head);
}
#include <employees.h>

int main() {
    int employee_num = 0;

    //Get number of employee
    printf("Enter number of employee: ");
    get_employee_num(&employee_num);

    node_t *head = init_employees(employee_num);

    free_linked_list(head);
}
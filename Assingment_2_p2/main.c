#include <employees.h>

int main() {
    int employee_num = 0;

    printf("Enter number of employee: ");
    get_employee_num(&employee_num);

    employee_t *employee_1 = malloc(sizeof(employee_t));
    get_employee_data(employee_1);
}
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <ctype.h> 
#include <string.h>

#define MAX_STRING 50

typedef struct date
{
    int day;
    int month;
    int year;
} date_t;

typedef struct employee
{
    int id;
    char *full_name;
    char *department;
    float salary;
    date_t *start_date;
} employee_t;

typedef struct node
{
    employee_t *employee_data;
    struct node *next;
} node_t;

void get_employee_num(int *size);

void get_employee_data(employee_t *employee);

node_t *init_employees(int size);

void print_linked_list(node_t *head);

void free_linked_list(node_t *head);



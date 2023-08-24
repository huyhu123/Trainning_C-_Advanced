#ifndef _EMPLOYEES_H_
#define _EMPLOYEES_H_

#ifdef _WIN32
#include <conio.h>
#else
#define clrscr() printf("\e[1;1H\e[2J")
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h> 
#include <string.h>

#define MAX_STRING 50

typedef enum {
    e_quit = 0x00U,
    e_input_employees = 0x01U,
    e_show_employee_table = 0x02U,
    e_sort = 0x03U,
    e_delete_employee_id = 0x04U,
    e_delete_employee_full_name = 0x05U,
} e_main_interface_option;

typedef enum {
    e_name_sorting = 0x00U,
    e_salary_decend_sorting = 0x01U,
    e_salary_accend_sorting = 0x02U,
} e_sort_mode_t;

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
} employees_list_t;

void get_employee_num(int *size);

void get_employee_data(employee_t *employee, employees_list_t *head);

employees_list_t *input_employees_information(employees_list_t *head, int size);

void print_employees_list(employees_list_t *head);

void free_employees_list(employees_list_t *head);

e_sort_mode_t get_input_sort_order();

e_main_interface_option show_main_interface();

employees_list_t *input_employees(employees_list_t *head, int *employee_num);

void show_employee_table(employees_list_t *head);

void merge_sort(employees_list_t** head, e_sort_mode_t order);

employees_list_t *delete_employee_by_index(employees_list_t *head, int index);

int find_employee_by_id(employees_list_t *head);

int find_employee_by_name(employees_list_t *head);

void delete_node_by_index(employees_list_t **head, int index);

#endif

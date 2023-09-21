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

#define MAX_EMPLOYEES      50
#define MAX_STRING         50

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


void print_employees_list();

void free_employees_list();

e_main_interface_option show_main_interface();

void input_employees(employee_t employee_list[], int *employee_num);

void sort_employee_list(employee_t employee_list[], int *employee_num);

void delete_employee_by_id(employee_t employee_list[], int *employee_num);

void delete_employee_by_full_name(employee_t employee_list[], int *employee_num);

void print_employees_array(employee_t employee_list[], int employee_num);

#endif

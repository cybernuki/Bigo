#ifndef TEST_TOOLS_H
#define TEST_TOOLS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "./solve_prototypes/educative_sort.h"
#include "./answers/sort.h"


/**TOOLS*/
int array_verification(const int *array, size_t size);
int list_verification(listint_t *list, size_t size);
void error_message(int i1, int value1, int i2, int value2, int type, size_t size);
void print_squares(int i1, size_t size);
void print_rows(int i1, size_t size);
listint_t *create_listint(const int *array, size_t size);
listint_t *generate_linked_list(size_t *size, char *path);
int *generate_array(size_t *size, char *path);


/**Test-cases*/

/**Mandatories*/
void test_bubble_sort();
void test_quick_sort();
void test_selection_sort();
void test_insertion_sort();

/**Advances*/
#endif

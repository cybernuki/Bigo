#ifndef EDUCATIVE_SORT_H
#define EDUCATIVE_SORT_H

#include "../answers/sort.h"

void bubble_sort_i(int *array, size_t size, int *steps);
void insertion_sort_list_i(listint_t **list, int *steps);
void selection_sort_i(int *array, size_t size, int *steps);
void quick_sort_i(int *array, size_t size, int *steps);

#endif
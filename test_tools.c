#include "test_tools.h"

/**
 * array_verification - Verify if the given array is sorted
 * @array: is the given array
 * @size: is the size of the array
 * Return: 1 if it fails, 0 in otherwise, if the given array is sorted it display a message of
 * Okey operation, in otherwise, display a message with the current wrong value
 */
int array_verification(const int *array, size_t size)
{
    int i;

    if (!array)
    {
        printf("Array is NULL\n");
        return (1);
    }
    for (i = 0; i < size - 1; i++)
    {
        if (array[i] > array[i + 1])
        { 
            error_message(i, array[i], i + 1, array[i + 1], 0, size);
            return (1);
        }
    }
    printf("\033[32mWELL DONE! :D\033[0m\n\n");
    return (0);
}

/**
 * list_verification - Verify if the given list is sorted
 * @list: is the given list
 * @size: is the size of the array
 * Return: 1 if it fails, 0 in otherwise, if the given array is sorted it display a message of
 * Okey operation, in otherwise, display a message with the current wrong value
 */
int list_verification(listint_t *list, size_t size)
{
    int i = 0;
    listint_t *node = list;

    if (!list)
    {
        printf("list is NULL\n");
        return (1);
    }
    for (i = 0; i < size; i++, node = node->next)
    {
        if (node->next && node->n > node->next->n)
        { 
            error_message(i, node->n, i + 1, node->next->n, 1, size);
            return (1);
        }
    }
    printf("\033[32mWELL DONE! :D\033[0m\n\n");
    return (0);
}

/**
 * error_message - it prints a error message indicating where is the error
 * in the sorting
 * 
 * @i1: is the index of the first value
 * @value1: is the first value
 * @i2: is the index of the second value
 * @value2: is the second value
 * @type: is the type of set, array -0- or list -1-
 * @size: is the size of the set
 * Return: Nothing, just display in a fansy way
 */
void error_message(int i1, int value1, int i2, int value2, int type, size_t size)
{
    int i, start;
    printf("\033[31mFails:\033[0m\n");
    if(type)
    {
        print_rows(i1, size);
        printf("node[%d]: %d > %d :node[%d]\n", i1, value1, value2, i2);
    }
    else
    {
        print_squares(i1, size);
        printf("Array[%d]: %d > %d :Array[%d]\n", i1, value1, value2, i2);
    }
    printf("\n");
}

/**
 * print_rows - just print some fancy rows that represent
 * the linked list's nodes that are not correctly sorted.
 * 
 * @i1: is the index of the error
 * @size: is the size of the linked list
 * Return: Nothing, just draw a message
 */
void print_rows(int i1, size_t size)
{
    int i, start = 0;

    printf("--------------Linked List------------------\n");
    start = ((i1 - 5) < 0) ? i1 - i1 : i1 - 5;
        for(i = start; i <= i1; i++)
        {
            if(i == 0)
                printf("NULL");
            if (i != i1 && i > 0)
                printf("->(%d)", i);
            else 
            {
                printf("\033[31m-->(\033[0m\033[30;106m%d\033[0;0m\033[31m)\033[0m", i);
                printf("\033[31m-->(\033[0m\033[30;106m%d\033[0;0m\033[31m)\033[0m", i + 1);
                if ((i + 2) <= size - 1)
                    printf("->(%d)", i + 2);
                else
                    printf("->NULL");
                printf("\n");
            }
        }
    printf("-------------------------------------------\n");
}

/**
 * print_squares - just print some fancy squares that represent
 * the array's index that are not correctly sorted.
 * 
 * @i1: is the index of the error
 * @size: is the size of the array
 * Return: Nothing, just draw a message
 */
void print_squares(int i1, size_t size)
{
    int i, start = 0;
    printf("-----------------Array---------------------\n");
    start = ((i1 - 5) < 0) ? i1 - i1 : i1 - 5;
        for(i = start; i <= i1; i++)
        {

            if (i != i1 && i > 0)
                printf("-[%d]", i);
            else 
            {
                printf("\033[31m--[\033[0m\033[30;106m%d\033[0;0m\033[31m]\033[0m", i);
                printf("\033[31m--[\033[0m\033[30;106m%d\033[0;0m\033[31m]\033[0m", i + 1);
                if ((i + 2) <= size - 1)
                    printf("-[%d]", i + 2);
                printf("\n");
            }
        }
    printf("-------------------------------------------\n");
}


/**
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
listint_t *create_listint(const int *array, size_t size)
{
    listint_t *list;
    listint_t *node;
    int *tmp;

    list = NULL;
    while (size--)
    {
        node = malloc(sizeof(*node));
        if (!node)
            return (NULL);
        tmp = (int *)&node->n;
        *tmp = array[size];
        node->next = list;
        node->prev = NULL;
        list = node;
        if (list->next)
            list->next->prev = list;
    }
    return (list);
}

/**
 * generate_array - It reads the file generated by the scrapper and
 * generates an array
 * @size: is a pointer to the size
 * @Return: an array of integers
 */
int *generate_array(size_t *size, char *path)
{
	FILE *fp;
    char str[1024], *token, copy[1024];
    int *array, iterations = 1;

	fp = fopen(path, "r");
	if (fp == NULL)
	{
		printf("Failed to open and read the file.\n");
		exit(99);
	}

    while (fgets(str, 1024, fp) != NULL)
    {
        memcpy(copy, str, 1024);
        token = strtok(copy,", \0");

        if (iterations == 1)
        {
            array = malloc(sizeof(array));
            array[0] = atoi(token);
            iterations++;
            token = strtok(NULL, ", ");
        }
        while(token)
        {
            array = realloc(array, sizeof(array) * iterations);
            array[iterations - 1] = atoi(token);
            iterations++;
            token = strtok(NULL, ", ");
        }
    }

    fclose(fp);
	*size = iterations - 1;
    return (array);
}

/**
 * generate_linked_list - It reads the file generated by the scrapper and
 * generates an linkedlist
 * @size: is a pointer to the size
 * @Return: an array of integers
 */
listint_t *generate_linked_list(size_t *size, char *path)
{
	listint_t *list;
    int *array;

    array = generate_array(size, path);
    list = create_listint(array, *size);
    free(array);

    return (list);
}
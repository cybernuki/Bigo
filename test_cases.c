#include "test_tools.h"

int *random_set, *duplicates_set, *sorted_set, *al_duplicates_set, *inverted_set;
listint_t *l_random_set, *l_duplicates_set, *l_sorted_set, *l_al_duplicates_set, *l_inverted_set;
size_t random_size, duplicates_size, sorted_size, al_duplicates_size, inverted_size;

/**
 * setup_array - read the input files and setup the array_set and the size
 */
void setup_array(const char *test_name)
{
    random_set = generate_array(&random_size, "./input/random_100.txt");
    duplicates_set = generate_array(&duplicates_size, "./input/duplicates_100.txt");
    sorted_set = generate_array(&sorted_size, "./input/sorted_100.txt");
    al_duplicates_set = generate_array(&al_duplicates_size, "./input/almost_duplicates_100.txt");
    inverted_set = generate_array(&inverted_size, "./input/inverted_100.txt");
    printf("The %s test has begun:\n", test_name);
}

/**
 * setup_array - read the input files and setup the list_set and the size
 */
void setup_list(const char *test_name)
{
    l_random_set = generate_linked_list(&random_size, "./input/random_100.txt");
    l_duplicates_set = generate_linked_list(&duplicates_size, "./input/duplicates_100.txt");
    l_sorted_set = generate_linked_list(&sorted_size, "./input/sorted_100.txt");
    l_al_duplicates_set = generate_linked_list(&al_duplicates_size, "./input/almost_duplicates_100.txt");
    l_inverted_set = generate_linked_list(&inverted_size, "./input/inverted_100.txt");
    printf("\n ============================\n");
    printf("The %s test has begun:\n\n", test_name);
}

void free_list(listint_t *node)
{
    if (node)
    {
        free_list(node->next);
        free(node);
    }
}

void teardown_array(int fails, int asserts)
{
    free(random_set);
    free(duplicates_set);
    free(sorted_set);
    free(al_duplicates_set);
    free(inverted_set);
    printf("fails: %d, success: %d\n", fails, asserts);
    printf("\n ============================\n\n");
}

/**
 * teardown_list - free the generated_array or linked_list
 */
void teardown_list(int fails, int asserts)
{
    free_list(l_random_set);
    free_list(l_duplicates_set);
    free_list(l_sorted_set);
    free_list(l_al_duplicates_set);
    free_list(l_inverted_set);
    printf("fails: %d, success: %d\n", fails, asserts);
    printf("\n ============================\n\n");
}


/**
 * test_bubble_sort - it checkout that bubble sort
 * works correctly
 * Return: Nothing
*/
void test_bubble_sort()
{
    int fails = 0, assert = 0;

    setup_array("Bubble sort");

    /** NULL array*/
    printf("NULL case: ");
    bubble_sort(NULL, 10);
    assert++;
    printf("OK\n");

    /** size overflows*/
    printf("size overflows case: ");
    bubble_sort(random_set, random_size + 10);
    assert++;    
    printf("OK\n");

    /** Random set*/
    printf("Random set case: \n");
    bubble_sort(random_set, random_size);
    if (array_verification(random_set, random_size))
        fails++;
    else
        assert++;

    /** duplicates set*/
    printf("Duplicates set case: \n");
    bubble_sort(duplicates_set, duplicates_size);
    if (array_verification(duplicates_set, duplicates_size))
        fails++;
    else
        assert++;

    /** sorted set*/
    printf("Sorted set case: \n");
    bubble_sort(sorted_set, sorted_size);
    if (array_verification(sorted_set, sorted_size))
        fails++;
    else
        assert++;

    /** almost duplicates set*/
    printf("Almost duplicates set case: \n");
    bubble_sort(al_duplicates_set, al_duplicates_size);
    if (array_verification(al_duplicates_set, al_duplicates_size))
        fails++;
    else
        assert++;

    /** inverted set*/
    printf("Inverted set case: \n");
    bubble_sort(inverted_set, inverted_size);
    if (array_verification(inverted_set, inverted_size))
        fails++;
    else
        assert++;

    teardown_array(fails, assert);
}

void test_quick_sort()
{
    int fails = 0, assert = 0;

    setup_array("Quick sort");

    /** NULL array*/
    printf("NULL case: ");
    quick_sort(NULL, 10);
    assert++;
    printf("OK\n");

    /** size overflows*/
    printf("size overflows case: \n");
    quick_sort(random_set, random_size + 10);
    assert++;    
    printf("OK\n");

    /** Random set*/
    printf("Random set case: \n");
    quick_sort(random_set, random_size);
    if (array_verification(random_set, random_size))
        fails++;
    else
        assert++;

    /** duplicates set*/
    printf("Duplicates set case: \n");
    quick_sort(duplicates_set, duplicates_size);
    if (array_verification(duplicates_set, duplicates_size))
        fails++;
    else
        assert++;

    /** sorted set*/
    printf("Sorted set case: \n");
    quick_sort(sorted_set, sorted_size);
    if (array_verification(sorted_set, sorted_size))
        fails++;
    else
        assert++;

    /** almost duplicates set*/
    printf("Almost duplicates set case: \n");
    quick_sort(al_duplicates_set, al_duplicates_size);
    if (array_verification(al_duplicates_set, al_duplicates_size))
        fails++;
    else
        assert++;

    /** inverted set*/
    printf("Inverted set case: \n");
    quick_sort(inverted_set, inverted_size);
    if (array_verification(inverted_set, inverted_size))
        fails++;
    else
        assert++;

    teardown_array(fails, assert);
}

void test_selection_sort()
{
    int fails = 0, assert = 0;

    setup_array("Selection sort");

    /** NULL array*/
    printf("NULL case: ");
    selection_sort(NULL, 10);
    assert++;
    printf("OK\n");

    /** size overflows*/
    printf("size overflows case: ");
    selection_sort(random_set, random_size + 10);
    assert++;    
    printf("OK\n");

    /** Random set*/
    printf("Random set case: \n");
    selection_sort(random_set, random_size);
    if (array_verification(random_set, random_size))
        fails++;
    else
        assert++;

    /** duplicates set*/
    printf("Duplicates set case: \n");
    selection_sort(duplicates_set, duplicates_size);
    if (array_verification(duplicates_set, duplicates_size))
        fails++;
    else
        assert++;

    /** sorted set*/
    printf("Sorted set case: \n");
    selection_sort(sorted_set, sorted_size);
    if (array_verification(sorted_set, sorted_size))
        fails++;
    else
        assert++;

    /** almost duplicates set*/
    printf("Almost duplicates set case: \n");
    selection_sort(al_duplicates_set, al_duplicates_size);
    if (array_verification(al_duplicates_set, al_duplicates_size))
        fails++;
    else
        assert++;

    /** inverted set*/
    printf("Inverted set case: \n");
    selection_sort(inverted_set, inverted_size);
    if (array_verification(inverted_set, inverted_size))
        fails++;
    else
        assert++;

    teardown_array(fails, assert);
}

void test_insertion_sort()
{
    int fails = 0, assert = 0;

    setup_list("insertion sort");

    /** NULL array*/
    printf("NULL case: ");
    insertion_sort_list(NULL);
    assert++;
    printf("OK\n");

    /** Random set*/
    printf("Random set case: \n");
    insertion_sort_list(&l_random_set);
    if (list_verification(l_random_set, random_size))
        fails++;
    else
        assert++;

    /** duplicates set*/
    printf("Duplicates set case: \n");
    insertion_sort_list(&l_duplicates_set);
    if (list_verification(l_duplicates_set, duplicates_size))
        fails++;
    else
        assert++;

    /** sorted set*/
    printf("Sorted set case: \n");
    insertion_sort_list(&l_sorted_set);
    if (list_verification(l_sorted_set, sorted_size))
        fails++;
    else
        assert++;

    /** almost duplicates set*/
    printf("Almost duplicates set case: \n");
    insertion_sort_list(&l_al_duplicates_set);
    if (list_verification(l_al_duplicates_set, al_duplicates_size))
        fails++;
    else
        assert++;

    /** inverted set*/
    printf("Inverted set case: \n");
    insertion_sort_list(&l_inverted_set);
    if (list_verification(l_inverted_set, inverted_size))
        fails++;
    else
        assert++;

    teardown_list(fails, assert);
}
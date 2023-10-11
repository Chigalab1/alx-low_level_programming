#include "search_algos.h"
#include <math.h>

/**
 * jump_search - Func that Searches for a value in an array of
 * integers using the Jump search algorithm
 *
 * @array: Input array
 * @size: number of elements in the array
 * @value: Value to search for
 * Return: Index of the number, or -1 if not found
 */
int jump_search(int *array, size_t size, int value)
{
    if (array == NULL || size == 0)
        return -1;

    int step = (int)sqrt(size); // Step size
    int prev = 0;
    int current = 0;

    // Perform the jump search
    while (current < (int)size && array[current] < value) {
        printf("Value checked array[%d] = [%d]\n", current, array[current]);
        prev = current;
        current += step;
    }

    printf("Value found between indexes [%d] and [%d]\n", prev, current);

    // Linear search in the block for the target value
    for (int i = prev; i < (int)size && i <= current; i++) {
        printf("Value checked array[%d] = [%d]\n", i, array[i]);
        if (array[i] == value)
            return i;
    }

    return -1; // Value not found
}


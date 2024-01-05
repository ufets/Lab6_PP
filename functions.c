#include "functions.h"

int *create_array(const int num, const int limit)
{
    int *array = NULL; 

    array = (int *)malloc(num * sizeof(int));
    for (int i = 0; i < num; i++)
    {
        array[i] = rand() % limit;
    }
    return array;
}

void print_array(int *array, int size)
{
    printf("\n");
    if (array == NULL || size < 0)
    {
        printf(RED_COLOR "ERROR in print_array()\n" RESET_COLOR);
        return;
    }
    for (int i = 0; i < size; i++)
    {
        printf("arr[%d] = %d\n", i, array[i]);
    }
}

void shell_sort(int* array, int size)
{
    for(int step = size / 2; step > 0; step /= 2) 
    {
        for(int i = step; i < size; i++) 
        {
            for(int j = i - step; j >= 0 && array[j] > array[j + step]; j -= step) 
            {
                int temp = array[j];
                array[j] = array[j + step];
                array[j + step] = temp;
            }
        }
    }
}
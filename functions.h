#include "stdio.h"
#include "stdlib.h"

#define RED_COLOR "\x1b[31m"
#define RESET_COLOR "\x1b[0m"

int *create_array(const int num, const int limit);
void print_array(int *array, int size);
void shell_sort(int* array, int size);
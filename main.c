#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
#include <time.h>

#include "functions.h"

#define RED_COLOR "\x1b[31m"
#define RESET_COLOR "\x1b[0m"

#define SIZE 1000000
#define LIMIT 100

/// @brief Different codes of errors
enum CODES
{
    ERROR,
    OK
};

int main(int argc, char *argv[])
{
    srand(time(NULL));
    int *array = create_array(SIZE, LIMIT);

    int num_procs, rank;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    double result = 0;
    int c = 1000;
    int n = SIZE / num_procs;
    int *sub_array = malloc(n * sizeof(int));
    int *sorted_array = malloc(SIZE * sizeof(int));

    for (int i = 0; i < c; i++)
    {
        MPI_Barrier(MPI_COMM_WORLD);

        double start_time = MPI_Wtime();

        MPI_Scatter(array, n, MPI_INT, sub_array, n, MPI_INT, 0, MPI_COMM_WORLD);

        shell_sort(sub_array, n);

        MPI_Gather(sub_array, n, MPI_INT, sorted_array, n, MPI_INT, 0, MPI_COMM_WORLD);

        if (!rank)
        {
            shell_sort(sorted_array, SIZE);
        }

        MPI_Barrier(MPI_COMM_WORLD);

        double end_time = MPI_Wtime();
        if (!rank)
        {
            result += end_time - start_time;
        }
    }
    if (!rank)
    {
        printf("%lf\n", result / c);
    }

    free(array);
    free(sub_array);
    free(sorted_array);

    MPI_Finalize();

    return 0;
}
#include <stdio.h>
#include <mpi.h>
#include <conio.h>

int main(int argc, char *argv[])
{
    int rank;
    int value;
    int sum, max, min, prod;
    int allsum;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    value = rank + 1;

    MPI_Reduce(&value, &sum, 1, MPI_INT,
               MPI_SUM, 0, MPI_COMM_WORLD);

    MPI_Reduce(&value, &max, 1, MPI_INT,
               MPI_MAX, 0, MPI_COMM_WORLD);

    MPI_Reduce(&value, &min, 1, MPI_INT,
               MPI_MIN, 0, MPI_COMM_WORLD);

    MPI_Reduce(&value, &prod, 1, MPI_INT,
               MPI_PROD, 0, MPI_COMM_WORLD);

    MPI_Allreduce(&value, &allsum, 1, MPI_INT,
                  MPI_SUM, MPI_COMM_WORLD);

    if (rank == 0)
    {
        printf("SUM  = %d\n", sum);
        printf("MAX  = %d\n", max);
        printf("MIN  = %d\n", min);
        printf("PROD = %d\n", prod);
    }

    printf("Process %d: Allreduce SUM = %d\n",
           rank, allsum);

    MPI_Finalize();
    getch();
    return 0;
}

#include <stdio.h>
#include <mpi.h>
#include <conio.h>

int main(int argc, char *argv[])
{
    int rank, size;
    int data[8];
    int local;
    int result[8];

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size != 4)
    {
        if (rank == 0)
            printf("Run using 4 processes.\n");

        MPI_Finalize();
        return 0;
    }

    if (rank == 0)
    {
        for (int i = 0; i < 8; i++)
            data[i] = i + 1;
    }

    MPI_Scatter(data, 2, MPI_INT,
                &local, 2, MPI_INT,
                0, MPI_COMM_WORLD);

    local = local * 2;

    MPI_Gather(&local, 2, MPI_INT,
               result, 2, MPI_INT,
               0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        printf("Gathered data:\n");

        for (int i = 0; i < 8; i++)
            printf("%d ", result[i]);
    }

    MPI_Finalize();
    getch();
    return 0;
}

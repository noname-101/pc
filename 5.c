#include <stdio.h>
#include <mpi.h>
int main(int argc, char *argv[])
{
    int rank, size;
    int data;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0)
    {
        data = 100;

        MPI_Send(&data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);

        printf("Process 0 sent data = %d\n", data);
    }
    else if (rank == 1)
    {
        MPI_Recv(&data, 1, MPI_INT, 0, 0,
                 MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        printf("Process 1 received data = %d\n", data);
    }

    MPI_Finalize();

    return 0;
}

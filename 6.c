#include <stdio.h>
#include <mpi.h>
#include <conio.h>

int main(int argc, char *argv[])
{
    int rank;
    int data = 10;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0)
    {
        MPI_Send(&data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Recv(&data, 1, MPI_INT, 1, 0,
                 MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }
    else if (rank == 1)
    {
        MPI_Send(&data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        MPI_Recv(&data, 1, MPI_INT, 0, 0,
                 MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }

    MPI_Finalize();
    getch();
    return 0;
}
if (rank == 0)
{
    MPI_Send(&data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    MPI_Recv(&data, 1, MPI_INT, 1, 0,
             MPI_COMM_WORLD, MPI_STATUS_IGNORE);
}
else if (rank == 1)
{
    MPI_Recv(&data, 1, MPI_INT, 0, 0,
             MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    MPI_Send(&data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
}

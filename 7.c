#include <stdio.h>
#include <mpi.h>
#include <conio.h>

int main(int argc, char *argv[])
{
    int rank;
    int number;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0)
    {
        number = 100;
        printf("Root process broadcasting: %d\n", number);
    }

    MPI_Bcast(&number, 1, MPI_INT, 0, MPI_COMM_WORLD);

    printf("Process %d received number = %d\n",
           rank, number);

    MPI_Finalize();


    getch();
    return 0;
}

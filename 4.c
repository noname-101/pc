#include <stdio.h>
#include <omp.h>
#include <conio.h>

int isPrime(int n)
{
    if (n < 2)
        return 0;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

int main()
{
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    double start, end;

    start = omp_get_wtime();

    printf("Serial prime numbers:\n");

    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i))
            printf("%d ", i);
    }

    end = omp_get_wtime();

    printf("\nSerial time = %lf seconds\n", end - start);

    start = omp_get_wtime();

    printf("\nParallel prime numbers:\n");
    #pragma omp parallel for
    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i))
            printf("%d ", i);
    }

    end = omp_get_wtime();

    printf("\nParallel time = %lf seconds\n", end - start);

    getch();
    return 0;
}

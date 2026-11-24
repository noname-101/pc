#include <stdio.h>
#include <omp.h>
#include <conio.h>

int main()
{
    int n;

    printf("Enter number of iterations: ");
    scanf("%d", &n);

    #pragma omp parallel for schedule(static,2)
    for (int i = 0; i < n; i++)
    {
        printf("Thread %d executes iteration %d\n",
               omp_get_thread_num(), i);
    }
    getch();
    return 0;
}

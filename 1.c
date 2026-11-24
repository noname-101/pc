#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <conio.h>

void merge(int a[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    int temp[1000];

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= mid)
        temp[k++] = a[i++];
    while (j <= high)
        temp[k++] = a[j++];

    for (i = low, k = 0; i <= high; i++, k++)
        a[i] = temp[k];
}

void mergesort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);

        merge(a, low, mid, high);
    }
}

void parallel_mergesort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        #pragma omp parallel sections
        {
            #pragma omp section
            {
                mergesort(a, low, mid);
            }

            #pragma omp section
            {
                mergesort(a, mid + 1, high);
            }
        }

        merge(a, low, mid, high);
    }
}

int main()
{
    int n, a[1000], b[1000];

    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }

    double start, end;

    start = omp_get_wtime();
    mergesort(a, 0, n - 1);
    end = omp_get_wtime();

    printf("\nSequential execution time = %lf seconds\n",
           end - start);

    start = omp_get_wtime();
    parallel_mergesort(b, 0, n - 1);
    end = omp_get_wtime();

    printf("Parallel execution time = %lf seconds\n",
           end - start);

    printf("\nSorted array:\n");

    for (int i = 0; i < n; i++)
        printf("%d ", b[i]);

    getch();
    return 0;
}

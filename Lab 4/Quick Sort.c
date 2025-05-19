#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int *, int, int);
void quickSort(int *, int, int);
void swap(int *, int *);

int low = 0, high = 7;
int a[15000], n, i, j, temp;
clock_t start, end;

int main(void)
{
    int a[8] = {33, 77, 99, 67, 49, 21, 12, 107};
    quickSort(a, low, high);

    printf("The sorted array is : ");
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n=================================================================================\n");

    n = 500;
    while (n <= 14500)
    {
        for (i = 0; i < n; i++)
        {
            a[i] = n - i;
        }
        start = clock();
        quickSort(a, 0, n - 1); // Pass correct arguments
        end = clock();
        printf("\nTime taken to sort %d numbers is %f Secs", n, (((double)(end - start)) / CLOCKS_PER_SEC));
        n = n + 1000;
    }

    return 0; // Add return statement
}

int partition(int *a, int low, int high)
{
    int pivot = a[low], i = low + 1, j = high;
    while (i <= j)
    {
        while (i <= high && a[i] <= pivot)
        {
            i++;
        }
        while (j >= low && a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[low], &a[j]); // Place pivot in the correct position
    return j;
}

void quickSort(int *a, int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = partition(a, low, high);
        quickSort(a, low, mid - 1);
        quickSort(a, mid + 1, high);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

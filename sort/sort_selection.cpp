#include <stdio.h>
#define MAX 100

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

// Selection Sort
void selectionSort(int a[], int n)
{
    int min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[min] > a[j])
            {
                min = j;
            }
        }
        if (a[i] != a[min])
        {
            swap(a[i], a[min]);
        }
    }
}
int main()
{
    int a[5] = {23, 42, 54, 7, 56};
    selectionSort(a, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
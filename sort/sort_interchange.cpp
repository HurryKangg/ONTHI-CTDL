#include <stdio.h>
#define MAX 100

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

// Interchange Sort
void interchangeSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                swap(a[i], a[j]);
            }
        }
    }
}
int main()
{
    int a[5] = {23, 42, 54, 7, 56};
    interchangeSort(a, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
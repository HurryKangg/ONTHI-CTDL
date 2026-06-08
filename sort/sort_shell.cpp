#include <stdio.h>
#define MAX 100

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

// Shell Sort
void shellSort_Ascending(int a[], int n, int h)
{
    while (h > 0)
    {
        for (int i = h; i < n; i++)
        {
            int x = a[i];
            int j = i - h;
            while ((j >= 0) && (a[j] > x))
            {
                a[j + h] = a[j];
                j = j - h;
            }
            a[j + h] = x;
        }
        h = h / 2;
    }
}
int main()
{
    int a[5] = {23, 42, 54, 7, 56};
    shellSort_Ascending(a, 5, 2);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
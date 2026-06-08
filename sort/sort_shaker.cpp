#include <stdio.h>
#define MAX 100

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

// Shaker Sort
void shakerSort_Ascending(int a[], int n)
{
    int Left = 0;
    int Right = n - 1;
    int k = n - 1;
    while (Left < Right)
    {
        for (int j = Right; j > Left; j--)
        {
            if (a[j] < a[j - 1])
            {
                swap(a[j], a[j - 1]);
                k = j;
            }
        }
        Left = k;
        for (int i = Left; i < Right; i++)
        {
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                k = i;
            }
        }
        Right = k;
    }
}
int main()
{
    int a[5] = {23, 42, 54, 7, 56};
    shakerSort_Ascending(a, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
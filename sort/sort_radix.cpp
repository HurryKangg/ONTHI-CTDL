#include <stdio.h>
#define MAX 100
void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
void radixSort(int a[], int n, int maxDigit)
{
    int j, i, k, digit, num;
    int h = 10;
    long b[10][MAX];
    int len[10];
    for (k = 0; k < maxDigit; k++)
    {
        for (j = 0; j < 10; j++)
        {
            len[j] = 0;
        }
        for (i = 0; i < n; i++)
        {
            digit = (a[i] % h) / (h / 10);
            b[digit][len[digit]++] = a[i];
        }
        num = 0;
        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < len[i]; j++)
            {
                a[num++] = b[i][j];
            }
        }
        h *= 10;
    }
}
int main()
{
    int a[5] = {23, 90, 9, 25, 16};

    radixSort(a, 5, 2); // Assuming maxDigit is 2 for numbers up to 99
    printf("Sorted array: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
#include <stdio.h>
#include <conio.h>

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void quickSort_Ascending(int a[], int left, int right)
{
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    int i = left;
    int j = right;
    int x = a[mid];
    do
    {
        while (a[i] < x)
            i++;
        while (a[j] > x)
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i <= j);
    quickSort_Ascending(a, left, j);
    quickSort_Ascending(a, i, right);
}

int main()
{
    int n = 5;
    int a[5] = {24, 54, 43, 76, 4};
    quickSort_Ascending(a, 0, n - 1);
    printf("Sorted: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
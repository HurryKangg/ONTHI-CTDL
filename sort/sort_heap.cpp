#include <stdio.h>
#define MAX 100

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

// Heap Sort
void shift(int a[], int left, int right)
{
    if (left >= right)
        return;
    int i = left;
    int j = 2 * i;
    int x = a[i];
    while (j <= right)
    {
        // thực hiện hiệu chỉnh giữa a[i] với a[j] và a[j+1]
        if ((j < right) && (a[j] < a[j + 1]))
        {
            j = j + 1;
            if (a[j] <= x)
            {
                return;
            }
            swap(a[i], a[j]);
            i = j;
            j = 2 * i;
        }
    }
}
void createHeap(int a[], int n)
{
    int left = n / 2;
    while (left >= 0)
    {
        shift(a, left, n - 1);
        left--;
    }
}
void heapSort_Ascending(int a[], int n)
{
    createHeap(a, n);
    int right = n - 1;
    while (right > 0)
    {
        swap(a[0], a[right]);
        right--;
        shift(a, 0, right);
    }
}
int main()
{
    int a[5] = {23, 42, 54, 7, 56};
    heapSort_Ascending(a, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
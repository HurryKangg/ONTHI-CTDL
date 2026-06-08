#include <stdio.h>
#define MAX 100
void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
void bubbleSort(int a[], int n){
      for (int i = 0; i < n - 1; i++){

        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}
int main()
{
    int a[5] = {23, 90, 9, 25, 16};

    bubbleSort(a, 5);
    printf("Sorted array: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
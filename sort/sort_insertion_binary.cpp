#include <stdio.h>
#define MAX 100

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

// Binary Insertion Sort
void binaryInsertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int Left = 0;
        int Right = i - 1;
        while (Left <= Right)
        {
            int Mid = (Left + Right) / 2;
            if(a[Mid] > key){
                Right = Mid - 1;
            }else{
                Left = Mid + 1;
            }
        }
        for(int j = i - 1; j>=Left;j--){
            a[j + 1] = a[j];
        }
        a[Left] = key;
    }
}
int main()
{
    int a[5] = {23, 42, 54, 7, 56};
    binaryInsertionSort(a, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
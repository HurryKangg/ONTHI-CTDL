#include <stdio.h>
int linear_Search(int a[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            return i; 
        }
    }
    return 0; 
}
int main()
{
    int a[10] = {3, 1, 2, 4, 5, 10, 9, 7, 8, 6};
    int x = 9;
    int result = linear_Search(a, 10, x);
    if (result != 0)
    {
        printf("FOUND %d AT INDEX %d\n", x, result);
    }
    else
    {
        printf("NOT FOUND\n");
    }
    return 0;
}

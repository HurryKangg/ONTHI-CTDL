#include <stdio.h>
#include <conio.h>
#define min(a, b) ((a < b) ? a : b)
#define MAXSIZE 100
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void merge(int a[], int b[], int nb, int c[], int nc, int k)
{
    int ia, ib, ic, jb, jc, kb, kc;
    ia = ib = ic = 0;
    jb = jc = 0;
    while ((nb > 0) && (nc > 0))
    {
        kb = min(k, nb);
        kc = min(k, nc);
        if (b[ib + jb] <= c[ic + jc])
        {
            a[ia++] = b[ib + jb++];
            if (jb == kb)
            {
                while (ic < kc)
                    a[ia++] = c[ic + jc++];
            }
        }
        else
        {
            a[ia++] = c[ic + jc++];
            if (jc == kc)
            {
                while (ib < kb)
                    a[ia++] = b[ib + jb++];
            }
        }
        if ((jb == kb) && (jc == kc))
        {
            ib += kb;
            ic += kc;
            nb -= kb;
            nc -= kc;
            jb = jc = 0;
        }
    }
}
void mergeSort_Ascending(int a[], int n)
{
    int b[MAXSIZE], c[MAXSIZE];
    int ia, ib, ic, jb, jc;
    int k = 1;
    do
    {
        ia = ib = ic = 0;
        while (ia < n)
        {
            for (jb = 0; (ia < n) && (jb < k); jb++)
            {
                b[ib++] = a[ia++];
            }
            for (jc = 0; (ia < n) && (jc < k); jc++)
            {
                c[ic++] = a[ia++];
            }
        }
        merge(a, b, ib, c, ic, k);
        k *= 2;
    } while (k < n);
}
int main()
{
    int a[5] = {23, 90, 9, 25, 16};
    mergeSort_Ascending(a, 5);
    printf("Sorted: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
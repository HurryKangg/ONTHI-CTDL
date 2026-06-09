#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
// 7. Giai thừa: Sử dụng Stack để viết hàm khử đệ quy tính giai thừa của số nguyên dương n
typedef int Itemtype;
struct StackNode
{
    Itemtype Info;
    StackNode *Next;
};

struct Stack
{
    StackNode *Top;
};

void initEmpty(Stack &s)
{
    s.Top = NULL;
}

int isEmpty(Stack &s)
{
    return s.Top == NULL ? 1 : 0;
}

StackNode *createStack(int x)
{
    StackNode *p = new StackNode();
    if (p == NULL)
    {
        printf("Khong co bo nho ben trong!!");
        return NULL;
    }
    p->Info = x;
    p->Next = NULL;
    return p;
}

int push(Stack &s, StackNode *p)
{
    if (p == NULL)
        return -1;
    if (isEmpty(s) == 1)
    {
        s.Top = p;
    }
    else
    {
        p->Next = s.Top;
        s.Top = p;
    }
    return 1;
}

int pop(Stack &s, Itemtype &x)
{
    StackNode *p = s.Top;
    if (isEmpty(s) == 1)
    {
        return 0;
    }
    s.Top = s.Top->Next;
    x = p->Info;
    delete p;
    return 1;
}

int getTop(Stack &s, int &x)
{
    if (isEmpty(s) == 1)
        return 0;
    x = s.Top->Info;
    return 1;
}
void showStack(Stack &s)
{
    if (isEmpty(s) == 1)
    {
        return;
    }
    printf("\nTop: \n");
    for (StackNode *p = s.Top; p != NULL; p = p->Next)
    {
        printf("%d\n", p->Info);
    }
    printf("NULL");
}
long int giaiThua(int n)
{
    Stack s;
    initEmpty(s);
    Itemtype x;
    while (n > 0)
    {
        StackNode *p = createStack(n);
        if (push(s, p) == 0)
            break;
        n--;
    }
    long int kq = 1;
    while (1)
    {
        if (pop(s, x) == 0)
            break;
        kq *= x;
    }
    printf("Ket qua: %ld", kq);
    return kq;
}
int main()
{
    Stack s;
    StackNode *p;
    initEmpty(s);
    int lc;
    Itemtype x;
    do
    {
        printf("\nLua chon: ");
        scanf("%d", &lc);
        switch (lc)
        {
        case 1:
            printf("\nNhap phan tu: ");
            scanf("%d", &x);
            p = createStack(x);
            push(s, p);
            showStack(s);
            break;
        case 2:
            pop(s, x);
            showStack(s);
            break;
        case 3:
            showStack(s);
            break;
        case 4:
        {
            int KT = getTop(s, x);
            if (KT == 1)
            {
                printf("\nDINH DAU: %d", x);
            }
            else
            {
                printf("Khong co phan tu dinh dau");
            }
            break;
        }
        case 5:
        {
            int n;
            printf("\nNhap n: ");
            scanf("%d", &n);
            giaiThua(n);
            break;
        }
        }
    } while (lc != 0);
    return 0;
    getch();
}
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
// 6. Chuyển cơ số: Dùng hàm push, pop đổi số nguyên dương n từ hệ thập phân sang hệ a phân bất kỳ (2  a  9).
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
void doiCoSo(int n, int a)
{
    int sodu, x, cn = n;
    Stack s;
    initEmpty(s);
    while (n != 0)
    {
        sodu = n % a;
        n /= a;
        push(s, createStack(sodu));
    }
    printf("Ket qua: %ld", cn);
    while (isEmpty(s) == 0)
    {
        pop(s, x);
        printf("%3d", x);
    }
}
int main()
{
    Stack s;
    initEmpty(s);
    // char str[] = "ANH KHANG";
    int n, a;
    printf("\nn = ");
    scanf("%d", &n);
    printf("\na = ");
    scanf("%d", &a);
    doiCoSo(n, a);
    return 0;
    getch();
}
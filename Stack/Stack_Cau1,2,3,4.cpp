#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
// 1. Infix -> Postfix: Kẻ bảng chuyển đổi biểu thức M = ((3 + 5) - (6 / 2 - 1)) - 4 sang
// hậu tố bằng Stack.
// 2. Infix -> Postfix: Kẻ bảng chuyển đổi biểu thức M = (2 * 3 - 4 + 2) / (4 - 2) sang hậu
// tố.
// 3. Tính Postfix: Kẻ bảng tính giá trị biểu thức hậu tố M = 8 2 3 * - 5 4 + * 3 / bằng
// Stack.
// 4. Tính Postfix: Kẻ bảng tính giá trị biểu thức hậu tố M = 1 5 * 3 - 2 3 + * 5 / bằng
// Stack.
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
        printf("Bo nho rong\n");
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
int predence(char op)
{
    if (op == '(' || op == ')')
    {
        return 0;
    }
    if (op == '+' || op == '-')
    {
        return 1;
    }
    if (op == '*' || op == '/' || op == '%')
    {
        return 2;
    }
    return -1;
}
int infixToPostfix(char infix[], char postfix[])
{
    Stack s;
    initEmpty(s);
    Itemtype x;
    char item;
    int i = 0, j = 0;
    for(int i =0; infix[i] != '0'; i++){
        item = infix[i];
    }
}
int main()
{
    Stack s;
    StackNode *p;
    initEmpty(s);
    Itemtype x, lc;
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
    } while (lc != 0);
    return 0;
    getch();
}
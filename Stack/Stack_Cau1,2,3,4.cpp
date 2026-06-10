#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
// 1. Infix -> Postfix: Kẻ bảng chuyển đổi biểu thức M = ((3 + 5) - (6 / 2 - 1)) - 4 sang
// hậu tố bằng Stack.
// 2. Infix -> Postfix: Kẻ bảng chuyển đổi biểu thức M = (2 * 3 - 4 + 2) / (4 - 2) sang hậu
// tố.
// 3. Tính Postfix: Kẻ bảng tính giá trị biểu thức hậu tố M = 8 2 3 * - 5 4 + * 3 / bằng
// Stack.
// 4. Tính Postfix: Kẻ bảng tính giá trị biểu thức hậu tố M = 1 5 * 3 - 2 3 + * 5 / bằng
// Stack.
typedef float Itemtype;
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

int getTop(Stack &s, Itemtype &x)
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
        printf("%f\n", p->Info);
    }
    printf("NULL");
}
int predence(char op)
{
    if (op == '(')
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
    return 3;
}
void infixToPostfix(char infix[], char postfix[])
{
    Stack s;
    initEmpty(s);
    Itemtype x;
    char item;
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++)
    {
        item = infix[i];
        if (isalnum(item))
        {
            postfix[j++] = item;
            continue;
        }
        else
        {
            postfix[j++] = ' ';
            if (item == '(')
            {
                push(s, createStack('('));
            }
            else
            {
                if (item == ')')
                {
                    while (pop(s, x) == 1 && x != '(')
                    {
                        postfix[j++] = x;
                        postfix[j++] = ' ';
                    }
                }
                else
                {
                    while (getTop(s, x) == 1 && predence(x) >= predence(item))
                    {
                        if (pop(s, x) == 1)
                        {
                            postfix[j++] = x;
                            postfix[j++] = ' ';
                        }
                    }
                    push(s, createStack(item));
                }
            }
        }
    }
    while (isEmpty(s) == 0)
    {
        if (pop(s, x) == 1)
        {
            postfix[j++] = ' ';
            postfix[j++] = x;
        }
    }
    postfix[j] = '\0';
}
float computeValue(char postfix[])
{
    Stack s;
    initEmpty(s);
    float kq;
    Itemtype value1, value2;
    char *p;
    p = &postfix[0];
    while (*p != '\0')
    {
        while (*p == ' ' || *p == '\t')
        {
            p++;
        }
        if (isdigit(*p))
        {
            int number = 0;
            while (isdigit(*p))
            {
                number = number * 10 + *p - '0';
                p++;
            }
            push(s, createStack(number));
        }
        else
        {
            pop(s, value1);
            pop(s, value2);
            switch (*p)
            {
            case '+':
                kq = value2 + value1;
                break;
            case '-':
                kq = value2 - value1;
                break;
            case '*':
                kq = value2 * value1;
                break;
            case '/':
                kq = value2 / value1;
                break;
            }
            push(s, createStack(kq));
        }
        p++;
    }
    pop(s, kq);
    return kq;
}
void stackComputeInfixPostfix(char str[])
{
    char postfix[100] = "";
    float kq;
    infixToPostfix(str, postfix);
    printf("Bieu thuc Postfix: %s\n", postfix);
    kq = computeValue(postfix);
    printf("Gia tri cua bieu thuc: %.2f\n", kq);
}
int main()
{
    Stack s;
    initEmpty(s);
    char str[] = "(2*3+8/2)*(5-1)";
    stackComputeInfixPostfix(str);
    return 0;
    getch();
}
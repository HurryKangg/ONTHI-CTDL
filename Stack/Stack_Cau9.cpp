#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
// 9. Đảo chuỗi: Viết hàm dùng Stack để đảo ngược thứ tự các từ trong một câu.
typedef char Itemtype;
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
void daoChuoi(char str[])
{
    Stack s;
    initEmpty(s);
    for (int i = 0; str[i] != '\0'; i++)
    {
        push(s, createStack(str[i]));
    }
    int i = 0;
    char x;
    while (isEmpty(s) == 0)
    {
        pop(s, x);
        str[i++] = x;
    }
}
int main()
{
    Stack s;
    initEmpty(s);
    char str[] = "ANH KHANG";
    daoChuoi(str);
    printf("DAO CHUOI THANH: %s", str);
    return 0;
    getch();
}
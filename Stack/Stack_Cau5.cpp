#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
// 5. Kiểm tra ngoặc: Dùng Stack kẻ bảng kiểm tra tính hợp lệ của chuỗi ()[()(())]).
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
int kiemTraDauNgoac(char str[])
{
    Stack s;
    initEmpty(s);
    int len = strlen(str);
    int dong, mo;
    mo = dong = 0;
    Itemtype x, y; // x = ( và y = ) => () -> hợp lệ
    for (int i = 0; i < len; i++)
    {
        x = str[i];
        if (x == '(' || x == '[' || x == '{')
        {
            StackNode *p = createStack(x);
            push(s, p);
            mo++;
        }
        else if (x != ' ')
        {
            if (pop(s, y) == 1)
            {
                if (x == '(' && y != ')') return 0;
                if (x == '[' && y != ']') return 0;
                if (x == '{' && y != '}') return 0;
            }
            dong++;
        }
    }
    if (mo == dong)
        return 1;
    else
        return 0;
}
int main()
{
    Stack s;
    initEmpty(s);
    char str[] = "()]";
    if (kiemTraDauNgoac(str) == 1)
    {
        printf("CHUOI HOP LE");
    }
    else
    {
        printf("CHUOI KHONG HOP LE");
    }
    return 0;
    getch();
}
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
// 7. Lưu trữ đa thức P(x) = anxn + ... + a1x1 + a0. Viết hàm tính giá trị đa thức khi biết x
struct donThuc
{
    float heSo;
    int soMu;
};
typedef donThuc Itemtype;
struct SNode
{
    Itemtype Info;
    SNode *Next;
};
struct SList
{
    SNode *Head;
    SNode *Tail;
};
void initEmpty(SList *sl)
{
    sl->Head = NULL;
    sl->Tail = NULL;
}
int isEmpty(SList &sl)
{
    return sl.Head == NULL ? 1 : 0;
}
SNode *createSNode(Itemtype x)
{
    SNode *p = new SNode();
    if (p == NULL)
        return NULL;
    p->Info = x;
    p->Next = NULL;
    return p;
}

int insertTail(SList &sl, SNode *p)
{
    if (p == NULL)
    {
        return -1;
    }
    if (isEmpty(sl) == 1)
    {
        sl.Head = sl.Tail = p;
        return 1;
    }
    else
    {
        sl.Tail->Next = p;
        sl.Tail = p;
    }
    return 1;
}
void nhapDaThuc(SList &sl, Itemtype x)
{
    int n;
    printf("Nhap bac da thuc: ");
    scanf("%d", &n);

    for (int i = n; i >= 0; i--)
    {
        printf("Nhap he so a%d ", i);
        scanf("%f", &x.heSo);
        x.soMu = i;
        if (x.heSo != 0)
        {
            insertTail(sl, createSNode(x));
        }
    }
}
void inDaThuc(SList &sl)
{
    for (SNode *p = sl.Head; p != NULL; p = p->Next)
    {
        printf("%.2fx^%d", p->Info.heSo, p->Info.soMu);
        if (p->Next != NULL)
            printf(" + ");
    }
}
float tinhDaThuc(SList &sl, float x0)
{
    float kq = 0.0f;
    SNode *p = sl.Head;
    while (p != NULL)
    {
        kq += p->Info.heSo * (float)pow((double)x0, p->Info.soMu);
        p = p->Next;
    }
    return kq;
}
void menu()
{
    printf("\nMENU");
    printf("\n1. Nhap da thuc");
    printf("\n2. In da thuc");
    printf("\n3. Tinh da thuc");
    printf("\n0. Thoat");
}

int main()
{
    SList sl;
    Itemtype x;
    float X;
    initEmpty(&sl);
    int lc;
    do
    {
        menu();
        printf("\nNhap lua chon: ");
        scanf("%d", &lc);
        switch (lc)
        {
        case 1:
            nhapDaThuc(sl, x);
            break;
        case 2:
            inDaThuc(sl);
            break;
        case 3:
            printf("Nhap x: ");
            scanf("%f", &X);
            printf("Da thuc x = %.2f: %.2f", X, tinhDaThuc(sl, X));
            break;
        default:
            break;
        }
    } while (lc != 0);

    getch();
}

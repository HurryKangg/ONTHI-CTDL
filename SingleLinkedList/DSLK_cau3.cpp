#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
// 3. Lưu trữ tọa độ đỉnh đa giác 2D (x, y) trên DHeadK và viết hàm tính chu vi đa giác
struct Point
{
    float x;
    float y;
};
typedef Point Itemtype;
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

void initEmpty(SList &sl)
{
    sl.Head = NULL;
    sl.Tail = NULL;
}

int isEmpty(SList &sl)
{
    return sl.Head == NULL ? 1 : 0;
}

SNode *createPoint(Itemtype x)
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
void nhapDaGiac(SList &sl, int n)
{
    for (int i = 0; i < n; i++)
    {
        Itemtype diem;
        printf("Nhap thu tu %d (a,b): ", i + 1);
        scanf("%f %f", &diem.x, &diem.y);
        insertTail(sl, createPoint(diem));
    }
}

float khoangCach(Itemtype a, Itemtype b)
{
    return (float)sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
float chuViDaGiac(SList &sl)
{
    float cv = 0.0f;
    SNode *p = sl.Head;
    if (p == NULL)
        return 0.0f;
    while (p->Next != NULL)
    {
        cv += khoangCach(p->Info, p->Next->Info);
        p = p->Next;
    }
    cv += khoangCach(sl.Tail->Info, sl.Head->Info);
    return cv;
}
int main()
{
    SList sl;
    initEmpty(sl);

    int n;
    printf("Nhap so luong diem: ");
    scanf("%d", &n);
    nhapDaGiac(sl, n);
    printf("Chu vi da giac: %.2f", chuViDaGiac(sl));

    getch();
}
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
// 13.Lưu trữ phân số (tuSo, mauSo) trên DSLK và viết hàm tính tổng các phân số, In ra các phân số có giá trị lớn hơn 1.

struct PhanSo
{
    int tuso, mauso;
    PhanSo *Next;
};
typedef PhanSo Itemtype;
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
int isEmpty(SList *sl)
{
    return sl->Head == NULL ? 1 : 0;
}
SNode *createSNode(Itemtype *x)
{
    SNode *p = new SNode();
    if (p == NULL)
        return NULL;
    p->Info = *x;
    p->Next = NULL;
    return p;
}
int insertHead(SList *sl, SNode *p)
{
    if (p == NULL)
    {
        return -1;
    }
    if (isEmpty(sl) == 1)
    {
        sl->Head = sl->Tail = p;
        return 1;
    }
    else
    {
        p->Next = sl->Head;
        sl->Head = p;
    }
    return 1;
}
int insertTail(SList *sl, SNode *p)
{
    if (p == NULL)
    {
        return -1;
    }
    if (isEmpty(sl) == 1)
    {
        sl->Head = sl->Tail = p;
        return 1;
    }
    else
    {
        sl->Tail->Next = p;
        sl->Tail = p;
    }
    return 1;
}
void createRandom(SList *sl, int n)
{
    for (int i = 0; i < n; i++)
    {
        Itemtype ps;
        ps.tuso = rand() % 10 + 1;
        ps.mauso = rand() % 10 + 1;
        SNode *p = createSNode(&ps);
        insertTail(sl, p);
    }
}
float giaTri(Itemtype ps)
{
    return (float)ps.tuso / ps.mauso;
}
void tongPS(SList *sl){
    float sum =0;
    SNode* p = sl->Head;
    while(p != NULL){
        sum += giaTri(p->Info);
        p = p->Next;
    }
    printf("Tong cac phan so: %.2f\n", sum);
}
void showSList(SList *sl)
{
    SNode *p = sl->Head;
    while (p != NULL)
    {
        printf("%.2f    ",giaTri(p->Info));
        p = p->Next;
    }
    printf("\n");
}
void danhSachLonHon1(SList *sl){
    printf("Cac phan so co gia tri lon hon 1: ");
    SNode *p = sl->Head;
    while (p != NULL)
    {
        if (giaTri(p->Info) > 1)
        {
            printf("%.2f    ", giaTri(p->Info));
        }
        p = p->Next;
    }
    printf("\n");
}
int main()
{
    int n;
    SList sl;
    initEmpty(&sl);
    int lc;
    do
    {
        printf("\nNhap lua chon: ");
        scanf("%d", &lc);
        switch (lc)
        {
        case 1:
            printf("Nhap so luong phan so: ");
            scanf("%d", &n);
            createRandom(&sl, n);
            break;
        case 2:
            showSList(&sl);
            break;
        case 3:
            tongPS(&sl);
            break;
            case 4:
            danhSachLonHon1(&sl);
            break;
        default:
            break;
        }
    } while (lc != 0);

    getch();
}
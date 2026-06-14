#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
// 1. Tính tổng các nút có giá trị là số chính phương trong DSLK.
typedef int Itemtype;
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

SNode *createSNode(int x)
{
    SNode *p = new SNode();
    if (p == NULL)
        return NULL;
    p->Info = x;
    p->Next = NULL;
    return p;
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

void showSNode(SNode *p)
{
    printf("%d -> ", p->Info);
}

void showSList(SList *sl)
{
    printf("Node: ");
    for (SNode *p = sl->Head; p != NULL; p = p->Next)
    {
        showSNode(p);
    }
    printf("NULL");
}
bool KTSoChinhPhuong(int n)
{
    if (n < 0)
        return false;
    int can = sqrt(n);
    while (can * can == n)
    {
        return true;
    }
    return false;
}
int tongCacNut(SList *sl)
{
    int tong = 0;
    for (SNode *p = sl->Head; p != NULL; p = p->Next)
    {
        if (KTSoChinhPhuong(p->Info))
        {
            tong += p->Info;
        }
    }
    return tong;
}
bool KTSoNguyenTo(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int tongNutSoNguyenTo(SList *sl)
{
    int tong = 0;
    for (SNode *p = sl->Head; p != NULL; p = p->Next)
    {
        if (KTSoNguyenTo(p->Info))
        {
            tong += p->Info;
        }
    }
    return tong;
}
int max(SList &sl)
{
    SNode *p = sl.Head;
    int max = sl.Head->Info;
    while (p != NULL)
    {
        if (p->Info > max)
        {
            max = p->Info;
        }
        p = p->Next;
    }
    return max;
}
int min(SList &sl)
{
    SNode *p = sl.Head;
    int min = sl.Head->Info;
    while (p != NULL)
    {
        if (p->Info < min)
        {
            min = p->Info;
        }
        p = p->Next;
    }
    return min;
}
i
void menu()
{
    printf("\nMENU");
    printf("\n1. Them phan tu");
    printf("\n2. Hien thi danh sach");
    printf("\n3. Tinh tong so chinh phuong");
    printf("\n4. Tinh tong so nguyen to");
    printf("\n5. Max/ Min");
    printf("\n0. Thoat");
}
int main()
{
    SList sl;
    initEmpty(&sl);
    Itemtype x;
    int lc;
    do
    {
        menu();
        printf("\nNhap lua chon: ");
        scanf("%d", &lc);
        switch (lc)
        {
        case 1:
            printf("Nhap phan tu: ");
            scanf("%d", &x);
            insertTail(&sl, createSNode(x));
            break;
        case 2:
            showSList(&sl);
            break;
        case 3:
            printf("Tong so chinh phuong: %d", tongCacNut(&sl));
            break;
        case 4:
            printf("Tong so nguyen to: %d", tongNutSoNguyenTo(&sl));
            break;
        case 5:
            

            printf("\nMAX: %d",max(sl));
            printf("\nMIN: %d",min(sl));
            break;
        default:
            break;
        }
    } while (lc != 0);

    getch();
}
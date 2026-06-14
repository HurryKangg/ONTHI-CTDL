#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
// 2. Đếm số lượng phần tử hiện có của DSLK.
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
int demPhanTu(SList *sl)
{
    int count = 0;
    SNode *p = sl->Head;
    while (p != NULL)
    {
        count++;
        p = p->Next;
    }
    return count;
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
int demSoChinhPhuong(SList *sl)
{
    int count = 0;
    SNode *p = sl->Head;
    while (p != NULL)
    {
        if (KTSoChinhPhuong(p->Info))
        {
            count++;
        }
        p = p->Next;
    }
    return count;
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
int demSoNguyenTo(SList *sl)
{
    int count = 0;
    SNode *p = sl->Head;
    while (p != NULL)
    {
        if (KTSoNguyenTo(p->Info))
        {
            count++;
        }
        p = p->Next;
    }
    return count;
}
int insertInputHand(SList &sl, SNode *x, int k)
{
    if (x == NULL)
    {
        return -1;
    }
    isEmpty(&sl);
    int n = demPhanTu(&sl);
    if (k < 1 || k > n + 1)
        return -1;
    if (k == 1)
        return insertHead(&sl, x);
    if (k == n + 1)
        return insertTail(&sl, x);
    SNode *p = sl.Head;
    for (int i = 1; i < k - 1; i++)
    {
        p = p->Next;
    }
    SNode *z = p->Next;
    x->Next = z;
    p->Next = x;
    return 1;
}
void menu()
{
    printf("\nMENU");
    printf("\n1. Them phan tu");
    printf("\n2. Hien thi danh sach");
    printf("\n3. Dem so phan tu");
    printf("\n4. Dem so chinh phuong");
    printf("\n5. Dem so nguyen to");
    printf("\n6. Them phan tu tuy y");
    printf("\n0. Thoat");
}
int main()
{
    SList sl;
    initEmpty(&sl);
    Itemtype x, k;
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
            printf("So phan tu: %d", demPhanTu(&sl));
            break;
        case 4:
            printf("So chinh phuong: %d", demSoChinhPhuong(&sl));
            break;
        case 5:
            printf("So nguyen to: %d", demSoNguyenTo(&sl));
            break;
        case 6:
            printf("\nNhap phan tu them: ");
            scanf("%d", &x);
            printf("\nNhap vi tri them: ");
            scanf("%d", &k);
            if (insertInputHand(sl, createSNode(x), k) == 1)
            {
                printf("\nDa them phan tu %d vao vi tri %d", x, k);
            }
            else
            {
                printf("\nThem that bai");
            }
        default:
            break;
        }
    } while (lc != 0);

    getch();
}
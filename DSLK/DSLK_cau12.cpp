#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
// 12.Nối hai danh sách liên kết đơn thành một danh sách duy nhất.
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
int deleteSNode_Head(SList *sl)
{
    SNode *p = sl->Head;
    if (p == NULL)
        return 0;
    sl->Head = sl->Head->Next;
    if (sl->Head == NULL)
        sl->Tail = NULL;
    int x = p->Info;
    delete (p);
    return x;
}
int deleteSNode_Tail(SList *sl)
{
    SNode *p = sl->Head;
    if (p == NULL)
        return 0;
    isEmpty(sl);
    while (p->Next != sl->Tail)
    {
        p = p->Next;
    }
    sl->Tail = p;
    p = p->Next;
    int x = p->Info;
    sl->Tail->Next = NULL;
    delete (p);
    return x;
}
void deleteAll(SList *sl)
{
    if (isEmpty(sl) == 1)
        return;
    while (sl->Head != NULL)
    {
        deleteSNode_Head(sl);
    }
    sl->Tail = NULL;
    printf("Delete all...");
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
SList noiHaiDanhSachVao1DanhSach(SList *sl1, SList *sl2)
{
    SList sl;
    initEmpty(&sl);
    SNode *p = sl1->Head;
    SNode *q = sl2->Head;
    while (p != NULL && q != NULL)
    {
        if (p->Info <= q->Info)
        {
            insertTail(&sl, createSNode(p->Info));
            p = p->Next;
        }
        else
        {
            insertTail(&sl, createSNode(q->Info));
            q = q->Next;
        }
    }
    while (p != NULL)
    {
        insertTail(&sl, createSNode(p->Info));
        p = p->Next;
    }
    while (q != NULL)
    {
        insertTail(&sl, createSNode(q->Info));
        q = q->Next;
    }
    return sl;
}
void createRandom(SList *sl, int &n)
{
    do
    {
        printf("Nhap so luong phan tu: ");
        scanf("%d", &n);
    } while (n <= 0);
    srand((unsigned)time(NULL));
    int i = 0;
    while (i < n)
    {
        int x = rand() % 199 - 99;
        SNode *tmp = createSNode(x);
        insertTail(sl, tmp);
        i++;
    }
}
void createInputHand(SList *sl, int &n)
{
    do
    {
        printf("Nhap so luong phan tu: ");
        scanf("%d", &n);

    } while (n <= 0);
    int x;
    for (int i = 0; i < n; i++)
    {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &x);
        SNode *p = createSNode(x);
        insertTail(sl, p);
    }
}

void menu(){
    printf("\nMENU");
    printf("\n1. Them phan tu");
    printf("\n2. Hien thi danh sach");
    printf("\n3. Tao phan tu");
    printf("\n4. Noi hai danh sach");
    printf("\n5. Xoa dau");
    printf("\n6. Xoa tat ca");
    printf("\n7. Xoa cuoi");
    printf("\n8. Nhap tay");
    printf("\n0. Thoat");
}

int main()
{
    int n;
    SList sl, sl1, sl2;
    initEmpty(&sl);
    initEmpty(&sl1);
    initEmpty(&sl2);
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
            createRandom(&sl, n);
            break;
        case 4:
            deleteAll(&sl1);
            deleteAll(&sl2);
            printf("Nhap phan tu cho danh sach 1 va 2:\n");
            createInputHand(&sl1, n);
            createInputHand(&sl2, n);
            sl = noiHaiDanhSachVao1DanhSach(&sl1, &sl2);
            showSList(&sl);
            break;
        case 5:
            deleteSNode_Head(&sl);
            break;
        case 6:
            deleteAll(&sl);
            break;
        case 7:
            deleteSNode_Tail(&sl);
            break;
        case 8:
            createInputHand(&sl, n);
            break;
        default:
            break;
        }
    } while (lc != 0);

    getch();
}
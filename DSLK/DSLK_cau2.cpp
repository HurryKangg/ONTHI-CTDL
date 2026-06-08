#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
//2. Đếm số lượng phần tử hiện có của DSLK.
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
int demPhanTu(SList* sl){
    int count = 0;
    SNode* p = sl->Head;
    while(p != NULL){
        count++;
        p = p->Next;
    }
    return count;
}
int main()
{
    SList sl;
    initEmpty(&sl);
    Itemtype x;
    int lc;
    do
    {
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
        default:
            break;
        }
    } while (lc != 0);

    getch();
}
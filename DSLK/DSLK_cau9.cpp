#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
// 9. Đếm các phần tử trong DSLK chia hết cho 3 và tiến hành nhân đôi giá trị của chúng.
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
    if(p == NULL) return 0;
    isEmpty(sl);
    while (p->Next != sl->Tail)
    {
        p = p->Next;
    }
    sl->Tail = p;
    p = p->Next;
    int x = p->Info;
    sl->Tail->Next = NULL;
    delete(p);
    return x;
}
void deleteAll(SList *sl)
{
    if (isEmpty(sl) == 1)return;
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
void demVaNhanDoi(SList *sl)
{
    SNode* p = sl->Head;
    while(p!= NULL){
        if(p->Info %3 == 0){
            p->Info *= 2;
        }
        p = p->Next;
    }
    printf("\nCac phan tu chia het cho 3 da duoc nhan doi.\n");
    showSList(sl);
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
void menu(){
    printf("\nMENU");
    printf("\n1. Them phan tu");
    printf("\n2. Hien thi danh sach");
    printf("\n3. Tao phan tu");
    printf("\n4. Dem va nhan doi");
    printf("\n5. Xoa dau");
    printf("\n6. Xoa tat ca");
    printf("\n7. Xoa cuoi");
    printf("\n0. Thoat");
}
int main()
{
    int n;
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
            createRandom(&sl, n);
            break;
        case 4:
            demVaNhanDoi(&sl);
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
        default:
            break;
        }
    } while (lc != 0);

    getch();
}
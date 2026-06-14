#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
// 8. Mô phỏng Queue: Kẻ bảng sự thay đổi của biến Front, Rear qua chuỗi 6 thao tác Enqueue/Dequeue.
typedef int ItemType;
struct QueueSNode
{
    ItemType Info;
    QueueSNode *Next;
};

struct Queue
{
    QueueSNode *Head;
    QueueSNode *Tail;
};

void initQueue(Queue &q)
{
    q.Head = NULL;
    q.Tail = NULL;
}

int isEmpty(Queue &q)
{
    return q.Head == NULL ? 1 : 0;
}

QueueSNode *createQueue(ItemType x)
{
    QueueSNode *p = new QueueSNode();
    if (p == NULL)
        return NULL;
    p->Info = x;
    p->Next = NULL;
    return p;
}

int insertQueue(Queue &q, QueueSNode *p)
{
    if (isEmpty(q) == 1)
    {
        q.Head = q.Tail = p;
        return 0;
    }
    else
    {
        q.Tail->Next = p;
        q.Tail = p;
    }
    return 1;
}

int deleteQueue(Queue &q)
{
    QueueSNode *p = q.Head;
    if (isEmpty(q) == 1)
    {
        return 0;
    }
    else
    {
        q.Head = q.Head->Next;
        if (q.Head == NULL)
            q.Tail = NULL;
        int x = p->Info;
        delete p;
        return x;
    }
}
int getHead(Queue &q, int &x)
{
    if (isEmpty(q) == 1)
    {
        printf("HANG DOI RONG!!!\n");
        return 0;
    }
    x = q.Head->Info;
    return 1;
}
int getTail(Queue &q, int &x)
{
    if (isEmpty(q) == 1)
    {
        printf("HANG DOI RONG!!!\n");
        return 0;
    }
    x = q.Tail->Info;
    return 1;
}
void showListHead(Queue &q)
{
    if (isEmpty(q) == 1)
    {
        printf("HANG DOI RONG!!!\n");
        return;
    }
    printf("\nQUEUE: ");
    QueueSNode *p = q.Head;
    while (p != NULL)
    {
        printf("%4d -> ", p->Info);
        p = p->Next;
    }
    printf("NULL");
}
void menu()
{
    printf("\n=== MENU ===");
    printf("\n1. Enqueue");
    printf("\n2. Dequeue");
    printf("\n3. Hien thi queue");
    printf("\n4. Xem phan tu dau tien");
    printf("\n5. Xem phan tu cuoi cung");
    printf("\n0. Thoat");
}
int main()
{
    Queue q;
    initQueue(q);
    ItemType x;
    int lc;
    do
    {
        menu();
        scanf("%d", &lc);
        switch (lc)
        {
        case 1:
            printf("Nhap phan tu: ");
            scanf("%d", &x);
            insertQueue(q, createQueue(x));
            break;
        case 2:
            deleteQueue(q);
            break;
        case 3:
            showListHead(q);
            break;
        case 4:
            if (getHead(q, x) == 1)
            {
                printf("Phan tu dau tien: %d\n", x);
            }
            else
            {
                printf("HANG DOI RONG!!!\n");
            }
            break;
        case 5:
            if (getTail(q, x) == 1)
            {
                printf("Phan tu cuoi cung: %d\n", x);
            }
            else
            {
                printf("HANG DOI RONG!!!\n");
            }
            break;
        default:
            break;
        }
    } while (lc != 0);
    return 0;
}
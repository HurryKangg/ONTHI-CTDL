#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
// 6. Viết hàm xuất thông tin của 3 sinh viên có Điểm Trung Bình cao nhất ra màn hình.
// Khai báo cấu trúc sinh viên
struct SV
{
    char maSV[10];
    char ten[50];
    float diemGK;
    float diemTL;
    float diemCK;
};
typedef SV Itemtype;
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

SNode *createSNode(Itemtype SV)
{
    SNode *p = new SNode();
    if (p == NULL)
        return NULL;
    p->Info = SV;
    p->Next = NULL;
    return p;
}
void inputSV(Itemtype *SV)
{
    printf("Nhap ma SV: ");
    getchar();
    fgets(SV->maSV, sizeof(SV->maSV), stdin);
    SV->maSV[strcspn(SV->maSV, "\n")] = '\0';

    printf("Nhap ten SV: ");
    fgets(SV->ten, sizeof(SV->ten), stdin);
    SV->ten[strcspn(SV->ten, "\n")] = '\0';

    printf("Nhap diem GK: ");
    scanf("%f", &SV->diemGK);
    printf("Nhap diem TL: ");
    scanf("%f", &SV->diemTL);
    printf("Nhap diem CK: ");
    scanf("%f", &SV->diemCK);
}
int insertTail(SList *sl, Itemtype x)
{
    SNode *p = createSNode(x);
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

float diemTrungBinh(Itemtype *x)
{
    return x->diemGK * 0.2 + x->diemTL * 0.3 + x->diemCK * 0.5;
}

void show1SV(Itemtype SV)
{
    printf("Ma SV: %s\n", SV.maSV);
    printf("Ten SV: %s\n", SV.ten);
    printf("Diem GK: %.2f\n", SV.diemGK);
    printf("Diem TL: %.2f\n", SV.diemTL);
    printf("Diem CK: %.2f\n", SV.diemCK);
    printf("Diem trung binh: %.2f\n", diemTrungBinh(&SV));
}

void showSList(SList *sl)
{
    printf("DANH SACH SINH VIEN\n");
    for (SNode *p = sl->Head; p != NULL; p = p->Next)
    {
        show1SV(p->Info);
        printf("\n");
    }
}

void createList(SList *sl, Itemtype x)
{
    int n;
    do
    {
        printf("Nhap so luong sinh vien: ");
        scanf("%d", &n);
    } while (n < 0);
    for (int i = 0; i < n; i++)
    {
        printf("Sinh vien thu %d: \n", i + 1);
        inputSV(&x);
        insertTail(sl, x);
    }
}

void swap(Itemtype &a, Itemtype &b)
{
    Itemtype temp = a;
    a = b;
    b = temp;
}
void sortSListDiemTrungBinh(SList *sl)
{
    for (SNode *p = sl->Head; p != NULL; p = p->Next)
    {
        SNode *min = p;
        for (SNode *q = p->Next; q != NULL; q = q->Next)
        {
            if (diemTrungBinh(&min->Info) < diemTrungBinh(&q->Info))
            {
                min = q;
            }
        }
        if (min != p)
        {
            swap(min->Info, p->Info);
        }
    }
}
void top3DTB(SNode *head)
{
    printf("3 SINH VIEN CO DIEM TRUNG BINH CAO NHAT:\n");
    for (int i = 0; i < 3 && head != NULL; i++, head = head->Next)
    {
        printf("%s - %.2f\n", head->Info.ten, diemTrungBinh(&head->Info));
    }
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
            inputSV(&x);
            insertTail(&sl, x);
            show1SV(x);
            break;
        case 2:
            showSList(&sl);
            break;
        case 3:
            createList(&sl, x);
            break;
        case 4:
            printf("Diem trung binh cua sinh vien: %.2f\n", diemTrungBinh(&x));
            break;
        case 5:
            sortSListDiemTrungBinh(&sl);
            showSList(&sl);
            break;
        case 6:
            sortSListDiemTrungBinh(&sl);
            top3DTB(sl.Head);
            break;
        default:
            break;
        }
    } while (lc != 0);

    getch();
}
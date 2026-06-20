#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
// 13.Lưu trữ phân số (tuSo, mauSo) trên DSLK và viết hàm tính tổng các phân số, In ra các phân số có giá trị lớn hơn 1.

struct PhanSo
{
    int tuSo;
    int mauSo;
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
void createRandom(SList &sl, int n)
{
    for (int i = 0; i < n; i++)
    {
        Itemtype ps;
        ps.tuSo = rand() % 10 + 1;
        ps.mauSo = rand() % 10 + 1;
        SNode *p = createSNode(ps);
        insertTail(sl, p);
    }
}
void kiemtraDau(Itemtype &x)
{
    if (x.mauSo < 0)
    {
        x.mauSo *= -1;
        x.tuSo *= -1;
    }
}
int USCLN(int a, int b)
{
    a = abs(a);
    b = abs(b);
    if (a == 0 || b == 0)
    {
        return 1;
    }
    else
    {
        while (a != b)
        {
            if (a > b)
            {
                a = a - b;
            }
            else
            {
                b = b - a;
            }
        }
    }
    return a;
}
void rutGon(Itemtype &x)
{
    kiemtraDau(x);
    int ucln = USCLN(x.tuSo, x.mauSo);
    x.tuSo /= ucln;
    x.mauSo /= ucln;
}
void nhapSo(Itemtype &x)
{
    do
    {
        printf("Nhap tu so: ");
        scanf("%d", &x.tuSo);
    } while (x.tuSo == 0);
    do
    {
        printf("Nhap mau so: ");
        scanf("%d", &x.mauSo);
    } while (x.mauSo == 0);
    rutGon(x);
}
void inPhanSo(Itemtype x)
{
    kiemtraDau(x);
    if (x.mauSo == 1)
    {
        printf("%d", x.tuSo);
    }
    else
    {
        printf("%d/%d", x.tuSo, x.mauSo);
    }
}
void showSList(SList &sl)
{
    for (SNode *p = sl.Head; p != NULL; p = p->Next)
    {
        inPhanSo(p->Info);
        printf("   ");
    }
}
void createPhanSo(SList &sl)
{
    int n;
    Itemtype x;

    do
    {
        printf("Nhap so luong phan so: ");
        scanf("%d", &n);
    } while (n <= 0);
    srand((unsigned)time(NULL));
    int i = 0;
    while (i < n)
    {
        do
        {
            x.tuSo = (rand() % 100) - 50;
        } while (x.tuSo == 0);
        do
        {
            x.mauSo = (rand() % 100) - 50;
        } while (x.mauSo == 0);
        rutGon(x);
        SNode *p = createSNode(x);
        insertTail(sl, p);
        i++;
    }
}
void toiGian(SList &sl)
{
    for (SNode *p = sl.Head; p != NULL; p = p->Next)
    {
        rutGon(p->Info);
    }
    printf("Da toi gian phan so\n");
    showSList(sl);
}
Itemtype tongPhanSo(Itemtype ps1, Itemtype ps2)
{
    Itemtype x;
    x.tuSo = (ps1.tuSo * ps2.mauSo) + (ps2.tuSo * ps1.mauSo);
    x.mauSo = (ps1.mauSo * ps2.mauSo);
    rutGon(x);
    return x;
}
Itemtype tongDanhSach(SList &sl)
{
    Itemtype sum = {0, 1};
    for (SNode *p = sl.Head; p != NULL; p = p->Next)
    {
        if (p->Info.mauSo != 0)
        {
            sum = tongPhanSo(sum, p->Info);
        }
    }
    return sum;
}
void danhSachLonHon1(SList &sl)
{
    for (SNode *p = sl.Head; p != NULL; p = p->Next)
    {
        if (p->Info.mauSo != 0 && p->Info.tuSo * 1.0 / p->Info.mauSo > 1.0f)
        {
            inPhanSo(p->Info);
        }
    }
}
void menu()
{
    printf("\nMENU");
    printf("\n1. Nhap phan so");
    printf("\n2. Hien thi phan so");
    printf("\n3. Tao phan tu");
    printf("\n4. Toi gian phan so");
    printf("\n5. Tinh tong cac phan so");
    printf("\n6. Tong cac phan so");
    printf("\n7. Hien thi cac phan so co gia tri lon hon 1");
    printf("\n0. Thoat");
}

int main()
{
    SNode *p;
    SNode* q;
    SList sl;
    Itemtype x, ps1, ps2;
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
            nhapSo(x);
            p = createSNode(x);
            insertTail(sl, p);
            inPhanSo(x);
            break;
        case 2:
            showSList(sl);
            break;
        case 3:
            createPhanSo(sl);
            break;
        case 4:
            toiGian(sl);
            break;
        case 5:
            printf("Nhap phan so thu 1: \n");
            nhapSo(ps1);
            printf("Nhap phan so thu 2: \n");
            nhapSo(ps2); 
            printf("Tong phan so: ");
            inPhanSo(ps1);
            printf(" + ");
            inPhanSo(ps2);
            printf(" = ");
            inPhanSo(tongPhanSo(ps1, ps2));
            break;
        case 6:
        {
            Itemtype kq = tongDanhSach(sl);
            printf("\nTong danh sach: ");
            inPhanSo(kq);
            break;
        }
        case 7:
            danhSachLonHon1(sl);
            break;
        default:
            break;
        }
    } while (lc != 0);

    getch();
}
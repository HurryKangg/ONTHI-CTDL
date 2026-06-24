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
int KTSoChinhPhuong(int n)
{
    if (n < 0)
        return 0;
    int can = sqrt(n);
    while (can * can == n)
    {
        return 1;
    }
    return 0;
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
int KTSoNguyenTo(int n)
{
    if (n < 2)
        return 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
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
int isHoanThien(int n)
{
    int sum = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }
    return sum == n ? 1 : 0;
}
void inSoHoanThien(SList *sl)
{
    for (SNode *p = sl->Head; p != NULL; p = p->Next)
    {
        if (isHoanThien(p->Info))
        {
            printf("%4d", p->Info);
        }
    }
}
// 1. Đếm/Tổng các phần tử DSLK Đơn
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
int tongPhanTu(SList &sl)
{
    int tong = 0;
    SNode *p = sl.Head;
    while (p != NULL)
    {
        tong += p->Info;
        p = p->Next;
    }
    return tong;
}
// 2.Tính tổng/đếm số chẵn/lẻ/âm/dương các phần tử DSLK đơn
int demAm(SList &sl)
{
    int count = 0;
    SNode *p = sl.Head;
    while (p != NULL)
    {
        if (p->Info < 0)
        {
            count++;
        }
        p = p->Next;
    }
    return count;
}
int demDuong(SList &sl)
{
    int count = 0;
    SNode *p = sl.Head;
    while (p != NULL)
    {
        if (p->Info > 0)
        {
            count++;
        }
        p = p->Next;
    }
    return count;
}
int demChan(SList &sl)
{
    int count = 0;
    SNode *p = sl.Head;
    while (p != NULL)
    {
        if (p->Info % 2 == 0)
        {
            count++;
        }
        p = p->Next;
    }
    return count;
}
int demLe(SList &sl)
{
    int count = 0;
    SNode *p = sl.Head;
    while (p != NULL)
    {
        if (p->Info % 2 != 0)
        {
            count++;
        }
        p = p->Next;
    }
    return count;
}
// 3. Kiểm tra mảng toàn chẵn/lẻ/âm/dương trong DSLK
int kiemTraMangToanChan(SList &sl)
{
    if (isEmpty(&sl) == 1)
        return 0;
    SNode *p = sl.Head;
    while (p != NULL)
    {
        if (p->Info % 2 != 0)
        {
            return 0;
        }
        p = p->Next;
    }
    return 1;
}
int kiemTraMangToanLe(SList &sl)
{
    if (isEmpty(&sl) == 1)
        return 0;
    SNode *p = sl.Head;
    while (p != NULL)
    {
        if (p->Info % 2 == 0)
        {
            return 0;
        }
        p = p->Next;
    }
    return 1;
}
int kiemTraMangToanAm(SList &sl)
{
    if (isEmpty(&sl) == 1)
        return 0;
    SNode *p = sl.Head;
    while (p != NULL)
    {
        if (p->Info >= 0)
        {
            return 0;
        }
        p = p->Next;
    }
    return 1;
}
int kiemTraMangToanDuong(SList &sl)
{
    if (isEmpty(&sl) == 1)
        return 0;
    SNode *p = sl.Head;
    while (p != NULL)
    {
        if (p->Info <= 0)
        {
            return 0;
        }
        p = p->Next;
    }
    return 1;
}
// 4. Kiểm tra danh sách âm/dương xen kẻ hay không.
int kiemTraAmDuongXenKe(SList &sl)
{
    if (isEmpty(&sl) == 1)
        return 0;
    if (sl.Head == 0 || sl.Head->Next == NULL)
        return 0;
    for (SNode *p = sl.Head; p->Next != NULL; p = p->Next)
    {
        if (p->Info * p->Next->Info > 0)
        {
            return 0;
        }
    }
    return 1;
}
int kiemTraChanLeXenKe(SList &sl)
{
    if (isEmpty(&sl) == 1)
        return 0;
    if (sl.Head == 0 || sl.Head->Next == NULL)
        return 0;
    for (SNode *p = sl.Head; p->Next != NULL; p = p->Next)
    {
        if ((p->Info + p->Next->Info) % 2 == 0)
        {
            return 0;
        }
    }
    return 1;
}
// 5. Viết hàm tính trung bình cộng các phần tử chẵn lẻ
float tbCongPhanTuChan(SList &sl)
{
    int sum = 0;
    int count = 0;
    SNode *p = sl.Head;
    while (p != NULL)
    {
        if (p->Info % 2 == 0)
        {
            sum += p->Info;
            count++;
        }
        p = p->Next;
    }
    return count > 0 ? sum * 1.0 / count : 0.0f;
}
float tbCongPhanTuLe(SList &sl)
{
    int sum = 0;
    int count = 0;
    SNode *p = sl.Head;
    while (p != NULL)
    {
        if (p->Info % 2 != 0)
        {
            sum += p->Info;
            count++;
        }
        p = p->Next;
    }
    return count > 0 ? sum * 1.0 / count : 0.0f;
}
// 6. Tìm max/min trong danh sách liên kết
int max(SList &sl)
{
    if (isEmpty(&sl) == 1)
        return 0;
    int max = sl.Head->Info;
    SNode *p = sl.Head;
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
    if (isEmpty(&sl) == 1)
        return 0;
    int min = sl.Head->Info;
    SNode *p = sl.Head;
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
// 7. Đếm Tính tổng các phần tử lớn hơn giá trị trung bình cộng toàn danh sách
float tbCongPhanTu(SList &sl)
{
    int sum = 0;
    int count = 0;
    SNode *p = sl.Head;
    while (p != NULL)
    {
        sum += p->Info;
        count++;
        p = p->Next;
    }
    return count > 0 ? sum * 1.0 / count : 0.0f;
}
int demTinhTongPhanTuLonHonTBC(SList &sl)
{
    int count = 0;
    int sum = 0;
    int tbc = tbCongPhanTu(sl);
    SNode *p = sl.Head;
    while (p != NULL)
    {
        if (p->Info > tbc)
        {
            count++;
            sum += p->Info;
        }
        p = p->Next;
    }
    return count;
}
// 8.Sắp xếp danh sách tăng/giảm dần.
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void sortSelection_Ascending(SList &sl)
{
    for (SNode *p = sl.Head; p != NULL; p = p->Next)
    {
        SNode *min = p;
        for (SNode *q = p->Next; q != NULL; q = q->Next)
        {
            if (q->Info < min->Info)
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
// 9,10. Di chuyển các số chẵn lẻ/âm/dương/Số nguyên tố hoàn thiện vào đầu trong DSLK
void sapXepDiChuyenSoNguyenTo(SList &sl)
{
    for (SNode *p = sl.Head; p != NULL; p = p->Next)
    {
        for (SNode *q = p->Next; q != NULL; q = q->Next)
        {
            if (!KTSoNguyenTo(p->Info) && KTSoNguyenTo(q->Info))
            {
                swap(p->Info, q->Info);
            }
        }
    }
}
// 11. Thêm 1 node vào DSLK sao cho giữ nguyên thứ tự
int them1SNodeVaoDSLKGiuNguyenThuTu(SList &sl, Itemtype x)
{
    SNode *tmp = createSNode(x);
    if (isEmpty(&sl) == 1)
        sl.Head = sl.Tail = tmp;
    return 1;
    if (x <= sl.Head->Info)
        insertHead(&sl, tmp);
    return 1;
    if (x >= sl.Tail->Info)
        insertTail(&sl, tmp);
    return 1;
    SNode *p = sl.Head;
    while (p->Next != NULL && p->Next->Info < x)
    {
        p = p->Next;
    }
    p->Next = tmp->Next;
    tmp->Next = p;
    return 1;
}
// 12.Xóa các phần tử giá trị x
int xoaCacPhanTuX(SList &sl, Itemtype x)
{
    while (sl.Head != NULL && sl.Head->Info == x)
    {
        SNode *p = sl.Head;
        sl.Head = sl.Head->Next;
        delete p;
    }
    SNode *cur = sl.Head;
    while (cur != NULL && cur->Next != NULL)
    {
        if (cur->Next->Info == x)
        {
            SNode *p = cur->Next;
            cur->Next = p->Next;
            delete p;
        }
        else
        {
            cur = cur->Next;
        }
    }
    return 1;
}
// 13.Đảo ngược danh sách
void reverseList(SList *sl)
{
    SNode *prev = NULL;
    SNode *cur = sl->Head;
    SNode *next = NULL;
    while (cur != NULL)
    {
        next = cur->Next;
        cur->Next = prev;
        prev = cur;
        cur = next;
    }
    sl->Head = prev;
}

int main()
{
    SList sl;
    initEmpty(&sl);
    Itemtype x, kq;

    insertTail(&sl, createSNode(4));
    insertTail(&sl, createSNode(3));
    insertTail(&sl, createSNode(5));
    insertTail(&sl, createSNode(6));
    insertTail(&sl, createSNode(8));
    insertTail(&sl, createSNode(7));

    showSList(&sl);

    printf("\nSo phan tu: %d", demPhanTu(&sl));

    printf("\nTong phan tu: %d", tongPhanTu(sl));

    printf("\nSo chinh phuong: %d", demSoChinhPhuong(&sl));

    printf("\nSo nguyen to: %d", demSoNguyenTo(&sl));

    printf("\nSo hoan thien: ");
    inSoHoanThien(&sl);
    // 9,10
    printf("\nSau khi sap xep: ");
    sapXepDiChuyenSoNguyenTo(sl);
    showSList(&sl);
    // 11
    kq = kiemTraAmDuongXenKe(sl);
    if (kq == 1)
    {
        printf("\nDANH SACH TREN CO AM DUONG XEN KE!!\n");
        showSList(&sl);
    }
    else
    {
        printf("\nDANH SACH TREN KHONG CO AM DUONG XEN KE!!");
    }
    kq = kiemTraChanLeXenKe(sl);
    if (kq == 1)
    {
        printf("\nDANH SACH TREN CO CHAN LE XEN KE!!\n");
        showSList(&sl);
    }
    else
    {
        printf("\nDANH SACH TREN KHONG CO CHAN LE XEN KE!!");
    }
    // 12
    printf("\nNhap phan tu can xoa: ");
    scanf("%d", &x);
    xoaCacPhanTuX(sl, x);
    showSList(&sl);

    // 13
    reverseList(&sl);
    showSList(&sl);

    getch();
}
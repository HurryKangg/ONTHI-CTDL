#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <math.h>
#include <limits.h>

typedef int Itemtype;

//----------------------------------------------BSTNODE------------------------------------------------------
struct BSTNode
{
    Itemtype Info;
    BSTNode *Right;
    BSTNode *Left;
};
//--------------------------------------------------------------------------------------------------------

//----------------------------------------------BTREE------------------------------------------------------
struct BTree
{
    BSTNode *Root;
};
//--------------------------------------------------------------------------------------------------------

//-----------------------------------------------INIT----------------------------------------------------
void initBST(BTree &bt)
{
    bt.Root = NULL;
};
//--------------------------------------------------------------------------------------------------------

//-----------------------------------------------CREATE-------------------------------------------------
BSTNode *createNode(Itemtype x)
{
    BSTNode *p = new BSTNode();
    if (p == NULL)
        return NULL;
    p->Info = x;
    p->Right = NULL;
    p->Left = NULL;
    return p;
}
//--------------------------------------------------------------------------------------------------------

//-----------------------------------------------INSERT-------------------------------------------------
int insertTree(BSTNode *&r, BSTNode *x)
{
    if (r == NULL)
    {
        r = x;
        return 1;
    }
    if (r->Info == x->Info)
    {
        return 0;
    }
    if (x->Info > r->Info)
    {
        return insertTree(r->Right, x);
    }
    else
    {
        return insertTree(r->Left, x);
    }
    return 1;
}
//--------------------------------------------------------------------------------------------------------
//---------------------------------------------------SHOW-----------------------------------------------
void ShowBST(BSTNode *root)
{
    printf("%4d ", root->Info);
}
void traverseLNR(BSTNode *root)
{
    if (root == NULL)
        return;
    traverseLNR(root->Left);
    ShowBST(root);
    traverseLNR(root->Right);
}
void traverseRNL(BSTNode *root)
{
    if (root == NULL)
        return;
    traverseRNL(root->Right);
    ShowBST(root);
    traverseRNL(root->Left);
}
void traverseNRL(BSTNode *root)
{
    if (root == NULL)
        return;
    ShowBST(root);
    traverseNRL(root->Right);
    traverseNRL(root->Left);
}

void traverseNLR(BSTNode *root)
{
    if (root == NULL)
        return;
    ShowBST(root);
    traverseNLR(root->Left);
    traverseNLR(root->Right);
}
void traverseLRN(BSTNode *root)
{
    if (root == NULL)
        return;
    traverseLRN(root->Left);
    traverseLRN(root->Right);
    ShowBST(root);
}
void traverseRLN(BSTNode *root)
{
    if (root == NULL)
        return;
    traverseRLN(root->Right);
    traverseRLN(root->Left);
    ShowBST(root);
}
//-------------------------------------------------------------------------------------------------------

// 1. Đếm số nút trong cây
int countNode(BSTNode *root)
{
    if (root == NULL)
        return 0;
    return 1 + countNode(root->Left) + countNode(root->Right);
}
// 2. Tính chiều cao của cây
int heightNode(BSTNode *root)
{
    if (root == NULL)
        return 0;
    int leftHeight = heightNode(root->Left);
    int rightHeight = heightNode(root->Right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}
// 3. Tìm nút có giá trị lớn nhất, nhỏ nhất của cây.
int MAX(BSTNode *root)
{
    if (root == NULL)
        return INT_MIN;
    int maxLeft = MAX(root->Left);
    int maxRight = MAX(root->Right);
    int max = root->Info;
    if (maxLeft > max)
        max = maxLeft;
    if (maxRight > max)
        max = maxRight;
    return max;
}

int MIN(BSTNode *root)
{
    if (root == NULL)
        return INT_MAX;
    int minLeft = MIN(root->Left);
    int minRight = MIN(root->Right);
    int min = root->Info;
    if (minLeft < min)
        min = minLeft;
    if (minRight < min)
        min = minRight;
    return min;
}
// 4. Tính tổng giá trị các nút của cây (dùng đệ quy / không dùng đệ quy).
int sumNodes(BSTNode *root)
{
    if (root == NULL)
        return 0;
    return root->Info + sumNodes(root->Left) + sumNodes(root->Right);
}
// 5. Tính tổng giá trị các nút dương, giá trị các nút âm trên cây
int sumPositiveNodes(BSTNode *root)
{
    int sum = 0;
    if (root == NULL)
        return 0;
    if (root->Info > 0)
        sum = root->Info;
    return sum + sumPositiveNodes(root->Left) + sumPositiveNodes(root->Right);
}

int sumNegativeNodes(BSTNode *root)
{
    int sum = 0;
    if (root == NULL)
        return 0;
    if (root->Info < 0)
        sum = root->Info;
    return sum + sumNegativeNodes(root->Left) + sumNegativeNodes(root->Right);
}
// 6. Tính tổng giá trị các nút là số nguyên tố
int snt(int n)
{
    if (n < 2)
        return 0;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return 0;
    return 1;
}
int sumPrimeNodes(BSTNode *root)
{
    int sum = 0;
    if (root == NULL)
        return 0;
    if (snt(root->Info))
        sum = root->Info;
    return sum + sumPrimeNodes(root->Left) + sumPrimeNodes(root->Right);
}
// 8. Đếm số lượng nút lá của cây
int countLeaf(BSTNode *root)
{
    if (root == NULL)
        return 0;
    if (root->Left == NULL && root->Right == NULL)
        return 1;
    return countLeaf(root->Left) + countLeaf(root->Right);
}
// 10.Đếm số nút không phải là nút lá
int countNonLeaf(BSTNode *root)
{
    if (root == NULL)
        return 0;
    if (root->Left == NULL && root->Right == NULL)
        return 0;
    return 1 + countNonLeaf(root->Left) + countNonLeaf(root->Right);
}
// 12.Đếm số nút chỉ có đúng 1 nút con.
int count1Child(BSTNode *root)
{
    if (root == NULL)
        return 0;
    if ((root->Left == NULL && root->Right != NULL) ||
        (root->Left != NULL && root->Right == NULL))
    {
        return 1;
    }
    return count1Child(root->Left) + count1Child(root->Right);
}
// 13.Đếm số nút có đủ cả 2 nút con
int count2Children(BSTNode *root)
{
    if (root == NULL)
        return 0;
    if ((root->Left == NULL && root->Right == NULL) ||
        (root->Left == NULL && root->Right != NULL) ||
        (root->Left != NULL && root->Right == NULL))
    {
        return 0;
    }
    return 1 + count2Children(root->Left) + count2Children(root->Right);
}
// 14.Tìm phần tử có khoảng cách về giá trị gần nhất với phần tử x trong cây (nếu cây rỗng trả về -1).
int findClosetX(BSTNode *root, Itemtype x)
{
    if (root == NULL)
        return -1;
    int closet = root->Info;
    BSTNode *tmp = root;
    while (root != NULL)
    {
        if (abs(tmp->Info - x) < abs(closet - x))
        {
            closet = tmp->Info;
        }
        if (root->Info > x)
        {
            root = root->Left;
        }
        else if (root->Info < x)
        {
            root = root->Right;
        }
        else
        {
            return root->Info;
        }
    }
    return closet;
}
// 15.Tìm phần tử có khoảng cách về giá trị xa nhất với phần tử x trong cây (nếu cây rỗng trả về -1).
int findFarthestX(BSTNode *root, Itemtype x)
{
    if (root == NULL)
        return -1;
    int farthest = root->Info;
    BSTNode *tmp = root;
    while (root != NULL)
    {
        if (abs(tmp->Info - x) > abs(farthest - x))
        {
            farthest = tmp->Info;
        }
        if (root->Info > x)
        {
            root = root->Left;
        }
        else if (root->Info < x)
        {
            root = root->Right;
        }
        else
        {
            return root->Info;
        }
    }
    return farthest;
}
// 16.Xuất ra nội dung các nút ở mức k (k ≥ 0).
void inMucK(BSTNode *root, int k)
{
    if (root == NULL)
        return;
    if (k == 0)
    {
        printf("%4d ", root->Info);
        return;
    }
    inMucK(root->Left, k - 1);
    inMucK(root->Right, k - 1);
}
// 17.Xuất ra nội dung các nút lá ở mức k (k ≥ 0).
void inMucLaK(BSTNode *root, int k)
{
    if (root == NULL)
        return;
    if (k == 0 && root->Left == NULL && root->Right == NULL)
    {
        printf("%4d ", root->Info);
        return;
    }
    inMucLaK(root->Left, k - 1);
    inMucLaK(root->Right, k - 1);
}
// 18.Đếm số nút ở mức k (k ≥ 0).
int demMucK(BSTNode *root, int k)
{
    if (root == NULL)
        return 0;
    if (k == 0)
    {
        return 1;
    }
    return demMucK(root->Left, k - 1) + demMucK(root->Right, k - 1);
}
// 19.Đếm số nút lá ở mức k (k ≥ 0).
int demMucLaK(BSTNode *root, int k)
{
    if (root == NULL)
        return 0;
    if (k == 0 && root->Left == NULL && root->Right == NULL)
    {
        return 1;
    }
    return demMucLaK(root->Left, k - 1) + demMucLaK(root->Right, k - 1);
}
// 20.Tính tổng giá trị các nút tại mức thứ k (k ≥ 0).
// 21.Đếm số nút nằm tại mức thứ k (k ≥ 0)
// 22.Tính tổng giá trị các nút lá nằm tại mức thứ k (k ≥ 0).
// 23.Đếm số nút lá nằm tại mức thứ k (k ≥ 0).
// 24.Đếm số giá trị lớn hơn x, nhỏ hơn x, có giá trị trong đoạn [x, y].
// 25.Tìm và trả về giá trị khóa Lớn nhất (Max/Min) trong cây.
int findMax(BSTNode *root)
{
    if (root == NULL)
        return -1;
    while (root->Right != NULL)
    {
        root = root->Right;
    }
    return root->Info;
}
int findMin(BSTNode *root)
{
    if (root == NULL)
        return -1;
    while (root->Left != NULL)
    {
        root = root->Left;
    }
    return root->Info;
}
// 26.In các khóa của cây theo thứ tự LNR (Trung tự) để thu được mảng tăng dần.
// 27.Tính tổng các nút có giá trị là số chẵn trên cây.
int chanNutCay(BSTNode *root)
{
    if (root == NULL)
        return 0;
    if (root->Info % 2 == 0)
        return root->Info + chanNutCay(root->Left) + chanNutCay(root->Right);
    return chanNutCay(root->Left) + chanNutCay(root->Right);
}
// 28.Tính tổng các nút lá có giá trị là số lẻ.
int leNutCay(BSTNode *root)
{
    if (root == NULL)
        return 0;
    if (root->Info % 2 != 0)
        return root->Info + leNutCay(root->Left) + leNutCay(root->Right);
    return leNutCay(root->Left) + leNutCay(root->Right);
}
// 29.Đếm số nút có đúng 2 nút con, số nút chỉ có 1 nút con, số nút có con là nút lá của cây.

// 30.Tìm kiếm xem một nút có khóa X có tồn tại trong cây không (Trả về 1/0).
int findNodeX(BSTNode *root, int x)
{
    if (root == NULL)
        return 0;
    if (root->Info == x)
        return 1;
    if (x < root->Info)
        return findNodeX(root->Left, x);
    else
        return findNodeX(root->Right, x);
}
// 31.In ra màn hình tất cả các nút có giá trị lớn hơn X.
void inLonHonX(BSTNode *root, int x)
{
    if (root == NULL)
        return;
    if (root->Info > x)
    {
        printf("%d ", root->Info);
    }
    inLonHonX(root->Left, x);
    inLonHonX(root->Right, x);
}
// 32.Đếm số lượng nút có giá trị là số nguyên tố trên cây.
int demSNTNode(BSTNode *root)
{
    if (root == NULL)
        return 0;
    if (snt(root->Info))
        return 1 + demSNTNode(root->Left) + demSNTNode(root->Right);
    return demSNTNode(root->Left) + demSNTNode(root->Right);
}
// 33.Tính trung bình cộng của tất cả các nút có trên cây (Kết hợp hàm đếm và hàm tổng)
float tbc(BSTNode *root)
{
    if (root == NULL)
        return 0;
    int sum = sumNodes(root);
    int count = countNode(root);
    if (count == 0)
        return 0;
    return sum*1.0 / count;
}
int main()
{
    BSTNode *root = NULL;
    BTree bt;
    initBST(bt);

    insertTree(root, createNode(50));
    insertTree(root, createNode(30));
    insertTree(root, createNode(70));
    insertTree(root, createNode(20));
    insertTree(root, createNode(60));
    insertTree(root, createNode(80));
    insertTree(root, createNode(65));
    insertTree(root, createNode(45));
    insertTree(root, createNode(3));
    insertTree(root, createNode(2));

    printf("\nLNR: ");
    traverseLNR(root);
    printf("\nRNL: ");
    traverseRNL(root);
    printf("\nNRL: ");
    traverseNRL(root);
    printf("\nNLR: ");
    traverseNLR(root);
    printf("\nLRN: ");
    traverseLRN(root);
    printf("\nRLN: ");
    traverseRLN(root);
    // 1
    printf("\nCau 1");
    printf("\nSo nut trong cay: %d", countNode(root));
    // 2
    printf("\nCau 2");
    printf("\nChieu cao cua cay: %d", heightNode(root));
    // 3
    printf("\nCau 3");
    printf("\nGia tri lon nhat: %d", MAX(root));
    printf("\nGia tri nho nhat: %d", MIN(root));
    // 4
    printf("\nCau 4");
    printf("\nTong gia tri cac nut: %d", sumNodes(root));
    // 5
    printf("\nCau 5");
    printf("\nTong gia tri cac nut duong: %d", sumPositiveNodes(root));
    printf("\nTong gia tri cac nut am: %d", sumNegativeNodes(root));
    // 6
    printf("\nCau 6");
    printf("\nTong gia tri cac nut la so nguyen to: %d", sumPrimeNodes(root));
    // 8
    printf("\nCau 8");
    printf("\nSo luong nut la: %d", countLeaf(root));
    // 10
    printf("\nCau 10");
    printf("\nSo luong nut khong phai la nut la: %d", countNonLeaf(root));
    // 12
    printf("\nCau 12");
    printf("\nSo luong nut chi co dung 1 nut con: %d", count1Child(root));
    // 13
    printf("\nCau 13");
    printf("\nSo luong nut co du ca 2 nut con: %d", count2Children(root));
    // 14
    printf("\nCau 14");
    printf("\nPhan tu gan nhat voi 35: %d", findClosetX(root, 40));
    // 15
    printf("\nCau 15");
    printf("\nPhan tu xa nhat voi 35: %d", findFarthestX(root, 40));
    // 16
    printf("\nCau 16");
    printf("\nDanh sach muc k = 2: ");
    inMucK(root, 2);
    // 17
    printf("\nCau 16");
    printf("\nDanh sach muc la k = 3: ");
    inMucLaK(root, 3);
    // 18
    printf("\nCau 18");
    printf("\nSo luong nut muc k: %d", demMucK(root, 2));
    // 19
    printf("\nCau 19");
    printf("\nSo luong nut la k: %d", demMucLaK(root, 3));
    // 25
    printf("\nCau 25");
    printf("\nGia tri lon nhat trong cay: %d", findMax(root));
    printf("\nGia tri nho nhat trong cay: %d", findMin(root));
    // 27
    printf("\nCau 27");
    printf("\nTong gia tri cac nut chan: %d", chanNutCay(root));
    // 28
    printf("\nCau 28");
    printf("\nTong gia tri cac nut le: %d", leNutCay(root));
    // 30
    printf("\nCau 30");
    if (findNodeX(root, 35) == 1)
        printf("\nCo ton tai nut co gia tri 35");
    else
        printf("\nKhong ton tai nut co gia tri 35");
    // 31
    printf("\nCau 31");
    printf("\nCac nut lon hon 35: ");
    inLonHonX(root, 35);
    // 32
    printf("\nCau 32");
    printf("\nSo luong nut la so nguyen to: %d", demSNTNode(root));
    // 33
    printf("\nCau 33");
    printf("\nTrung binh cong gia tri cac nut: %.2f", tbc(root));
    return 0;
}
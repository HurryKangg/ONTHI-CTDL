#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
// 3. Lưu trữ tọa độ đỉnh đa giác 2D (x, y) trên DHeadK và viết hàm tính chu vi đa giác
typedef int Itemtype;
struct Point
{
    float x, y;
    Point *Next;
};
Point *createPoint(float x, float y)
{
    Point *p = new Point();
    p->x = x;
    p->y = y;
    p->Next = NULL;
    return p;
}
Point *insertTail(Point *Head, float x, float y)
{
    Point *p = createPoint(x, y);
    if (Head == NULL)
    {
        Head = p;
    }
    else
    {
        Point *cur = Head;
        while (cur->Next)
            cur = cur->Next;
        cur->Next = p;
    }
    return Head;
}
float dist(Point *a, Point *b)
{
    return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));
}
float chuViDaGiac(Point *point)
{
    float sum = 0;
    Point *p = point;
    while (p->Next != NULL)
    {
        sum += dist(p, p->Next);
        p = p->Next;
    }
    sum += dist(p, point);
    return sum;
}
int main()
{
    Point *p = NULL;

    p = insertTail(p, 0, 0);
    p = insertTail(p, 0, 3);
    p = insertTail(p, 4, 3);
    p = insertTail(p, 4, 0);
    printf("Chu vi da giac: %f", chuViDaGiac(p));

    getch();
}
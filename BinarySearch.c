/*
本题要求实现二分查找算法。

函数接口定义：
Position BinarySearch( List L, ElementType X );
其中List结构定义如下：

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; // 保存线性表中最后一个元素的位置 
};
L是用户传入的一个线性表，其中ElementType元素可以通过>、==、<进行比较，并且题目保证传入的数据是递增有序的。
函数BinarySearch要查找X在Data中的位置，即数组下标（注意：元素从下标1开始存储）。找到则返回下标，否则返回一个特殊的失败标记NotFound。

裁判测试程序样例：
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; // 保存线性表中最后一个元素的位置 
};

List ReadInput(); // 裁判实现，细节不表。元素从下标1开始存储 
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}

// 你的代码将被嵌在这里 
输入样例1：
5
12 31 55 89 101
31
输出样例1：
2
输入样例2：
3
26 78 233
31
输出样例2：
0
*/
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode
{
    ElementType Data[MAXSIZE];
    Position Last; // 保存线性表中最后一个元素的位置
};

List ReadInput() // 裁判实现，细节不表。元素从下标1开始存储
{
    List list = (List)malloc(sizeof(struct LNode));
    list->Data[1] = 26;
    list->Data[2] = 78;
    list->Data[3] = 223;
    list->Data[4] = 229;
    list->Data[5] = 230;
    list->Last = 5;
    return list;
}

Position _BinarySearch(List L, ElementType X, Position start)
{
    // start: 起始位置
    Position mid;
    mid = (start + L->Last) / 2;
    if (start >= L->Last && L->Data[mid] != X)
        return NotFound;
    if (L->Data[mid] == X)
        return mid;
    else if (L->Data[mid] > X)
    {
        L->Last = mid-1;
        return _BinarySearch(L, X, start);
    }
    else
    {
        return _BinarySearch(L, X, mid+1);
    }
}

Position BinarySearch(List L, ElementType X)
{
    return _BinarySearch(L, X, 1);
}

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    // scanf("%d", &X);
    X = 78;
    P = BinarySearch(L, X);
    printf("%d\n", P);

    return 0;
}
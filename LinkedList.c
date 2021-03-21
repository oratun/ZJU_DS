#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct LNode *PtrToLNode;
struct LNode
{
    int Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

#define ERROR NULL

Position Find(List L, int X)
{
    Position p = L;
    while (p && p->Data != X)
    {
        p = p->Next;
    }
    if (p)
    {
        return p;
    }
    return ERROR;
}

/* 带头结点的插入 在P之前插入新结点 */
bool Insert(List L, int X, Position P)
{
    Position pre, tmp;
    for (pre = L; pre && pre->Next != P; pre = pre->Next)
        ;

    if (pre)
    {
        tmp = (Position)malloc(sizeof(struct LNode));
        tmp->Data = X;
        tmp->Next = P;
        pre->Next = tmp;
        return true;
    }
    return false;
}
/* 带头节点带删除 P是拟删除结点指针 */
bool Delete(List L, Position P)
{
    Position pre;
    for (pre = L; pre && pre->Next != P; pre = pre->Next)
        ;
    if (pre && P != NULL)
    {
        pre->Next = P->Next;
        free(P);
        return true;
    }
    return false;
}

int main()
{
    printf("NULL=%s\n", NULL);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node
{
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode List;

List Read(int no);

void Print(List L);

// L1 L2带头节点，返回带头节点的L
List Merge(List L1, List L2)
{
    PtrToNode L3 = (PtrToNode)malloc(sizeof(struct Node));
    PtrToNode L = L3, p = L1->Next, q = L2->Next;

    while (p && q)
    {
        if (p->Data < q->Data)
        {
            L->Next = p;
            p = p->Next;
        }
        else
        {
            L->Next = q;
            q = q->Next;
        }
        L = L->Next;
    }
    if (p)
        L->Next = p;
    if (q)
        L->Next = q;
    L1->Next = NULL;
    L2->Next = NULL;
    return L3;
}

int main()
{
    List L1, L2, L;
    L1 = Read(1);
    L2 = Read(2);
    // Print(L1);
    // Print(L2);
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}
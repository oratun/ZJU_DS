#include <stdio.h>
#include <stdlib.h>

typedef int ElelmentType;
typedef struct Node *PtrToNode;
struct Node
{
    ElelmentType Data;
    struct Node *PtrToNode;
};
typedef PtrToNode List;

#define ERROR NULL

int main()
{
    return 0;
}

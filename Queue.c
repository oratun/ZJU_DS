// 队列-链表实现
// Created by Ora tun on 2021/3/20.
//

#include<stdlib.h>
#include "stdio.h"
#include "stdbool.h"

typedef int ElementType;
typedef struct QNode *PtrToNode;
typedef struct QNode {
    struct TNode *data;
    PtrToNode next;
};

PtrToNode Q = NULL;

PtrToNode create() {
    Q = (PtrToNode) malloc(sizeof(struct QNode));
    Q->data = -1;
    Q->next = NULL;
    return Q;
}

bool add(ElementType val) {
    if (!Q)return false;
    PtrToNode tmp = Q;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = (PtrToNode) malloc(sizeof(struct QNode));
    tmp->next->next = NULL;
    tmp->next->data = val;
    return true;
}

bool isEmpty() {
    if (Q->next)return true;
    return false;
}

ElementType pop() {
    ElementType tmp = Q->next->data;
    Q->next = Q->next->next;
    free(tmp);
    return tmp;
}

int main() {
    return 0;
}
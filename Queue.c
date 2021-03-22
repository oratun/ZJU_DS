// 队列-链表实现
// Created by Ora tun on 2021/3/20.
//

#include<stdlib.h>
#include "stdio.h"
#include "stdbool.h"

typedef int ElementType;
struct QNode {
    ElementType item;
    struct QNode *next;
};
typedef struct QNode *Position;

Position Create() {
    Position q;
    q = (Position) malloc(sizeof(struct QNode));
    q->item = 0;
    q->next = NULL;
    return q;
}

bool Add(Position q, ElementType val) {
    if (!q) q = Create();
    Position tmp = q;
    while (tmp->next)
        tmp = tmp->next;
    Position node = (Position) malloc(sizeof(struct QNode));
    node->item = val;
    node->next = NULL;
    tmp->next = node;
    return true;
}

bool IsEmpty(Position q) {
    return q->next == NULL;
}

int Pop(Position q) {
    Position p = q->next;
    ElementType tmp = p->item;
    q->next = p->next;
    free(p);
    return tmp;
}
//int main() {
//    return 0;
//}
/*
 * Given a tree, you are supposed to list all the leaves in the order of top down, and left to right.

Input Specification:
Each input file contains one test case. For each case,
 the first line gives a positive integer N (≤10) which is the total number of nodes in the tree --
 and hence the nodes are numbered from 0 to N−1. Then N lines follow, each corresponds to a node,
 and gives the indices of the left and right children of the node. If the child does not exist,
 a "-" will be put at the position. Any pair of children are separated by a space.

Output Specification:
For each test case, print in one line all the leaves' indices in the order of top down, and left to right.
 There must be exactly one space between any adjacent numbers, and no extra space at the end of the line.
给出一棵树，按上->下,左->右的顺序列出所有的叶子，
 测试输入的第一行给出节点总数正整数N(不大于10),其余N行每行代表一个节点，给出的是节点的左右子节点的索引。
 如果子节点不存在，用-表示

Sample Input:
8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6
Sample Output:
4 1 5
 */
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

struct TNode {
    int data;
    int left;
    int right;
} T[10];
// 链表队列
//typedef int ElementType;
struct QNode {
    int item;
    struct QNode *next;
};
typedef struct QNode *PtrToNode;

PtrToNode Create() {
    PtrToNode q;
    q = (PtrToNode) malloc(sizeof(struct QNode));
    q->item = 0;
    q->next = NULL;
    return q;
}

bool Add(PtrToNode q, int val) {
    if (!q) q = Create();
    PtrToNode tmp = q;
    while (tmp->next)
        tmp = tmp->next;
    PtrToNode node = (PtrToNode) malloc(sizeof(struct QNode));
    node->item = val;
    node->next = NULL;
    tmp->next = node;
    return true;
}

bool IsEmpty(PtrToNode q) {
    return q->next == NULL;
}

int Pop(PtrToNode q) {
    PtrToNode p = q->next;
    int tmp = p->item;
    q->next = p->next;
    free(p);
    return tmp;
}

/* 错误
 int Pop(PtrToNode q) {
    int tmp = q->next->item;
    q->next = q->next->next;
    free(q->next);
    return tmp;
*/

int BuildTree() {
    int N;
    scanf("%d\n", &N);
    int check[N];
    for (int m = 0; m < N; m++)check[m] = 0;
    for (int j = 0; j < N; j++) {
        char left, right;
        scanf("%c %c", &left, &right);
        getchar();
        T[j].data = j;
        if (left == '-') T[j].left = -1;
        else {
            T[j].left = left - '0';
            check[T[j].left] = 1; //标记出所有子节点，剩下的则为根节点
        }
        if (right == '-')T[j].right = -1;
        else {
            T[j].right = right - '0';
            check[T[j].right] = 1;
        }

    }
    for (int i = 0; i < N; i++) {
        if (check[i] == 0)return i; //根节点
    }
    return -1;
}

void LevelOrderTraversal(int root) {
    PtrToNode q = Create();
    Add(q, T[root].data);
    while (!IsEmpty(q)) {
        int tmp = Pop(q);
        if (T[tmp].left == -1 && T[tmp].right == -1) {
            printf("%d", T[tmp].data);
            if (!IsEmpty(q))
                printf(" ");
        }
        if (T[tmp].left != -1)
            Add(q, T[tmp].left);
        if (T[tmp].right != -1)
            Add(q, T[tmp].right);
    }
}

int main() {
    int root;
    root = BuildTree();
    LevelOrderTraversal(root);
    return 0;
}
/*
 * 03-树3 Tree Traversals Again (25 分)
An inorder binary tree traversal can be implemented in a non-recursive way with a stack.
 For example, suppose that when a 6-node binary tree (with the keys numbered from 1 to 6) is traversed,
 the stack operations are: push(1); push(2); push(3); pop(); pop(); push(4); pop(); pop(); push(5); push(6); pop(); pop().
 Then a unique binary tree (shown in Figure 1) can be generated from this sequence of operations.
 Your task is to give the postorder traversal sequence of this tree.


Figure 1
Input Specification:
Each input file contains one test case. For each case,
 the first line contains a positive integer N (≤30) which is the total number of nodes in a tree (and hence the nodes are numbered from 1 to N).
 Then 2N lines follow, each describes a stack operation in the format: "Push X" where X is the index of the node being pushed onto the stack;
 or "Pop" meaning to pop one node from the stack.

Output Specification:
For each test case, print the postorder traversal sequence of the corresponding tree in one line. A solution is guaranteed to exist.
 All the numbers must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:
6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop
Sample Output:
3 4 2 6 5 1
 */
#include<stdio.h>
#include<stdlib.h>
#include "Stack.c"

//typedef int ElementType;

struct TNode {
    ElementType data;
    int left;
    int right;
};
typedef struct TNode *PtrToNode;
PtrToNode T[31];

PtrToNode BuildTree() {
    int N, val, tag, idx;
    char s[4];
    PtrToNode current = NULL, p, tmp, root;
    Stk q = Create();
    scanf("%d", &N);
    for (int i = 0; i < 2 * N; i++) {
        scanf("%s", s);
        // push
        if (s[1] == 'u') {
            scanf("%d", &val);
            Push(q, val);
            tmp = (PtrToNode) malloc(sizeof(struct TNode));
            tmp->data = val;
            tmp->left = -1;
            tmp->right = -1;
            T[val] = tmp;
            if (i == 0)
                root = tmp;
            if (current) {
                if (tag == 0)
                    current->left = val;
                else
                    current->right = val;
            }
            current = tmp;
            tag = 0;
        } else { //pop
            idx = Pop(q);
            current = T[idx];
            tag = 1;
        }

    }
    return root;
}

void PostTraversal(PtrToNode root, int mark) {
    if (root) {
        if (root->left != -1)
            PostTraversal(T[root->left], 1);
        if (root->right != -1)
            PostTraversal(T[root->right], 1);
        printf("%d", root->data);
        if (mark)
            printf(" ");
    }
}

int main() {
    PtrToNode p = BuildTree();
    PostTraversal(p, 0);
    return 0;
}
/*
Given a constant K and a singly nexted list L, you are supposed to reverse the nexts of every K elements on L. F
 or example, given L being 1→2→3→4→5→6, if K=3, then you must output 3→2→1→6→5→4; if K=4, you must output 4→3→2→1→5→6.

Input Specification:
Each input file contains one test case. For each case, the first line contains the address of the first node,
 a positive N (≤10**5) which is the total number of nodes, and a positive K (≤N) which is the length of the sublist to be reversed.
 The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Data Next
where Address is the position of the node, Data is an integer, and Next is the position of the next node.

Output Specification:
For each case, output the resulting ordered nexted list. Each node occupies a line, and is printed in the same format as in the input.

Sample Input:
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

Sample Output:
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
struct Node {
    int data;
    int next;
};

void printList(PtrToNode List[], int address) {
    PtrToNode node = List[address];
    while (1) {
        if (node->next != -1)
            printf("%05d %0d %05d\n", address, node->data, node->next);
        else
            printf("%05d %0d %d", address, node->data, -1);

        address = node->next;
        if (address == -1) break;
        node = List[address];
    }
}

PtrToNode reverse(PtrToNode List[], int address, int k) {
    PtrToNode p;
    PtrToNode node;
    int tmp = address;
    if (!address)return NULL;

    PtrToNode prev = List[address];
    address = prev->next;
    while (--k) {
        node = List[address];
        tmp = node->next;
        node->next = address;
        address = tmp;
    }

    return p;
}

int main() {
    int head, address, N, k;
    scanf("%d %d %d", &head, &N, &k);
    int MAX = 10 * 10000;
    PtrToNode List[MAX];
    while (--MAX)
        List[MAX] = NULL;
    while (N--) {
        PtrToNode node = (PtrToNode) malloc(sizeof(struct Node));
        scanf("%d %d %d", &address, &node->data, &node->next);
        List[address] = node;
    }
    printList(List, head);
    return 0;
}
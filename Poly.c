/*
设计函数分别求两个一元多项式的乘积与和。

输入格式:
输入分2行，每行分别先给出多项式非零项的个数，再以指数递降方式输入一个多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。

输出格式:
输出分2行，分别以指数递降方式输出乘积多项式以及和多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。零多项式应输出0 0。

输入样例:
4  3 4  -5 2  6 1  -2 0
3  5 20  -7 4  3 1
输出样例:
15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
5 20 -4 4 -5 2 9 1 -2 0

4 2 1 0
3 -5 6 -2
*/
#include <stdio.h>
#include <stdlib.h>

typedef int ElelmentType;
typedef struct Node *PtrToNode;
struct Node {
    ElelmentType coef; // 系数
    ElelmentType exp;  // 指数
    PtrToNode link;
};

void Attach(int coef, int exp, PtrToNode *pRear) {
//    if ((*pRear)->exp == exp) { (*pRear)->coef += coef; }
//    else {
        PtrToNode item = (PtrToNode) malloc(sizeof(struct Node));
        item->coef = coef;
        item->exp = exp;
        item->link = NULL;
        if ((*pRear) == NULL)*pRear = item;
        else (*pRear)->link = item;
        *pRear = (*pRear)->link;
//    }
}

PtrToNode Read() {
    int k;
    ElelmentType coef, exp;
    PtrToNode head, pRear, tmp;
    head = (PtrToNode) malloc(sizeof(struct Node));
    head->link = NULL;
    pRear = head;
    scanf("%d", &k);
    for (int i = k; i > 0; i--) {
        scanf("%d %d", &coef, &exp);
        Attach(coef, exp, &pRear);
    }
    tmp = head->link;
    free(head);
    return tmp;
}

void PrintList(PtrToNode List) {
    while (List) {
        printf("%d %d", List->coef, List->exp);
        if (List->link)printf(" ");
        List = List->link;
    }
}

PtrToNode PolySum(PtrToNode p1, PtrToNode p2) {
    PtrToNode head, p;

    head = (PtrToNode) malloc(sizeof(struct Node));
    head->link = NULL;
    p = head;

    while (p1 && p2) {
        if (p1->exp > p2->exp) {
            Attach(p1->coef, p1->exp, &p);
            p1 = p1->link;
        } else if (p1->exp < p2->exp) {
            Attach(p2->coef, p2->exp, &p);
            p2 = p2->link;
        } else {
            if (p1->coef + p2->coef != 0) {
                Attach(p1->coef + p2->coef, p1->exp, &p);
            } else if (p1->coef == 0 || p2->coef == 0) {
                Attach(0, 0, &p);
            }
            p1 = p1->link;
            p2 = p2->link;
        }
    }
    while (p1) {
        Attach(p1->coef, p1->exp, &p);
        p1 = p1->link;
    };
    while (p2) {
        Attach(p2->coef, p2->exp, &p);
        p2 = p2->link;
    }
    p = head->link;
    free(head);
    return p;
}

PtrToNode PolyMulti(PtrToNode p1, PtrToNode p2) {
    PtrToNode head, q;
//    head = (PtrToNode) malloc(sizeof(struct Node));
//    head->link = NULL;
    head = NULL;
    while (p1) {
        q = p2;
        while (q) {
            PtrToNode node = (PtrToNode) malloc(sizeof(struct Node));
            node->coef = p1->coef * q->coef;
//            if (node->coef == 0) {
//                node->exp = 0;
//            } else {
                node->exp = p1->exp + q->exp;
//            }
            node->link = NULL;
            head = PolySum(head, node);
            q = q->link;
        }
        p1 = p1->link;
    }
    return head;
}

int main() {
    PtrToNode p1, p2, pSum;
    p1 = Read();
//     PrintList(p1);
    p2 = Read();
//     PrintList(p2);
    PtrToNode pMul = PolyMulti(p1, p2);
    PrintList(pMul);
    printf("\n");
    pSum = PolySum(p1, p2);
    PrintList(pSum);
    return 0;
}
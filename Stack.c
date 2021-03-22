// 堆栈
#include <stdlib.h>
#include <stdbool.h>

typedef int ElementType;
#define MAX_SIZE 30
struct Stack {
    int top;
    ElementType data[MAX_SIZE];
};

typedef struct Stack *Stk;

Stk Create() {
    Stk s = (Stk) malloc(sizeof(struct Stack));
    s->top = -1;
    return s;
}

bool IsEmpty(Stk s) {
    return s->top == -1;
}

ElementType Pop(Stk s) {
    if (!s || s->top == -1)
        return -1;
    return s->data[s->top--];
}

bool Push(Stk s, ElementType val) {
    if (!s || s->top == MAX_SIZE-1)
        return false;
    s->data[++s->top] = val;
    return true;
}
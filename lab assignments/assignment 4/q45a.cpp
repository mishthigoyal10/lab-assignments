#include <stdio.h>
#define MAX 100

int q1[MAX], q2[MAX], f1 = 0, r1 = -1, f2 = 0, r2 = -1;

void enqueue1(int x) { q1[++r1] = x; }
int dequeue1() { return q1[f1++]; }
int isEmpty1() { return f1 > r1; }

void enqueue2(int x) { q2[++r2] = x; }
int dequeue2() { return q2[f2++]; }
int isEmpty2() { return f2 > r2; }

void push(int x) {
    enqueue2(x);
    while (!isEmpty1())
        enqueue2(dequeue1());
    while (!isEmpty2())
        enqueue1(dequeue2());
}

int pop() {
    if (isEmpty1()) return -1;
    return dequeue1();
}

int main() {
    push(10);
    push(20);
    push(30);
    printf("Popped: %d\n", pop());
    printf("Popped: %d\n", pop());
    return 0;
}

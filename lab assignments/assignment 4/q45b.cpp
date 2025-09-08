#include <stdio.h>
#define MAX 100

int q[MAX], front = 0, rear = -1, size = 0;

void enqueue(int x) { q[++rear] = x; size++; }
int dequeue() { size--; return q[front++]; }

void push(int x) {
    enqueue(x);
    for (int i = 0; i < size - 1; i++)
        enqueue(dequeue());
}

int pop() {
    if (size == 0) return -1;
    return dequeue();
}

int main() {
    push(5);
    push(10);
    push(15);
    printf("Popped: %d\n", pop());
    printf("Popped: %d\n", pop());
    return 0;
}

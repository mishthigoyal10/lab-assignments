#include <stdio.h>
#include <limits.h>

#define MAX 100

int stack[MAX], top = -1;
int minEle;

void push(int x) {
    if(top == -1) {
        stack[++top] = x;
        minEle = x;
    } else if(x < minEle) {
        stack[++top] = 2*x - minEle; // store encoded value
        minEle = x;
    } else {
        stack[++top] = x;
    }
}

void pop() {
    if(top == -1) { printf("Stack Underflow\n"); return; }

    int t = stack[top--];
    if(t < minEle) {
        printf("Popped: %d\n", minEle);
        minEle = 2*minEle - t;
    } else
        printf("Popped: %d\n", t);
}

int peek() {
    int t = stack[top];
    if(t < minEle) return minEle;
    else return t;
}

int getMin() {
    if(top == -1) return INT_MAX;
    return minEle;
}

int main() {
    push(3); push(5); printf("Min: %d\n", getMin());
    push(2); push(1); printf("Min: %d\n", getMin());
    pop(); printf("Min: %d\n", getMin());
    pop(); printf("Min: %d\n", getMin());
    return 0;
}

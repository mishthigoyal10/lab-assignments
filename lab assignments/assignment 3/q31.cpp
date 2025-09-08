#include <stdio.h>
#define MAX 5

int stack[MAX], top = -1;

int isFull() {
    return top == MAX - 1;
}

int isEmpty() {
    return top == -1;
}

void push(int val) {
    if (isFull())
        printf("Stack Overflow!\n");
    else
        stack[++top] = val;
}

void pop() {
    if (isEmpty())
        printf("Stack Underflow!\n");
    else
        printf("Popped: %d\n", stack[top--]);
}

void peek() {
    if (isEmpty())
        printf("Stack is empty\n");
    else
        printf("Top element: %d\n", stack[top]);
}

void display() {
    int i;
    if (isEmpty())
        printf("Stack is empty\n");
    else {
        printf("Stack elements: ");
        for (i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main() {
    int choice, val;
    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            printf(isEmpty() ? "Stack is Empty\n" : "Stack is Not Empty\n");
            break;
        case 4:
            printf(isFull() ? "Stack is Full\n" : "Stack is Not Full\n");
            break;
        case 5:
            display();
            break;
        case 6:
            peek();
            break;
        case 7:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
}

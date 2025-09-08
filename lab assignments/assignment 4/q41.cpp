#include <stdio.h>
#define MAX 5

int queue[MAX], front = -1, rear = -1;

int isEmpty() { return front == -1; }
int isFull() { return (rear == MAX - 1); }

void enqueue(int val) {
    if (isFull())
        printf("Queue Overflow!\n");
    else {
        if (front == -1) front = 0;
        queue[++rear] = val;
    }
}

void dequeue() {
    if (isEmpty())
        printf("Queue Underflow!\n");
    else {
        printf("Dequeued: %d\n", queue[front]);
        if (front == rear)
            front = rear = -1;
        else
            front++;
    }
}

void peek() {
    if (isEmpty())
        printf("Queue is empty\n");
    else
        printf("Front element: %d\n", queue[front]);
}

void display() {
    int i;
    if (isEmpty())
        printf("Queue is empty\n");
    else {
        printf("Queue elements: ");
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice, val;
    while (1) {
        printf("\n--- MENU ---\n");
        printf("1.Enqueue 2.Dequeue 3.isEmpty 4.isFull 5.Display 6.Peek 7.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1: printf("Enter value: "); scanf("%d", &val); enqueue(val); break;
        case 2: dequeue(); break;
        case 3: printf(isEmpty() ? "Empty\n" : "Not Empty\n"); break;
        case 4: printf(isFull() ? "Full\n" : "Not Full\n"); break;
        case 5: display(); break;
        case 6: peek(); break;
        case 7: return 0;
        default: printf("Invalid choice\n");
        }
    }
}

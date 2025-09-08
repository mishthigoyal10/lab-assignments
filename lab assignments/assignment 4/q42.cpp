#include <stdio.h>
#define MAX 5

int cq[MAX], front = -1, rear = -1;

int isEmpty() { return front == -1; }
int isFull() { return (front == (rear + 1) % MAX); }

void enqueue(int val) {
    if (isFull())
        printf("Circular Queue Overflow!\n");
    else {
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX;
        cq[rear] = val;
    }
}

void dequeue() {
    if (isEmpty())
        printf("Circular Queue Underflow!\n");
    else {
        printf("Dequeued: %d\n", cq[front]);
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % MAX;
    }
}

void peek() {
    if (isEmpty())
        printf("Circular Queue is empty\n");
    else
        printf("Front element: %d\n", cq[front]);
}

void display() {
    int i;
    if (isEmpty())
        printf("Circular Queue is empty\n");
    else {
        printf("Circular Queue elements: ");
        i = front;
        while (1) {
            printf("%d ", cq[i]);
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

int main() {
    int choice, val;
    while (1) {
        printf("\n--- CIRCULAR QUEUE MENU ---\n");
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

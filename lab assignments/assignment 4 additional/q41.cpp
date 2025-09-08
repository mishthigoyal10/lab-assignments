#include <stdio.h>
#include <string.h>

#define MAX 1000

typedef struct {
    char arr[MAX][MAX];
    int front, rear;
} Queue;

void enqueue(Queue* q, char* s) {
    strcpy(q->arr[++q->rear], s);
}

char* dequeue(Queue* q) {
    return q->arr[++q->front];
}

void generateBinary(int n) {
    Queue q;
    q.front = -1; q.rear = -1;

    enqueue(&q, "1");

    for(int i = 0; i < n; i++) {
        char* s = dequeue(&q);
        printf("%s ", s);

        char s0[MAX], s1[MAX];
        strcpy(s0, s); strcat(s0, "0");
        strcpy(s1, s); strcat(s1, "1");

        enqueue(&q, s0);
        enqueue(&q, s1);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    generateBinary(n);
    return 0;
}
